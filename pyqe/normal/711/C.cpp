#include <bits/stdc++.h>

using namespace std;

long long n,m,d,a[169],am[169][169],dp[169][169][169];

int main()
{
	long long i,j,jj,r,mn=1e18,k;
	
	scanf("%lld%lld%lld",&n,&m,&d);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			scanf("%lld",&am[i][j]);
		}
	}
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=m;j++)
		{
			for(r=0;r<=d;r++)
			{
				dp[i][j][r]=1e18;
			}
		}
	}
	dp[0][0][0]=0;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			for(r=1;r<=d;r++)
			{
				k=1e18;
				for(jj=0;jj<=m;jj++)
				{
					if(jj==j)
					{
						continue;
					}
					k=min(k,dp[i-1][jj][r-1]);
				}
				dp[i][j][r]=min(dp[i-1][j][r],k);
				if(!a[i])
				{
					dp[i][j][r]+=am[i][j];
				}
				else if(j!=a[i])
				{
					dp[i][j][r]=1e18;
				}
			}
			if(i==n)
			{
				mn=min(mn,dp[i][j][d]);
			}
		}
	}
	if(mn==1000000000000000000)
	{
		printf("-1\n");
	}
	else
	{
		printf("%lld\n",mn);
	}
}