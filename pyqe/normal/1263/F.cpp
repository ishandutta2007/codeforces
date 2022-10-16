#include <bits/stdc++.h>

using namespace std;

long long n,m,ed=0,pr[2069],a[1069],ds[2069],d[2][1069][1069],dp[2][1069];
bitset<2069> vtd;

void dfs(long long x)
{
	if(!vtd[pr[x]])
	{
		dfs(pr[x]);
	}
	ds[x]=ds[pr[x]]+1;
	vtd[x]=1;
}

int main()
{
	long long i,j,ii,p,mn[2],z=1e18;
	
	scanf("%lld",&n);
	for(ii=0;ii<2;ii++)
	{
		scanf("%lld",&m);
		ed+=m-1;
		for(i=2;i<=m;i++)
		{
			scanf("%lld",pr+i);
		}
		a[0]=1;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
		}
		for(i=0;i<=n;i++)
		{
			vtd.reset();
			for(p=a[i];p;p=pr[p])
			{
				ds[p]=0;
				vtd[p]=1;
			}
			for(j=i+1;j<=n;j++)
			{
				dfs(a[j]);
				d[ii][i][j]=ds[a[j]];
			}
		}
	}
	for(ii=0;ii<2;ii++)
	{
		for(i=1;i<=n;i++)
		{
			dp[ii][i]=1e18;
		}
	}
	for(i=1;i<=n;i++)
	{
		for(ii=0;ii<2;ii++)
		{
			mn[ii]=1e18;
			for(j=0;j<i;j++)
			{
				mn[ii]=min(mn[ii],dp[ii][j]+d[!ii][j][i]);
				dp[ii][j]+=d[ii][i-1][i];
			}
		}
		for(ii=0;ii<2;ii++)
		{
			dp[ii][i-1]=min(dp[ii][i-1],mn[!ii]);
		}
	}
	for(ii=0;ii<2;ii++)
	{
		for(i=0;i<=n;i++)
		{
			z=min(z,dp[ii][i]);
		}
	}
	printf("%lld\n",ed-z);
}