#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,dg[269],od[269],zs;
vector<pair<long long,long long>> al[269];
bitset<20069> vtd;
pair<long long,long long> sq[20069];

void dfs(long long x)
{
	long long sz=al[x].size(),l,p;
	
	for(;od[x]<sz;)
	{
		l=al[x][od[x]].fr;
		p=al[x][od[x]].sc;
		od[x]++;
		if(!vtd[p])
		{
			vtd[p]=1;
			if(x&&l)
			{
				zs++;
				sq[zs]={x,l};
			}
			dfs(l);
		}
	}
}

int main()
{
	long long t,rr,i,k,l,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&m);
		for(i=1;i<=n;i++)
		{
			al[i].clear();
			dg[i]=0;
			od[i]=0;
		}
		for(i=1;i<=m;i++)
		{
			scanf("%lld%lld",&k,&l);
			al[k].push_back({l,i});
			al[l].push_back({k,i});
			dg[k]++;
			dg[l]++;
			vtd[i]=0;
		}
		z=0;
		for(i=1;i<=n;i++)
		{
			z+=dg[i]%2==0;
			if(dg[i]%2)
			{
				al[0].push_back({i,m+i});
				al[i].push_back({0,m+i});
			}
			vtd[m+i]=0;
		}
		zs=0;
		for(i=0;i<=n;i++)
		{
			if(!od[i])
			{
				dfs(i);
			}
		}
		printf("%lld\n",z);
		for(i=1;i<=zs;i++)
		{
			k=sq[i].fr;
			l=sq[i].sc;
			printf("%lld %lld\n",k,l);
		}
	}
}