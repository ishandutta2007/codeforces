#include <bits/stdc++.h>

using namespace std;

long long n,a[569],dp[569][569];

long long bf(long long lh,long long rh)
{
	if(lh>rh)
	{
		return 1;
	}
	if(dp[lh][rh]==-1)
	{
		long long i;
		
		dp[lh][rh]=1e18;
		if(a[lh]==a[rh])
		{
			dp[lh][rh]=bf(lh+1,rh-1);
		}
		for(i=lh;i<rh;i++)
		{
			dp[lh][rh]=min(dp[lh][rh],bf(lh,i)+bf(i+1,rh));
		}
	}
	return dp[lh][rh];
}

int main()
{
	long long i,j;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		for(j=i;j<=n;j++)
		{
			dp[i][j]=-1;
		}
	}
	printf("%lld\n",bf(1,n));
}