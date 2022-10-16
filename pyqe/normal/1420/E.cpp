#include <bits/stdc++.h>

using namespace std;

long long n,nn=0,a[82],ps[82],dp[82][81][3161],inf=1e18;

int main()
{
	long long i,j,r,jj,k,w,c=0,z=0;
	
	scanf("%lld",&n);
	for(i=1;i<=n+1;i++)
	{
		if(i<=n)
		{
			scanf("%lld",&k);
		}
		else
		{
			k=1;
		}
		if(!k)
		{
			c++;
		}
		else
		{
			nn++;
			a[nn]=c;
			c=0;
		}
	}
	for(i=0;i<=nn;i++)
	{
		for(j=0;j<=n-nn+1;j++)
		{
			for(r=0;r<=n*(n-1)/2;r++)
			{
				dp[i][j][r]=-inf;
			}
		}
	}
	dp[0][0][0]=0;
	for(i=1;i<=nn;i++)
	{
		ps[i]=ps[i-1]+a[i];
		for(j=0;j<=n-nn+1;j++)
		{
			for(r=0;r<=j;r++)
			{
				w=(n-nn+1-r)*r;
				k=abs(ps[i]-j);
				for(jj=k;jj<=n*(n-1)/2;jj++)
				{
					dp[i][j][jj]=max(dp[i][j][jj],dp[i-1][j-r][jj-k]+w);
				}
			}
		}
	}
	for(i=0;i<=n*(n-1)/2;i++)
	{
		z=max(z,dp[nn][n-nn+1][i]/2);
		printf("%lld%c",z," \n"[i==n*(n-1)/2]);
	}
}