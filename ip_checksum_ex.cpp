#include<stdio.h>
#include<string.h>
#include<stdint.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<vector>
using namespace std;
int main(){
	int sum=0;
	uint16_t chksum = 0;
	unsigned char buf[20] = {0x45,0x00,0x00,0x48,0x5a,0xc0,0x00,0x00,0x80,0x11,0x00,0x00,0xc0,0xa8,0x03,0x96,0xc0,0xa8,
0x03,0xff};
 
	uint16_t buf2[10];

	memcpy(&buf2[0], &buf, 20);
	vector<char> packet;
	
	//printf("%x\n", static_cast<int>(buf2[0]));
	for(int i=0;i<10;i++){
		sum += static_cast<int>(buf2[i]);		
		printf("%02x\n", buf2[i]);
	}
	chksum = (sum>>16) + (sum & 0xffff);
    	chksum = (chksum^0xffff);
	uint16_t s1 = chksum<<8;
	uint16_t s2 = chksum>>8;
	printf("result : %x\n", ntohs(chksum));
	printf("$1 : %x\n", ntohs(s1));
	printf("$2 : %x\n", ntohs(s2));
	printf("$1 + $2 = %x\n", s1|s2);
	
	printf("%x %x\n", packet.at(0), packet.at(1));

}
