#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,d,c,a[5069],dp[5069][5069];
priority_queue<pair<long long,long long>> pq[5069];

int main()
{
	long long i,j,z=-1;
	
	scanf("%lld%lld%lld",&n,&d,&c);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=c;j++)
		{
			dp[i][j]=-1e15;
		}
	}
	dp[0][0]=0;
	pq[0].push(mp(0,d));
	for(i=1;i<=n;i++)
	{
		for(j=c;j>=0;j--)
		{
			if(j>0)
			{
				for(;!pq[j-1].empty()&&pq[j-1].top().sc<i;pq[j-1].pop());
				if(!pq[j-1].empty())
				{
					dp[i][j]=a[i]+pq[j-1].top().fr;
					pq[j].push(mp(dp[i][j],i+d));
				}
			}
			if(i>n-d)
			{
				z=max(z,dp[i][j]);
			}
			dp[i][j]=max(dp[i][j],dp[i-1][j]);
		}
	}
	printf("%lld\n",z);
}