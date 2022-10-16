#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,d,aa[100069][7],a[100069][7],dp[100069][1<<7];
pair<long long,long long> as[100069];

int main()
{
	long long i,j,r,mk,k,ct;
	
	scanf("%lld%lld%lld",&n,&m,&d);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&as[i].fr);
		as[i].sc=i;
	}
	sort(as+1,as+n+1,greater<pair<long long,long long>>());
	for(i=1;i<=n;i++)
	{
		for(j=0;j<m;j++)
		{
			scanf("%lld",&aa[i][j]);
		}
	}
	for(i=0;i<=n;i++)
	{
		for(mk=0;mk<1<<m;mk++)
		{
			dp[i][mk]=-1e18;
		}
	}
	dp[0][0]=0;
	for(i=1;i<=n;i++)
	{
		if(i<=d)
		{
			dp[0][0]+=as[i].fr;
		}
		for(j=0;j<m;j++)
		{
			a[i][j]=aa[as[i].sc][j];
		}
	}
	for(i=1;i<=n;i++)
	{
		for(mk=0;mk<1<<m;mk++)
		{
			ct=__builtin_popcount(mk);
			dp[i][mk]=dp[i-1][mk];
			k=min(as[d+ct].fr-as[i].fr,0ll);
			for(j=0;j<m;j++)
			{
				if(mk>>j&1)
				{
					dp[i][mk]=max(dp[i][mk],dp[i-1][mk^1<<j]+a[i][j]+k);
				}
			}
		}
	}
	printf("%lld\n",dp[n][(1<<m)-1]);
}