#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
#define N 300000

const LL mod=998244353;
LL n,m,t,a[N],fac[N],ifac[N],pw[N],ans;

LL inv(LL x){return x==1?1:(mod-mod/x)*inv(mod%x)%mod;}

LL C(LL x,LL y){
	return x<y||y<0?0:fac[x]*ifac[y]%mod*ifac[x-y]%mod;
}

void upd(LL &x,LL y){x=(x+y)%mod;}

int main(){
	scanf("%lld%lld",&n,&m);
	for (LL i=0;i<n;++i){
		scanf("%lld",a+i);
	}
	for (LL i=0;i<n;++i){
		t+=a[i]!=a[(i+1)%n];
	}
	fac[0]=1; for (LL i=1;i<=n;++i) fac[i]=fac[i-1]*i%mod;
	ifac[n]=inv(fac[n]); for (LL i=n-1;~i;--i) ifac[i]=ifac[i+1]*(i+1)%mod;
	pw[0]=1; for (LL i=1;i<=n;++i) pw[i]=pw[i-1]*(m-2)%mod;
	for (LL i=0,pw2=1,I2=inv(2);i<=t;++i,pw2=pw2*2%mod){
		LL tmp=pw2;
		if (i%2==0) upd(tmp,-C(i,i/2));
		upd(ans,pw[t-i]*C(t,i)%mod*tmp%mod*I2);
	}
	for (LL i=1;i<=n-t;++i) ans=ans*m%mod;
	upd(ans,mod);
	printf("%lld\n",ans);
	
	return 0;
}