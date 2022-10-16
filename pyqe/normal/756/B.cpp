#include <bits/stdc++.h>

using namespace std;

long long n,a[100069],dp[100069],d[3]={1,90,1440},w[3]={20,50,120};

int main()
{
	long long i,j;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	a[0]=-1e18;
	for(i=1;i<=n;i++)
	{
		dp[i]=1e18;
		for(j=0;j<3;j++)
		{
			dp[i]=min(dp[i],dp[upper_bound(a,a+n+1,a[i]-d[j])-a-1]+w[j]);
		}
		printf("%lld\n",dp[i]-dp[i-1]);
	}
}