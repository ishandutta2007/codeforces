#include <bits/stdc++.h>

using namespace std;

long long n,ttl=0,a[169];
bitset<200069> dp;

int main()
{
	long long i,gd=0;
	
	scanf("%lld",&n);
	dp[0]=1;
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		ttl+=a[i];
		dp=dp|dp<<a[i];
		gd=__gcd(gd,a[i]);
	}
	if(ttl%2||!dp[ttl/2])
	{
		printf("0\n");
		return 0;
	}
	for(i=1;i<=n;i++)
	{
		if(a[i]/gd%2)
		{
			break;
		}
	}
	printf("1\n%lld\n",i);
}