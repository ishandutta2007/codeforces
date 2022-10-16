#include <bits/stdc++.h>

using namespace std;

long long n,d,d2,d3,d4,a[1000069][2],dp[1000069][2],inf=1e18;

int main()
{
	long long i,k,sm=0,z;
	
	scanf("%lld%lld%lld%lld%lld",&n,&d,&d2,&d3,&d4);
	d=min(d,d3);
	dp[0][1]=inf;
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		a[i][0]=d*k+d3;
		a[i][1]=min(min(d*(k+1),d2)+min(d,d2),a[i][0]);
		dp[i][0]=min(dp[i-1][0]+a[i][0],dp[i-1][1]+a[i][1]);
		dp[i][1]=min(dp[i-1][0],dp[i-1][1])+a[i][1]+d4*2;
	}
	z=min(dp[n][0],dp[n][1]);
	sm=a[n][0];
	for(i=n-1;i;i--)
	{
		sm+=a[i][1]+d4;
		z=min(z,min(dp[i-1][0],dp[i-1][1])+sm);
	}
	printf("%lld\n",z+d4*(n-1));
}