#include <bits/stdc++.h>

using namespace std;

const long long inf=1e18;
long long n,st,fn,a[5][5069],dp[2][5069];

int main()
{
	long long i,j,ii,c=0;
	
	scanf("%lld%lld%lld",&n,&st,&fn);
	for(i=0;i<5;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%lld",&a[i][j]);
		}
	}
	for(ii=0;ii<2;ii++)
	{
		for(i=0;i<=(n+1)/2;i++)
		{
			dp[ii][i]=inf;
		}
	}
	dp[0][1]=-a[0][st]-a[1][st]-a[0][fn]-a[3][fn];
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=(n+1)/2;j++)
		{
			if(i==st)
			{
				dp[1][j]=min(dp[1][j],dp[0][j]+a[1][i]+a[4][i]);
				if(c||j>=2)
				{
					dp[1][j-1]=min(dp[1][j-1],dp[0][j]+a[0][i]*2+a[1][i]+a[3][i]);
				}
			}
			else if(i==fn)
			{
				dp[1][j]=min(dp[1][j],dp[0][j]+a[2][i]+a[3][i]);
				if(c||j>=2)
				{
					dp[1][j-1]=min(dp[1][j-1],dp[0][j]+a[0][i]*2+a[1][i]+a[3][i]);
				}
			}
			else
			{
				dp[1][j+1]=min(dp[1][j+1],dp[0][j]-a[0][i]*2+a[2][i]+a[4][i]);
				if(i>st||j>=2)
				{
					dp[1][j]=min(dp[1][j],dp[0][j]+a[1][i]+a[4][i]);
				}
				if(i>fn||j>=2)
				{
					dp[1][j]=min(dp[1][j],dp[0][j]+a[2][i]+a[3][i]);
				}
				if(c==2||(c&&j>=2)||j>=3)
				{
					dp[1][j-1]=min(dp[1][j-1],dp[0][j]+a[0][i]*2+a[1][i]+a[3][i]);
				}
			}
		}
		c+=i==st||i==fn;
		for(j=0;j<=(n+1)/2;j++)
		{
			dp[0][j]=dp[1][j];
			dp[1][j]=inf;
		}
	}
	printf("%lld\n",dp[0][0]);
}