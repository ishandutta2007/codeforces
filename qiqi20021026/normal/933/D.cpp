#include<bits/stdc++.h>

using namespace std;

#define N 1200000
#define LL long long

const LL mod=1000000007;
LL n,sum2[N],sum4[N],sum6[N],tmp,ans,x,y,x2,x4,x6;

LL inv(LL x){return x==1?1:(mod-mod/x)*inv(mod%x)%mod;}

int main(){
	scanf("%lld",&n);
	sum2[0]=sum4[0]=sum6[0]=0;
	for (LL i=1;i*i<=n;++i){
		sum2[i]=(sum2[i-1]+i*i)%mod;
		sum4[i]=(sum4[i-1]+i*i%mod*i%mod*i)%mod;
		sum6[i]=(sum6[i-1]+i*i%mod*i%mod*i%mod*i%mod*i)%mod;
	}
	for (x=1;x*x<=n;++x){
		y=sqrt(n-x*x);
		x2=x*x%mod;
		x4=x*x%mod*x%mod*x%mod;
		x6=x*x%mod*x%mod*x%mod*x%mod*x%mod;
		tmp=n%mod*(n%mod+1)%mod*(n%mod+2)%mod*y%mod;
		tmp=(tmp+2*x6%mod*y)%mod;
		tmp=(tmp+6*x4%mod*sum2[y])%mod;
		tmp=(tmp+6*x2%mod*sum4[y])%mod;
		tmp=(tmp+2*sum6[y])%mod;
		tmp=(tmp-3*(n+2)%mod*(x4%mod*y%mod+2*x2%mod*sum2[y]%mod+sum4[y]))%mod;
		tmp=(tmp+(3*n+4)%mod*(x2%mod*y%mod+sum2[y]))%mod;
		tmp=(tmp%mod+mod)%mod;
		ans=(ans+tmp*4)%mod;
		tmp=n%mod*(n%mod+1)%mod*(n%mod+2)%mod;
		tmp=(tmp+2*x6)%mod;
		tmp=(tmp-3*(n+2)%mod*x4)%mod;
		tmp=(tmp+(3*n+4)%mod*x2)%mod;
		tmp=(tmp%mod+mod)%mod;
		ans=(ans+tmp*2)%mod;
	}
	y=sqrt(n);
	tmp=n%mod*(n%mod+1)%mod*(n%mod+2)%mod*y%mod;
	tmp=(tmp+2*sum6[y])%mod;
	tmp=(tmp-3*(n+2)%mod*sum4[y])%mod;
	tmp=(tmp+(3*n+4)%mod*sum2[y])%mod;
	tmp=(tmp%mod+mod)%mod;
	ans=(ans+tmp*2)%mod;
	tmp=n%mod*(n%mod+1)%mod*(n%mod+2)%mod;
	tmp=(tmp%mod+mod)%mod;
	ans=(ans+tmp)%mod;
	ans=ans*inv(6)%mod;
	printf("%lld\n",ans);
	
	return 0;
}