#include<bits/stdc++.h>

using namespace std;

#define N 120
#define LL long long

const LL mod=1000000007;
LL n,m,xb,ans,c[N],d[N],f[N],inv[N];

int main(){
	scanf("%lld%lld",&n,&m);
	inv[1]=1; for (LL i=2;i<=60;++i) inv[i]=(mod-mod/i)*inv[mod%i]%mod;
	for (LL i=2;i*i<=n;++i)
		if (n%i==0){
			c[++xb]=i;
			for (;n%i==0;n/=i) ++d[xb];
		}
	if (n>0){c[++xb]=n; ++d[xb];}
	ans=1;
	for (LL i=1;i<=xb;++i){
		memset(f,0,sizeof f);
		f[d[i]]=1;
		for (LL j=1;j<=m;++j){
			for (LL k=0;k<=d[i];++k){
				f[k]=f[k]*inv[k+1]%mod;
				for (LL l=0;l<k;++l) f[l]=(f[l]+f[k])%mod;
			}
		}
		LL sum=0;
		for (LL j=0,k=1;j<=d[i];++j,k=k*c[i]%mod) sum=(sum+k*f[j])%mod;
		ans=ans*sum%mod;
	}
	printf("%lld\n",ans);
	
	return 0;
}