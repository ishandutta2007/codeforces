#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
#define N 5005
#define NN 1000005

LL n,m,p,a[NN],g[N][N],f[N],F[N],mod,ans,M[NN],fac[NN];

int main(){
	scanf("%lld%lld%lld",&n,&m,&mod);
	M[0]=1; for (LL i=1;i<=m;++i) M[i]=M[i-1]*(m-i+1)%mod;
	fac[0]=1; for (LL i=1;i<=m;++i) fac[i]=fac[i-1]*i%mod;
	for (LL i=1;i<=n;++i) scanf("%lld",a+i);
	g[1][1]=1;
	for (LL i=2;i<=5000;++i)
		for (LL j=1;j<=i;++j)
			g[i][j]=(g[i-1][j]*(j-1)+g[i-1][j-1])%mod;
	f[0]=1;
	for (LL i=1;i<=n;++i){
		LL sum=0;
		for (LL j=0;j<=a[i-1];++j){F[j]=f[j]; f[j]=0; sum=(sum+F[j])%mod;}
		for (LL j=1;j<=a[i];++j){
			LL t=(sum*M[j]-F[j]*fac[j]%mod+mod)%mod;
			f[j]=t*g[a[i]][j]%mod;
		}
		for (LL j=0;j<=a[i-1];++j) F[j]=0;
	}
	for (LL i=0;i<=a[n];++i) ans=(ans+f[i])%mod;
	printf("%lld\n",ans);
	
	return 0;
}