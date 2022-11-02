#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#define LL long long
#define M
using namespace std;
LL read(){
	LL nm=0,fh=1;char cw=getchar();
	for(;!isdigit(cw);cw=getchar()) if(cw=='-') fh=-fh;
	for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
	return nm*fh;
}
LL n,m;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	LL a=read(),b=read()-1,c=read()-2;
	printf("%lld\n",min(a,min(b,c))*3ll+3ll);
	return 0;
}