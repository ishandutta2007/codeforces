#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,dp[1069][1069],dpp[1069][1069],zs=0,inf=1e18;
bitset<1069> a[1069],aa[1069];
pair<pair<long long,long long>,long long> sq[1000069];

int main()
{
	long long rr,i,j,c;
	char ch;
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			scanf(" %c",&ch);
			a[i][j]=ch=='*';
			dp[i][j]=inf;
		}
	}
	for(rr=0;rr<4;rr++)
	{
		for(i=1;i<=n;i++)
		{
			c=0;
			for(j=1;j<=m;j++)
			{
				c=(c+1)*a[i][j];
				dp[i][j]=min(dp[i][j],c);
				aa[m+1-j][i]=a[i][j];
				dpp[m+1-j][i]=dp[i][j];
			}
		}
		swap(n,m);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				a[i][j]=aa[i][j];
				dp[i][j]=dpp[i][j];
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			dp[i][j]-=dp[i][j]==1;
			if(dp[i][j])
			{
				zs++;
				sq[zs]={{i,j},dp[i][j]-1};
			}
		}
	}
	for(rr=0;rr<4;rr++)
	{
		for(i=1;i<=n;i++)
		{
			c=0;
			for(j=1;j<=m;j++)
			{
				c=max(c-1,dp[i][j]);
				a[i][j]=a[i][j]&&!c;
				aa[m+1-j][i]=a[i][j];
				dpp[m+1-j][i]=dp[i][j];
			}
		}
		swap(n,m);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				a[i][j]=aa[i][j];
				dp[i][j]=dpp[i][j];
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(a[i][j])
			{
				printf("-1\n");
				return 0;
			}
		}
	}
	printf("%lld\n",zs);
	for(i=1;i<=zs;i++)
	{
		printf("%lld %lld %lld\n",sq[i].fr.fr,sq[i].fr.sc,sq[i].sc);
	}
}