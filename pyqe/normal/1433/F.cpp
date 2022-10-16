#include <bits/stdc++.h>

using namespace std;

long long n,m,d,dp[36][70],dp2[2][70],inf=1e18;

int main()
{
	long long rr,i,j,r,k;
	
	scanf("%lld%lld%lld",&n,&m,&d);
	for(i=0;i<d;i++)
	{
		dp2[0][i]=-inf;
		dp2[1][i]=-inf;
	}
	dp2[0][0]=0;
	for(rr=0;rr<n;rr++)
	{
		for(i=0;i<=m/2;i++)
		{
			for(j=1;j<d;j++)
			{
				dp[i][j]=-inf;
			}
			dp[i][0]=0;
		}
		for(i=0;i<m;i++)
		{
			scanf("%lld",&k);
			for(j=m/2;j;j--)
			{
				for(r=0;r<d;r++)
				{
					dp[j][r]=max(dp[j][r],dp[j-1][(r+d-k%d)%d]+k);
				}
			}
		}
		for(i=0;i<d;i++)
		{
			for(j=0;j<d;j++)
			{
				dp2[1][j]=max(dp2[1][j],dp2[0][(j+d-i)%d]+dp[m/2][i]);
			}
		}
		for(i=0;i<d;i++)
		{
			dp2[0][i]=dp2[1][i];
			dp2[1][i]=-inf;
		}
	}
	printf("%lld\n",dp2[0][0]);
}