#include<bits/stdc++.h>
using namespace std;

const int mod=998244353;
int f[3010][3010],n,m,a[200010],w[200010],inv[6010],s,s1,inv1[6010],ans[200010];

int quickmi(int a,int b)
{
	int t=1;
	for (; b; b>>=1,a=1ll*a*a%mod)
		if (b&1) t=1ll*t*a%mod;
	return t;
}

int main()
{
	scanf("%d%d",&n,&m),s=0;
	for (int i=1; i<=n; i++) scanf("%d",&a[i]);
	for (int i=1; i<=n; i++) 
	{
		scanf("%d",&w[i]),s+=w[i];
		if (a[i]==1) s1+=w[i];
	}
	for (int i=0; i<=6000; i++) inv[i]=quickmi(s-3000+i,mod-2);
	f[0][0]=1;
	for (int i=1; i<=m; i++)
		for (int j=0; j<=i; j++)
		{
			if (j!=0) f[i][j]=1ll*f[i-1][j-1]*(s1+j-1)%mod*inv[3000+j-1-(i-j)]%mod; else f[i][j]=0;
			if (j!=i) f[i][j]=(f[i][j]+1ll*f[i-1][j]*(s+j-(i-j-1)-(s1+j))%mod*inv[3000+j-(i-j-1)])%mod;
		}
	int tot=0;
	for (int i=0; i<=m; i++) tot=(tot+1ll*i*f[m][i])%mod;
	tot=1ll*tot*quickmi(s1,mod-2)%mod;
	for (int i=1; i<=n; i++) if (a[i]==1) ans[i]=1ll*tot*w[i]%mod;
	tot=0;
	for (int i=0; i<=m; i++) tot=(tot+1ll*(m-i)*f[m][i])%mod;
	tot=1ll*tot*quickmi(s-s1,mod-2)%mod;
	for (int i=1; i<=n; i++) if (a[i]==0) ans[i]=1ll*tot*w[i]%mod;
	for (int i=1; i<=n; i++) 
	{
		if (a[i]==0) ans[i]=(w[i]-ans[i]+mod)%mod;
		else ans[i]=(w[i]+ans[i])%mod;
		printf("%d\n",ans[i]);
	}
	return 0;
}