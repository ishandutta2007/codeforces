#include <bits/stdc++.h>

using namespace std;

long long n,a[200069],dp[200069],inf=1e18;

int main()
{
	long long i,j,r,z=0,e,e2;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	sort(a+1,a+n+1);
	a[0]=-inf;
	for(i=0;i<31;i++)
	{
		for(r=0,j=1;j<=n;j++)
		{
			for(;a[r]<a[j]-(1ll<<i);r++);
			dp[j]=dp[r]*(a[r]==a[j]-(1ll<<i))+1;
			if(dp[j]>z)
			{
				z=dp[j];
				e=i;
				e2=j;
			}
		}
	}
	z=min(z,3ll);
	printf("%lld\n",z);
	for(i=0;i<z;i++)
	{
		printf("%lld%c",a[e2]-(1ll<<e)*i," \n"[i==z-1]);
	}
}