#include<bits/stdc++.h>
using namespace std;

const int mod=1000000007;
long long n,Nw;
int k,a[21],p[21],cnt,lim[21],ans,f[20][61],F[20][61],inv[101];

int quickmi(int a,int b)
{
	int t=1;
	for (; b; b>>=1,a=1ll*a*a%mod)
		if (b&1) t=1ll*t*a%mod;
	return t; 
}

void dfs(int x,int nw,int P)
{
	if (x==cnt+1) {ans=(ans+1ll*nw*P)%mod; return;}
	for (int i=0; i<a[x]; i++) dfs(x+1,nw,1ll*P*f[x][i]%mod),nw=1ll*nw*p[x]%mod;
	dfs(x+1,nw,1ll*P*f[x][a[x]]%mod);
}

int main()
{
	for (int i=1; i<=100; i++) inv[i]=quickmi(i,mod-2);
	scanf("%I64d%d",&n,&k); cnt=0;
	for (int i=2; 1ll*i*i<=n; i++)
		if (n%i==0) 
		{
			p[++cnt]=i; a[cnt]=0;
			while (n%i==0) n/=i,a[cnt]++;
		}
	if (n!=1) p[++cnt]=n%mod,a[cnt]=1; 
	for (int i=1; i<=cnt; i++)
	{
		f[i][a[i]]=1;
		for (int j=1; j<=k; j++)
		{
			F[i][a[i]+1]=0;
			for (int l=a[i]; l>=0; l--) F[i][l]=(F[i][l+1]+1ll*inv[l+1]*f[i][l])%mod;
			for (int l=0; l<=a[i]; l++) f[i][l]=F[i][l];
		}
	}
	ans=0; dfs(1,1,1); printf("%d\n",ans);
	return 0;
}