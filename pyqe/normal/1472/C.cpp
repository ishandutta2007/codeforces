#include <bits/stdc++.h>

using namespace std;

long long n,a[200069],dp[200069];

int main()
{
	long long t,rr,i,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
		}
		z=0;
		dp[n+1]=0;
		for(i=n;i;i--)
		{
			dp[i]=dp[min(i+a[i],n+1)]+a[i];
			z=max(z,dp[i]);
		}
		printf("%lld\n",z);
	}
}