#include<bits/stdc++.h>

using namespace std;

#define LL long long

const LL mod=998244353;
LL n,ans,fac[1200000],ifac[1200000];

LL inv(LL x){return x==1?1:(mod-mod/x)*inv(mod%x)%mod;}

LL C(LL x,LL y){
	return x<y?0:fac[x]*ifac[y]%mod*ifac[x-y]%mod;
}

int main(){
	scanf("%lld",&n);
	fac[0]=1; for (LL i=1;i<=n;++i) fac[i]=fac[i-1]*i%mod;
	ifac[n]=inv(fac[n]); for (LL i=n-1;~i;--i) ifac[i]=ifac[i+1]*(i+1)%mod;
	ans=n*fac[n]%mod;
	for (LL i=1;i<=n;++i)
		(ans-=C(n,n-i)*fac[n-i])%=mod;
	ans=(ans%mod+1+mod)%mod;
	printf("%lld\n",ans);
	
	return 0;
}