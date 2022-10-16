#include <bits/stdc++.h>

using namespace std;

long long n,st[2],cr,dis[2][200069],cdis=0,inf=1e18;
vector<long long> al[200069];
bitset<200069> vtd;

void dfs(long long x)
{
	long long i,sz=al[x].size(),l;
	
	vtd[x]=1;
	dis[cr][x]=cdis;
	cdis++;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			dfs(l);
		}
	}
	cdis--;
}

int main()
{
	long long i,ii,k,l,z=-inf;
	
	st[0]=1;
	scanf("%lld%lld",&n,st+1);
	for(i=0;i<n-1;i++)
	{
		scanf("%lld%lld",&k,&l);
		al[k].push_back(l);
		al[l].push_back(k);
	}
	for(ii=0;ii<2;ii++)
	{
		vtd.reset();
		cr=ii;
		dfs(st[ii]);
	}
	for(i=1;i<=n;i++)
	{
		if(dis[1][i]<dis[0][i])
		{
			z=max(z,dis[0][i]);
		}
	}
	printf("%lld\n",z*2);
}