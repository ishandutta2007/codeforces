#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,df[200069],dp[200069],z[200069];
pair<long long,long long> a[200069];

int main()
{
	long long i,c,mn;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&a[i].fr);
		a[i].sc=i;
	}
	sort(a+1,a+n+1);
	for(i=0;i<n;i++)
	{
		df[i]=a[i+1].fr-a[i].fr;
	}
	dp[0]=df[0];
	for(i=1;i<=n;i++)
	{
		dp[i]=dp[i-1];
		if(i>=3&&i<=n-3)
		{
			dp[i]=max(dp[i],dp[i-3]+df[i]);
		}
	}
	c=1;
	mn=n;
	for(i=n;i>0;i--)
	{
		if(i<=mn&&dp[i]!=dp[i-1])
		{
			c++;
			mn=i-3;
		}
		z[a[i].sc]=c;
	}
	printf("%lld %lld\n",a[n].fr-dp[n],c);
	for(i=1;i<=n;i++)
	{
		printf("%lld%c",z[i]," \n"[i==n]);
	}
}