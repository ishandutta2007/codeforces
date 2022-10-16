#include <bits/stdc++.h>

using namespace std;

long long n,d,ttl,a[100069],sbt[100069],dp[100069];
vector<long long> al[100069];
bitset<100069> vtd;

void dfs(long long x)
{
	long long i,sz=al[x].size(),l;
	vector<long long> v;
	bool bad=0;
	
	vtd[x]=1;
	sbt[x]=a[x];
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			dfs(l);
			sbt[x]^=sbt[l];
			v.push_back(l);
		}
	}
	dp[x]=0;
	sz=v.size();
	for(i=0;i<sz;i++)
	{
		l=v[i];
		dp[x]=min(dp[x]+dp[l],2ll);
		bad|=!sbt[x]&&dp[l]==1;
	}
	dp[x]=max(dp[x],(long long)(sbt[x]==ttl));
	dp[x]=max(dp[x],(long long)bad*2);
}

int main()
{
	long long t,rr,i,k,l;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		ttl=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
			ttl^=a[i];
			al[i].clear();
			vtd[i]=0;
		}
		for(i=0;i<n-1;i++)
		{
			scanf("%lld%lld",&k,&l);
			al[k].push_back(l);
			al[l].push_back(k);
		}
		if(!ttl)
		{
			printf("YES\n");
			continue;
		}
		dfs(1);
		for(i=1;i<=n;i++)
		{
			if(dp[i]==2)
			{
				break;
			}
		}
		if(d>=3&&i<=n)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}