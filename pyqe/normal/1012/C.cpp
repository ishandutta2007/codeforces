#include <bits/stdc++.h>

using namespace std;

long long n,nn,a[5069],dp[5069][2569][2],inf=1e18;

int main()
{
	long long i,j,ii,k,sm[2];
	
	scanf("%lld",&n);
	nn=(n+1)/2;
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=nn;j++)
		{
			for(ii=0;ii<2;ii++)
			{
				dp[i][j][ii]=inf;
			}
		}
	}
	dp[0][0][0]=0;
	for(i=1;i<=n;i++)
	{
		for(j=0;j<=nn;j++)
		{
			dp[i][j][0]=min(dp[i-1][j][0],dp[i-1][j][1]);
			if(j)
			{
				k=0;
				sm[0]=inf*!!(j-1);
				sm[1]=inf;
				if(i>=2)
				{
					k=a[i-2];
					for(ii=0;ii<2;ii++)
					{
						sm[ii]=dp[i-2][j-1][ii];
					}
				}
				dp[i][j][1]=min(sm[0]+max(a[i-1]-a[i]+1,0ll),sm[1]+max(min(a[i-1],k-1)-a[i]+1,0ll))+max(a[i+1]-a[i]+1,0ll);
			}
		}
	}
	for(i=1;i<=nn;i++)
	{
		printf("%lld%c",min(dp[n][i][0],dp[n][i][1])," \n"[i==nn]);
	}
}