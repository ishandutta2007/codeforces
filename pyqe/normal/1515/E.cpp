#include <bits/stdc++.h>

using namespace std;

long long n,dp[2][3][469][469],dv;

int main()
{
	long long i,j,r,ii,sm,z=0;
	
	scanf("%lld%lld",&n,&dv);
	dp[0][0][0][0]=1;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=i;j++)
		{
			for(r=1;r<=j;r++)
			{
				dp[1][1][j][r]=(dp[1][1][j][r]+dp[0][0][j-1][0])%dv;
			}
			sm=0;
			for(r=j;r;r--)
			{
				sm=(sm+dp[0][1][j-1][r])%dv;
				dp[1][1][j][r]=(dp[1][1][j][r]+sm)%dv;
			}
			sm=0;
			for(r=1;r<=j;r++)
			{
				sm=(sm+dp[0][1][j-1][r-1]+dp[0][2][j-1][r-1])%dv;
				dp[1][2][j][r]=(dp[1][2][j][r]+sm)%dv;
			}
			dp[1][0][j-1][0]=sm;
		}
		for(j=1;j<=i;j++)
		{
			for(r=1;r<=j;r++)
			{
				for(ii=0;ii<2;ii++)
				{
					dp[0][ii+1][j][r]=dp[1][ii+1][j][r];
					dp[1][ii+1][j][r]=0;
				}
			}
		}
		for(j=0;j<=i;j++)
		{
			dp[0][0][j][0]=dp[1][0][j][0];
			dp[1][0][j][0]=0;
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=i;j++)
		{
			for(ii=0;ii<2;ii++)
			{
				z=(z+dp[0][ii+1][i][j])%dv;
			}
		}
	}
	printf("%lld\n",z);
}