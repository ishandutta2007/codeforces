#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,d,dp[500069][2];
vector<pair<long long,long long>> al[500069];
bitset<500069> vtd;

void dfs(long long x)
{
	long long i,sz=al[x].size(),l,w;
	priority_queue<long long> pq;
	
	vtd[x]=1;
	dp[x][1]=0;
	for(i=0;i<sz;i++)
	{
		l=al[x][i].fr;
		w=al[x][i].sc;
		if(!vtd[l])
		{
			dfs(l);
			dp[x][1]+=dp[l][0];
			pq.push(dp[l][1]+w-dp[l][0]);
		}
	}
	for(i=0;!pq.empty()&&pq.top()>0&&i<d-1;pq.pop(),i++)
	{
		dp[x][1]+=pq.top();
	}
	dp[x][0]=dp[x][1];
	if(!pq.empty()&&pq.top()>0)
	{
		dp[x][0]+=pq.top();
	}
}

int main()
{
	long long t,rr,i,k,l,w;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		for(i=1;i<=n;i++)
		{
			al[i].clear();
			vtd[i]=0;
		}
		for(i=0;i<n-1;i++)
		{
			scanf("%lld%lld%lld",&k,&l,&w);
			al[k].push_back({l,w});
			al[l].push_back({k,w});
		}
		dfs(1);
		printf("%lld\n",dp[1][0]);
	}
}