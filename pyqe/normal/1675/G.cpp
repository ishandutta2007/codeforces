#include <bits/stdc++.h>

using namespace std;

const long long inf=1e18;
long long n,m,dp[2][269][269];

int main()
{
	long long i,j,r,ii,k,sm=0,mn,z=inf;
	
	scanf("%lld%lld",&n,&m);
	for(ii=0;ii<2;ii++)
	{
		for(i=0;i<=m;i++)
		{
			for(j=0;j<=m;j++)
			{
				dp[ii][i][j]=inf;
			}
		}
	}
	dp[0][0][m]=0;
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		sm+=k;
		for(j=0;j<=m;j++)
		{
			mn=inf;
			for(r=m;r>=0;r--)
			{
				mn=min(mn,dp[0][j][r]);
				if(j+r<=m)
				{
					dp[1][j+r][r]=min(dp[1][j+r][r],mn+abs(sm-(j+r)));
				}
			}
		}
		for(j=0;j<=m;j++)
		{
			for(r=0;r<=m;r++)
			{
				dp[0][j][r]=dp[1][j][r];
				dp[1][j][r]=inf;
			}
		}
	}
	for(i=0;i<=m;i++)
	{
		z=min(z,dp[0][m][i]);
	}
	printf("%lld\n",z);
}