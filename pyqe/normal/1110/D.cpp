#include <bits/stdc++.h>

using namespace std;

const long long inf=1e18;
long long n,m,fq[1000069],dp[2][3][3];

int main()
{
	long long i,j,r,ii,k,p;
	
	scanf("%lld%lld",&n,&m);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		fq[k]++;
	}
	for(ii=0;ii<2;ii++)
	{
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{
				dp[ii][i][j]=-inf;
			}
		}
	}
	dp[0][0][0]=0;
	for(i=1;i<=m;i++)
	{
		for(j=0;j<3;j++)
		{
			for(r=0;r<3;r++)
			{
				for(p=0;p<3;p++)
				{
					if(j+r+p>fq[i])
					{
						continue;
					}
					dp[1][r][p]=max(dp[1][r][p],dp[0][j][r]+p+(fq[i]-j-r-p)/3);
				}
			}
		}
		for(j=0;j<3;j++)
		{
			for(r=0;r<3;r++)
			{
				dp[0][j][r]=dp[1][j][r];
				dp[1][j][r]=-inf;
			}
		}
	}
	printf("%lld\n",dp[0][0][0]);
}