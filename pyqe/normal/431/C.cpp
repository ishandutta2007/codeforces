#include <bits/stdc++.h>

using namespace std;

long long n,m,d,dp[2][169][2],dv=1e9+7;

int main()
{
	long long i,j,r,ii,z=0;
	
	scanf("%lld%lld%lld",&n,&m,&d);
	dp[0][0][0]=1;
	for(i=1;i<=n;i++)
	{
		for(j=0;j<=n;j++)
		{
			for(r=1;r<=min(m,j);r++)
			{
				for(ii=0;ii<2;ii++)
				{
					dp[1][j][ii||r>=d]=(dp[1][j][ii||r>=d]+dp[0][j-r][ii])%dv;
				}
			}
		}
		for(j=0;j<=n;j++)
		{
			for(ii=0;ii<2;ii++)
			{
				dp[0][j][ii]=dp[1][j][ii];
				dp[1][j][ii]=0;
			}
		}
		z=(z+dp[0][n][1])%dv;
	}
	printf("%lld\n",z);
}