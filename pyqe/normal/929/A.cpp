#include <bits/stdc++.h>

using namespace std;

long long n,d,a[100069],dp[100069];

int main()
{
	long long i,j;
	
	scanf("%lld%lld",&n,&d);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	for(j=1,i=2;i<=n;i++)
	{
		for(;a[j]<a[i]-d;j++);
		if(j==i)
		{
			printf("-1\n");
			return 0;
		}
		dp[i]=dp[j]+1;
	}
	printf("%lld\n",dp[n]);
}