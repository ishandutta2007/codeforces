#include <bits/stdc++.h>

using namespace std;

#define fr first
#define sc second

long long n,a[400069],sz[69],cnt[69][69],dp[1<<20];
vector<long long> pst[69];

int main()
{
	long long i,j,p,p2,mk,mkk,k;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		pst[a[i]].push_back(i);
		sz[a[i]]++;
	}
	for(i=1;i<=20;i++)
	{
		for(j=1;j<=20;j++)
		{
			if(i==j)
			{
				continue;
			}
			for(p=0,p2=0;p<sz[i];p++)
			{
				for(;p2<sz[j]&&pst[j][p2]<pst[i][p];p2++);
				cnt[i][j]+=p2;
			}
		}
	}
	dp[0]=0;
	for(mk=1;mk<1<<20;mk++)
	{
		dp[mk]=1e18;
		for(i=1;i<=20;i++)
		{
			if(mk&1<<i-1)
			{
				mkk=mk-(1<<i-1);
				k=dp[mkk];
				for(j=1;j<=20;j++)
				{
					if(mkk&1<<j-1)
					{
						k+=cnt[j][i];
					}
				}
				dp[mk]=min(dp[mk],k);
			}
		}
	}
	printf("%lld\n",dp[(1<<20)-1]);
}