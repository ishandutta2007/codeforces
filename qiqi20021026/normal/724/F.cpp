#include<bits/stdc++.h>

using namespace std;

#define LL long long
#define N 1200

LL n,m,mod,ans,f[N][12][N],g[N][12];

LL inv(LL x){return x==1?1:(mod-mod/x)*inv(mod%x)%mod;}

int main(){
	scanf("%lld%lld%lld",&n,&m,&mod);
	if (n<=2) return puts("1");
	f[1][0][0]=1; for (LL i=1;i<=n;++i) f[1][0][i]=g[1][i]=1;
	for (LL i=2;i<=n;++i){
		for (LL j=1;j<=m;++j){
			for (LL k=1;k<i;++k)
				for (LL l=1;l<=j&&k*l<i;++l)
					f[i][j][k]=(f[i][j][k]+f[i-l*k][j-l][k-1]*g[k][l])%mod;
			for (LL k=1;k<=n;++k)
				f[i][j][k]=(f[i][j][k]+f[i][j][k-1])%mod;
		}
		g[i][1]=f[i][m-1][n];
		for (LL j=2;j<=m;++j) g[i][j]=g[i][j-1]*inv(j)%mod*(j+f[i][m-1][n]-1)%mod;
	}
	ans=f[n][m][n/2];
	if (!(n&1)) ans=(ans-f[n/2][m-1][n/2]*(f[n/2][m-1][n/2]-1)%mod*inv(2)%mod+mod)%mod;
	printf("%lld\n",ans);
	
	return 0;
}