#include<stdio.h>
#include<string.h>
char in[110];
int main(){
    scanf("%s",in);
    if(strlen(in)>19)puts("BigInteger");
    else{
	long long x;
	sscanf(in,"%I64d",&x);
	if(x<0)puts("BigInteger");
	else if(x<=127)puts("byte");
	else if(x<=32767)puts("short");
	else if(x<=2147483647)puts("int");
	else puts("long");
    }
}