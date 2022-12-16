#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MN 100
int n;
char s[MN+5];
bool o[MN+5][3];
int main(){
	memset(o,0,sizeof(o));
	scanf("%s",&s[1]); n=strlen(&s[1]);
	for(int i=1;i<=n;i++){
		if(s[i]=='A'){
			o[i-1][0]=true;
			o[i  ][0]=true;
			o[i+1][0]=true;
		}
		if(s[i]=='B'){
			o[i-1][1]=true;
			o[i  ][1]=true;
			o[i+1][1]=true;
		}
		if(s[i]=='C'){
			o[i-1][2]=true;
			o[i  ][2]=true;
			o[i+1][2]=true;
		}
	}
	for(int i=1;i<=n;i++)
		if(o[i][0]&&o[i][1]&&o[i][2])
			puts("Yes"),exit(0);
	puts("No");
}