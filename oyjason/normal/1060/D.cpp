#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#define LL long long
#define M 1000020
using namespace std;
LL read(){
	LL nm=0,fh=1; char cw=getchar();
	for(;!isdigit(cw);cw=getchar()) if(cw=='-') fh=-fh;
	for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
	return nm*fh;
}
LL n,m,p[M],t[M],ans;
int main(){
	n=read();
	for(LL i=1;i<=n;i++) p[i]=read(),t[i]=read();
	sort(p+1,p+n+1),sort(t+1,t+n+1);
	for(LL i=1;i<=n;i++) ans+=max(p[i],t[i]);
	printf("%lld\n",ans+n);
	return 0;
}