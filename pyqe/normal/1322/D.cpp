#include <bits/stdc++.h>

using namespace std;

const long long inf=1e18;
long long n,m,a[2069],wg[2069],ky[4069],dp[4069][2069];

int main()
{
	long long i,j,r,ub;
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	for(i=1;i<=n;i++)
	{
		scanf("%lld",wg+i);
	}
	for(i=1;i<=n+m;i++)
	{
		scanf("%lld",ky+i);
	}
	for(i=1;i<=n+m;i++)
	{
		for(j=1;j<=n;j++)
		{
			dp[i][j]=-inf;
		}
	}
	for(i=n;i;i--)
	{
		for(j=n-1;j+1;j--)
		{
			dp[a[i]][j+1]=max(dp[a[i]][j+1],dp[a[i]][j]-wg[i]);
		}
		ub=n;
		for(j=a[i];j<n+m;j++)
		{
			for(r=0;r<=ub;r++)
			{
				dp[j+1][r/2]=max(dp[j+1][r/2],dp[j][r]+ky[j]*r);
			}
			ub/=2;
		}
	}
	printf("%lld\n",dp[n+m][0]);
}