#include<bits/stdc++.h>

using namespace std;

#define LL long long
#define N 1200000

const LL mod=1000000007;
LL n,ans,a[N],fac[N],ifac[N];

LL inv(LL x){return x==1?1:(mod-mod/x)*inv(mod%x)%mod;}

LL C(LL x,LL y){return fac[x]*ifac[y]%mod*ifac[x-y]%mod;}

int main(){
	scanf("%lld",&n);
	fac[0]=1; for (LL i=1;i<=n;++i) fac[i]=fac[i-1]*i%mod;
	ifac[n]=inv(fac[n]); for (LL i=n-1;i>=0;--i) ifac[i]=ifac[i+1]*(i+1)%mod;
	for (LL i=1;i<=n;++i) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for (LL i=1,sum=0;i<n;++i){
		++sum;
		if (i!=n&&a[i]==a[i+1]) continue;
		LL k=i-sum;
		ans=(ans+sum*a[i]%mod*fac[k]%mod*fac[n-1-k]%mod*C(n,k)%mod+mod)%mod;
		sum=0;
	}
	printf("%lld\n",ans);
	
	return 0;
}