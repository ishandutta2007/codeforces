#include<bits/stdc++.h>
#define LL long long
#define mod 998244353
using namespace std;
LL read(){
	LL nm=0,fh=1;char cw=getchar();
	for(;!isdigit(cw);cw=getchar()) if(cw=='-') fh=-fh;
	for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
	return nm*fh;
}
LL n,m,ans,K;
LL qpow(LL x,LL sq){
	LL res=1;
	while(sq){
		if(sq&1) res=res*x%mod;
		x=x*x%mod,sq>>=1;
	} return res;
}
LL C(LL x, LL y){
	LL now=1; 
	for(LL i=1;i<=y;i++){
		now*=qpow(i,mod-2),now%=mod;
		now*=x-i+1,now%=mod;
	} return now;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read(),m=read(),K=read();
	ans=C(n-1,K);
	ans*=m,ans%=mod;
	ans*=qpow(m-1,K),ans%=mod;
	printf("%lld\n",ans);
	return 0;
}