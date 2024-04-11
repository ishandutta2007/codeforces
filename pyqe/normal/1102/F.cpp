#include <bits/stdc++.h>

using namespace std;

long long n,m,fu,a[16][10069],am[16][16],ame[16][16],dp[16][1<<16][16];

int main()
{
	long long i,j,r,mk,z=-1e18;
	
	scanf("%lld%lld",&n,&m);
	fu=(1<<n)-1;
	for(i=0;i<n;i++)
	{
		for(j=1;j<=m;j++)
		{
			scanf("%lld",&a[i][j]);
		}
		for(j=0;j<n;j++)
		{
			am[i][j]=1e18;
			ame[i][j]=1e18;
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			for(r=1;r<=m;r++)
			{
				am[i][j]=min(am[i][j],abs(a[i][r]-a[j][r]));
				if(r<m)
				{
					ame[i][j]=min(ame[i][j],abs(a[i][r]-a[j][r+1]));
				}
			}
		}
	}
	for(mk=0;mk<1<<n;mk++)
	{
		for(i=0;i<n;i++)
		{
			if(mk>>i&1)
			{
				if(1<<i==mk)
				{
					dp[i][mk][i]=1e18;
				}
				else
				{
					for(j=0;j<n;j++)
					{
						if(mk>>j&1)
						{
							dp[i][mk][j]=-1e18;
							for(r=0;r<n;r++)
							{
								if(r!=j&&(mk>>r&1))
								{
									dp[i][mk][j]=max(dp[i][mk][j],min(dp[i][mk^1<<j][r],am[r][j]));
								}
							}
						}
					}
				}
				
			}
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			dp[i][fu][j]=min(dp[i][fu][j],ame[j][i]);
			z=max(z,dp[i][fu][j]);
		}
	}
	printf("%lld\n",z);
}