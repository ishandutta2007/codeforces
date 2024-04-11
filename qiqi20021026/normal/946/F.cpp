#include<bits/stdc++.h>

using namespace std;

#define LL long long
#define N 120

const LL mod=1000000007;
LL n,m,f[N][N][N],g[N];
char s[N];

LL pw(LL x,LL k){
	if (k==0) return 1;
	LL tmp=pw(x*x%mod,k>>1);
	return k&1?tmp*x%mod:tmp;
}

int main(){
	scanf("%lld%lld%s",&n,&m,s+1);
	for (LL i=1;i<=n;++i)
		if (s[i]=='0') f[0][i][i]=1;
		else f[1][i][i]=1;
	g[0]=g[1]=1;
	for (LL i=2;i<=m;++i){
		g[i]=(g[i-1]+g[i-2])%(mod-1);
		for (LL l=1;l<=n;++l)
			f[i][l][n]=(f[i][l][n]+f[i-1][l][n]*pw(2,g[i-2]))%mod;
		for (LL l=1;l<=n;++l)
			for (LL r=l;r<n;++r)
				f[i][l][r]=(f[i][l][r]+f[i-1][l][r])%mod;
		for (LL r=1;r<=n;++r)
			f[i][1][r]=(f[i][1][r]+pw(2,g[i-1])*f[i-2][1][r])%mod;
		for (LL l=2;l<=n;++l)
			for (LL r=l;r<=n;++r)
				f[i][l][r]=(f[i][l][r]+f[i-2][l][r])%mod;
		for (LL l=1;l<=n;++l)
			for (LL r=l+1;r<=n;++r)
				for (LL k=l;k<r;++k)
					f[i][l][r]=(f[i][l][r]+f[i-1][l][k]*f[i-2][k+1][r])%mod;
	}
	printf("%lld\n",f[m][1][n]);
	
	return 0;
}