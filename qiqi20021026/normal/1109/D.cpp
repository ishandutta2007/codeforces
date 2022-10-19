#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
#define N 3000000

const LL mod=1000000007;
LL n,m,p,ans,fac[N],ifac[N];

void upd(LL &x,LL y){x=(x+y%mod+mod)%mod;}

LL inv(LL x){
	return x==1?1:(mod-mod/x)*inv(mod%x)%mod;
}

LL pw(LL x,LL k){
	if (!k) return 1;
	LL tmp=pw(x*x%mod,k>>1);
	return k&1?tmp*x%mod:tmp;
}

LL C(LL x,LL y){
	return x<y?0:fac[x]*ifac[y]%mod*ifac[x-y]%mod;
}

LL P(LL x,LL y){
	return x<y?0:fac[x]*ifac[x-y]%mod;
}

int main(){
	scanf("%lld%lld%*d%*d",&n,&m); p=n+m;
	fac[0]=1; for (LL i=1;i<=p;++i) fac[i]=fac[i-1]*i%mod;
	ifac[p]=inv(fac[p]); for (LL i=p-1;~i;--i) ifac[i]=ifac[i+1]*(i+1)%mod;
	for (LL k=1;k<n-1;++k)
		upd(ans,P(n-2,k-1)*C(m-1,k-1)%mod*pw(m,n-k-1)%mod*pw(n,n-k-2)%mod*(k+1));
	upd(ans,fac[n-2]*C(m-1,n-2));
	printf("%lld\n",ans);
	
	return 0;
}