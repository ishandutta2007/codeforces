#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#define LL long long
#define M 1000020
#define mod 998244353
using namespace std;
LL read(){
	LL nm=0,fh=1;char cw=getchar();
	for(;!isdigit(cw);cw=getchar()) if(cw=='-') fh=-fh;
	for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
	return nm*fh;
}
LL n,m,fac[M],ifac[M],ans;
LL qpow(LL x,LL sq){
	LL res=1;
	for(;sq;sq>>=1,x=x*x%mod) if(sq&1) res=res*x%mod;
	return res;
}
LL C(LL tot,LL tk){
	return (fac[tot]*ifac[tk]%mod)*ifac[tot-tk]%mod;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read(),fac[0]=1;
	for(LL i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
	ifac[n]=qpow(fac[n],mod-2);
	for(LL i=n;i;i--) ifac[i-1]=ifac[i]*i%mod;
	ans=fac[n];
	for(LL i=1;i<=n;i++) ans+=(fac[n-i]-1+mod)*(fac[i]*C(n,i)%mod)%mod,ans%=mod;
	printf("%lld\n",(ans%mod+mod)%mod);
	return 0;
}