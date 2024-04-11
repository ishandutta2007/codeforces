#include <bits/stdc++.h>

using namespace std;

long long n,m,d,d2,nn=0,a[1069],dp[2][10069],inf=1e18;

int main()
{
	long long i,j,r,k,on;
	
	scanf("%lld%lld%lld%lld",&n,&m,&d,&d2);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	dp[0][0]=m;
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		on=nn;
		for(j=0;j<=on+a[i];j++)
		{
			dp[1][j]=-inf;
			for(r=max(j-a[i],0ll);r<=min(j,on);r++)
			{
				dp[1][j]=max(dp[1][j],dp[0][r]-k*(j-r));
			}
			nn+=dp[1][j]>=0&&j>nn;
		}
		for(j=0;j<=nn;j++)
		{
			dp[0][j]=min(dp[1][j]+d2,m+d*j);
		}
	}
	printf("%lld\n",nn);
}