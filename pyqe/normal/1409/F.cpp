#include <bits/stdc++.h>

using namespace std;

long long n,d,a[269],ex[2],dp[2][269][269],inf=1e18;

int main()
{
	long long i,j,r,ii,jj,z=-inf;
	char ch;
	
	scanf("%lld%lld",&n,&d);
	for(i=1;i<=n;i++)
	{
		scanf(" %c",&ch);
		a[i]=ch-'a';
	}
	for(ii=0;ii<2;ii++)
	{
		scanf(" %c",&ch);
		ex[ii]=ch-'a';
	}
	for(ii=0;ii<2;ii++)
	{
		for(i=0;i<=d;i++)
		{
			for(j=0;j<=n;j++)
			{
				dp[ii][i][j]=-inf;
			}
		}
	}
	dp[0][0][0]=0;
	for(i=1;i<=n;i++)
	{
		for(j=0;j<26;j++)
		{
			for(r=j!=a[i];r<=d;r++)
			{
				for(jj=j==ex[0];jj<=n;jj++)
				{
					dp[1][r][jj]=max(dp[1][r][jj],dp[0][r-(j!=a[i])][jj-(j==ex[0])]+(jj-(j==ex[0]))*(j==ex[1]));
				}
			}
		}
		for(j=0;j<=d;j++)
		{
			for(r=0;r<=n;r++)
			{
				dp[0][j][r]=dp[1][j][r];
				dp[1][j][r]=-inf;
			}
		}
	}
	for(i=0;i<=d;i++)
	{
		for(j=0;j<=n;j++)
		{
			z=max(z,dp[0][i][j]);
		}
	}
	printf("%lld\n",z);
}