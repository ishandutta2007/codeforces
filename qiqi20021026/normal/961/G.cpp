#include<bits/stdc++.h>

using namespace std;

#define LL long long
#define N 800000

const LL mod=1000000007;
LL n,m,x,ans,fac[N],ifac[N];

LL inv(LL x){return x==1?1:(mod-mod/x)*inv(mod%x)%mod;}

LL pw(LL x,LL k){
	if (k==0) return 1;
	if (x<0) x+=mod;
	LL tmp=pw(x*x%mod,k>>1);
	return k&1?tmp*x%mod:tmp;
}

LL C(LL x,LL y){
	return fac[x]*ifac[y]%mod*ifac[x-y]%mod;
}

LL S(LL x,LL y){
	LL ret=0;
	for (LL i=0;i<=y;++i){
		ret=(ret+pw(-1,i)*C(y,i)%mod*pw(y-i,x))%mod;
	}
	ret=ret*ifac[y]%mod;
	return ret;
}

int main(){
	scanf("%lld%lld",&n,&m);
	fac[0]=1; for (LL i=1;i<=n+m;++i) fac[i]=fac[i-1]*i%mod;
	ifac[n+m]=inv(fac[n+m]); for (LL i=n+m-1;i>=0;--i) ifac[i]=ifac[i+1]*(i+1)%mod;
	for (LL i=1;i<=n;++i){scanf("%lld",&x); ans=(ans+x)%mod;}
	ans=ans*(S(n,m)+S(n-1,m)*(n-1)%mod)%mod;
	printf("%lld\n",ans);
	
	return 0;
}