#include <bits/stdc++.h>

using namespace std;

long long n,m,lb,rb,a[1069][2],dp[1069][2][1069];

int main()
{
	long long i,j,ii,z=1e18;
	string s;
	
	scanf("%lld%lld%lld%lld",&n,&m,&lb,&rb);
	for(i=1;i<=n;i++)
	{
		cin>>s;
		for(j=1;j<=m;j++)
		{
			for(ii=0;ii<2;ii++)
			{
				a[j][ii]+=(s[j-1]=='#')^ii;
			}
		}
	}
	for(i=0;i<=m;i++)
	{
		for(ii=0;ii<2;ii++)
		{
			for(j=1;j<=rb;j++)
			{
				dp[i][ii][j]=1e18;
			}
		}
	}
	for(ii=0;ii<2;ii++)
	{
		dp[0][ii][rb]=0;
	}
	for(i=1;i<=m;i++)
	{
		for(ii=0;ii<2;ii++)
		{
			for(j=2;j<=rb;j++)
			{
				dp[i][ii][j]=dp[i-1][ii][j-1]+a[i][ii];
			}
			for(j=lb;j<=rb;j++)
			{
				dp[i][ii][1]=min(dp[i][ii][1],dp[i-1][!ii][j]+a[i][ii]);
			}
		}
	}
	for(ii=0;ii<2;ii++)
	{
		for(i=lb;i<=rb;i++)
		{
			z=min(z,dp[m][ii][i]);
		}
	}
	printf("%lld\n",z);
}