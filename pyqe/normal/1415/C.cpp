#include <bits/stdc++.h>

using namespace std;

long long n,m,m2,d,d2,dp[100069],inf=1e18;
bitset<100069> a;

int main()
{
	long long t,rr,i,z;
	char ch;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld",&n,&m,&m2);
		for(i=1;i<=n;i++)
		{
			scanf(" %c",&ch);
			a[i]=ch-'0';
		}
		scanf("%lld%lld",&d,&d2);
		dp[n+1]=0;
		for(i=n;i;i--)
		{
			dp[i]=dp[min(i+m2,n+1)]+!a[i];
		}
		z=inf;
		for(i=0;i<=n-m;i++)
		{
			z=min(z,dp[i+m]*d+i*d2);
		}
		printf("%lld\n",z);
	}
}