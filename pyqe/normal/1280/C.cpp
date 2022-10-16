#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,z,sbt[200069],ctd;
vector<pair<long long,long long>> al[200069];
bitset<200069> vtd,rm;

void dfs(long long x)
{
	long long i,sz=al[x].size(),l,w;
	
	vtd[x]=1;
	rm[x]=1;
	sbt[x]=1;
	for(i=0;i<sz;i++)
	{
		l=al[x][i].fr;
		w=al[x][i].sc;
		if(!vtd[l])
		{
			dfs(l);
			if(rm[l])
			{
				z+=w;
			}
			rm[x]=rm[x]^rm[l];
			sbt[x]+=sbt[l];
		}
	}
}

void cfd(long long x,long long w)
{
	long long i,sz=al[x].size(),l,mx=-1e18;
	
	vtd[x]=1;
	for(i=0;i<sz;i++)
	{
		l=al[x][i].fr;
		if(!vtd[l])
		{
			cfd(l,w+sbt[x]-sbt[l]);
			mx=max(mx,sbt[l]);
		}
	}
	if(mx<=n/2&&w<=n/2)
	{
		ctd=x;
	}
}

void bf(long long x)
{
	long long i,sz=al[x].size(),l,w;
	
	vtd[x]=1;
	sbt[x]=1;
	for(i=0;i<sz;i++)
	{
		l=al[x][i].fr;
		w=al[x][i].sc;
		if(!vtd[l])
		{
			bf(l);
			sbt[x]+=sbt[l];
			z+=sbt[l]*w;
		}
	}
}

int main()
{
	long long t,rr,i,ii,k,l,w;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		n*=2;
		for(i=1;i<=n;i++)
		{
			al[i].clear();
		}
		for(i=0;i<n-1;i++)
		{
			scanf("%lld%lld%lld",&k,&l,&w);
			al[k].push_back({l,w});
			al[l].push_back({k,w});
		}
		z=0;
		vtd.reset();
		dfs(1);
		printf("%lld ",z);
		vtd.reset();
		cfd(1,0);
		z=0;
		vtd.reset();
		bf(ctd);
		printf("%lld\n",z);
	}
}