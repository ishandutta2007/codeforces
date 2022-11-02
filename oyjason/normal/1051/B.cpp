#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define LL long long
using namespace std;
LL read(){
	LL nm=0,fh=1;char cw=getchar();
	for(;!isdigit(cw);cw=getchar()) if(cw=='-') fh=-fh;
	for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
	return nm*fh;
}
LL L,R;
int main(){
	L=read(),R=read();
	if(((R-L)&1)^1){puts("NO");return 0;}
	puts("YES");
	for(LL i=L+1;i<=R;i+=2) printf("%lld %lld\n",i,i-1); 
	return 0;
}