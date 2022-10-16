#include <bits/stdc++.h>

using namespace std;

long long n,a[2069],dp[2069][2069];

int main()
{
	long long i,j;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++)
	{
		for(j=i-1;j;j--)
		{
			dp[j][i]=min(dp[j+1][i],dp[j][i-1])+a[i]-a[j];
		}
	}
	printf("%lld\n",dp[1][n]);
}