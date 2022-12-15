#include<cstdio>
#include<cstring>

const int mod=998244353;
int f0[100001][201],f1[100001][201],n,a[100001],s0[100001][201],s1[100001][201];

int main()
{
	scanf("%d",&n);
	for (int i=1; i<=n; i++) scanf("%d",&a[i]);
	if (a[1]==-1) {for (int i=1; i<=200; i++) f0[1][i]=1;}
	else f0[1][a[1]]=1;
	for (int i=1; i<=200; i++) s0[1][i]=(s0[1][i-1]+f0[1][i])%mod;
	for (int i=2; i<=n; i++)
	{
		if (a[i]==-1)
		{
			for (int j=1; j<=200; j++)
				f0[i][j]=(s0[i-1][j-1]+s1[i-1][j-1])%mod,
				f1[i][j]=(1ll*f0[i-1][j]+s1[i-1][200]-s1[i-1][j-1])%mod;
		} else
		{
			int j=a[i];
			f0[i][j]=(s0[i-1][j-1]+s1[i-1][j-1])%mod;
			f1[i][j]=(1ll*f0[i-1][j]+s1[i-1][200]-s1[i-1][j-1])%mod;
		}
		for (int j=1; j<=200; j++) s0[i][j]=(s0[i][j-1]+f0[i][j])%mod,s1[i][j]=(s1[i][j-1]+f1[i][j])%mod;
	}
	int ans=0;
	for (int i=1; i<=200; i++) ans=(ans+f1[n][i])%mod;
	printf("%d\n",(ans+mod)%mod);
	return 0;
}