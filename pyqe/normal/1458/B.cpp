#include <bits/stdc++.h>

using namespace std;

long long n,ma=100,dp[2][169][30069],inf=1e18;

int main()
{
	long long i,j,r,ii,k,l,mx;
	
	scanf("%lld",&n);
	for(ii=0;ii<2;ii++)
	{
		for(i=0;i<=n;i++)
		{
			for(j=-n*ma;j<=n*ma*2;j++)
			{
				dp[ii][i][n*ma+j]=-inf;
			}
		}
	}
	dp[0][0][n*ma]=0;
	for(i=1;i<=n;i++)
	{
		scanf("%lld%lld",&k,&l);
		for(j=0;j<=i-1;j++)
		{
			for(r=-(i-1)*ma;r<=(i-1)*ma*2;r++)
			{
				dp[1][j+1][n*ma+r+(k-l)*2]=max(dp[1][j+1][n*ma+r+(k-l)*2],dp[0][j][n*ma+r]+l*2);
				dp[1][j][n*ma+r-l]=max(dp[1][j][n*ma+r-l],dp[0][j][n*ma+r]+l);
			}
		}
		for(j=0;j<=i;j++)
		{
			for(r=-i*ma;r<=i*ma*2;r++)
			{
				dp[0][j][n*ma+r]=dp[1][j][n*ma+r];
				dp[1][j][n*ma+r]=-inf;
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		mx=-inf;
		for(j=-n*ma;j<=n*ma*2;j++)
		{
			mx=max(mx,dp[0][i][n*ma+j]+min(j,0ll));
		}
		printf("%lld.%lld%c",mx/2,mx%2*5," \n"[i==n]);
	}
}