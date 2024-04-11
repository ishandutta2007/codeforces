#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

const long long ma=86400;
long long n,d,dp[4069];
pair<long long,long long> a[4069];

int main()
{
	long long i,j,k,l,k2,z=0;
	
	scanf("%lld%lld",&n,&d);
	for(i=1;i<=n;i++)
	{
		scanf("%lld%lld",&k,&l);
		a[i]={k,l};
	}
	a[0].fr=1;
	a[n+1].fr=ma+1;
	sort(a+1,a+n+1);
	for(i=1;i<=n+1;i++)
	{
		k=a[i].fr;
		l=a[i].sc;
		k2=a[i-1].fr;
		for(j=0;j<=d;j++)
		{
			if(k2+dp[j]-1<k)
			{
				z=max(z,a[min(i+d-j,n+1)].fr-1-(k2+dp[j]-1));
			}
		}
		for(j=0;j<=d;j++)
		{
			dp[j]=max(dp[j]-(k-k2),0ll);
		}
		for(j=d;j>=0;j--)
		{
			dp[j]+=l;
			if(j)
			{
				dp[j]=min(dp[j],dp[j-1]);
			}
		}
	}
	printf("%lld\n",z);
}