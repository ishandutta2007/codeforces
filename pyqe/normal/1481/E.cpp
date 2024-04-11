#include <bits/stdc++.h>

using namespace std;

long long n,a[500069],mn[500069],mx[500069],fq[500069],dp[500069];

int main()
{
	long long i;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	for(i=n;i;i--)
	{
		mn[a[i]]=i;
		mx[a[i]]=max(mx[a[i]],i);
	}
	for(i=n;i;i--)
	{
		fq[a[i]]++;
		dp[i]=max(dp[i+1],fq[a[i]]);
		if(mn[a[i]]==i)
		{
			dp[i]=max(dp[i],dp[mx[a[i]]+1]+fq[a[i]]);
		}
	}
	printf("%lld\n",n-dp[1]);
}