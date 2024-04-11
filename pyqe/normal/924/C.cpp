#include <bits/stdc++.h>

using namespace std;

long long n,a[100069],dp[100069];

int main()
{
	long long i,z=0;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		dp[i]=max(dp[i-1],a[i]+1);
	}
	for(i=n;i;i--)
	{
		dp[i]=max(dp[i],dp[i+1]-1);
		z+=dp[i]-a[i]-1;
	}
	printf("%lld\n",z);
}