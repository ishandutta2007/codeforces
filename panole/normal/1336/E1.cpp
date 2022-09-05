#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;

int x,n,m,cnt,X,ans[40],a[40][40],f[40][66001],bc[66001];
long long xxj[40],xx,y;

int main()
{
	scanf("%d%d",&n,&m),cnt=0;
	for (int i=1; i<=n; i++) 
	{
		scanf("%I64d",&xx);
		for (int j=m-1; j>=0; j--) if (xx>>j&1) 
		{
			if (xxj[j]) xx^=xxj[j]; else
			{xxj[j]=xx,cnt++; break;}
		}
	}
	X=1;
	for (int i=1; i<=n-cnt; i++) X=2ll*X%mod;
	if (cnt<=20)
	{
		for (int i=0; i<(1<<cnt); i++)
		{
			x=i,y=0;
			for (int j=m-1; j>=0; j--) if (xxj[j]) y|=((1ll*(x&1))<<j),x>>=1;
			for (int j=m-1; j>=0; j--) if (xxj[j]&&(y>>j&1)) y^=xxj[j];
			int nw=0;
			for (int j=0; j<cnt; j++) if (i>>j&1) nw++;
			for (int j=0; j<m; j++) if (y>>j&1) nw++;
			ans[nw]++;
		}
	} else
	{
		for (int i=m-1; i>=0; i--) if (xxj[i])
			for (int j=i-1; j>=0; j--) if (xxj[j]&&(xxj[i]>>j&1)) xxj[i]^=xxj[j];
		f[0][0]=1;
		for (int i=0; i<m; i++)
			if (xxj[i])
			{
				x=0;
				for (int j=0; j<m; j++) if (!xxj[j]) x=(x<<1|(xxj[i]>>j&1));
				for (int k=cnt-1; k>=0; k--)
					for (int j=0; j<(1<<m-cnt); j++) f[k+1][j^x]=(f[k+1][j^x]+f[k][j]>=mod?f[k+1][j^x]+f[k][j]-mod:f[k+1][j^x]+f[k][j]);
			}
		bc[0]=0;
		for (int j=1; j<(1<<m-cnt); j++) bc[j]=bc[j^(j&-j)]+1;
		for (int i=0; i<=cnt; i++)
			for (int j=0; j<(1<<m-cnt); j++) ans[i+bc[j]]=(ans[i+bc[j]]+f[i][j]>=mod?ans[i+bc[j]]+f[i][j]-mod:ans[i+bc[j]]+f[i][j]);
	}
	for (int i=0 ;i<=m; i++) printf("%d ",1ll*X*ans[i]%mod);
	return 0;
}