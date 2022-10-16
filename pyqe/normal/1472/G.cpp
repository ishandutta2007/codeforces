#include <bits/stdc++.h>

using namespace std;

long long n,m,nr[200069],dp[200069],inf=1e18;
vector<long long> al[200069];
queue<long long> q;
bitset<200069> vtd;

void dfs(long long x)
{
	long long i,sz=al[x].size(),l;
	
	vtd[x]=1;
	dp[x]=nr[x];
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(nr[l]>nr[x])
		{
			if(!vtd[l])
			{
				dfs(l);
			}
			dp[x]=min(dp[x],dp[l]);
		}
		dp[x]=min(dp[x],nr[l]);
	}
}

int main()
{
	long long t,rr,i,k,l,sz;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&m);
		for(i=1;i<=n;i++)
		{
			al[i].clear();
			nr[i]=inf;
			vtd[i]=0;
		}
		for(i=0;i<m;i++)
		{
			scanf("%lld%lld",&k,&l);
			al[k].push_back(l);
		}
		q.push(1);
		nr[1]=0;
		for(;!q.empty();)
		{
			k=q.front();
			q.pop();
			sz=al[k].size();
			for(i=0;i<sz;i++)
			{
				l=al[k][i];
				if(nr[k]+1<nr[l])
				{
					q.push(l);
					nr[l]=nr[k]+1;
				}
			}
		}
		dfs(1);
		for(i=1;i<=n;i++)
		{
			printf("%lld%c",dp[i]," \n"[i==n]);
		}
	}
}