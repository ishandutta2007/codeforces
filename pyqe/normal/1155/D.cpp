#include <bits/stdc++.h>

using namespace std;

long long n,d,a[300069],dp[2][300069],pr[300069],w[300069];

int main()
{
	long long i,mx=0;
	
	scanf("%lld%lld",&n,&d);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	for(i=1;i<=n;i++)
	{
		dp[0][i]=max(dp[0][i-1]+a[i],0ll);
	}
	for(i=n;i;i--)
	{
		dp[1][i]=max(dp[1][i+1]+a[i],0ll);
	}
	for(i=1;i<=n;i++)
	{
		w[i]=max(w[i-1]+a[i]*d,0ll);
		pr[i]=pr[i-1];
		if(w[i]+dp[0][pr[i]]<dp[0][i])
		{
			w[i]=0;
			pr[i]=i;
		}
		mx=max(mx,w[i]+dp[0][pr[i]]+dp[1][i+1]);
	}
	printf("%lld\n",mx);
}