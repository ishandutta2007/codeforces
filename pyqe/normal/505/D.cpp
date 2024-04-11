#include <bits/stdc++.h>

using namespace std;

long long n,m,dsu[100069],z=0;
vector<long long> al[100069];
bitset<100069> vtd,vtd2,spc;

long long fd(long long x)
{
	if(dsu[x]!=x)
	{
		dsu[x]=fd(dsu[x]);
	}
	return dsu[x];
}

void dfs(long long x)
{
	long long i,sz=al[x].size(),l;
	
	vtd[x]=1;
	vtd2[x]=1;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			dfs(l);
		}
		else if(vtd2[l])
		{
			z+=!spc[fd(x)];
			spc[fd(x)]=1;
		}
	}
	vtd2[x]=0;
}

int main()
{
	long long i,k,l;
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		dsu[i]=i;
	}
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld",&k,&l);
		z+=fd(k)!=fd(l);
		dsu[fd(l)]=fd(k);
		al[k].push_back(l);
	}
	for(i=1;i<=n;i++)
	{
		if(!vtd[i])
		{
			dfs(i);
		}
	}
	printf("%lld\n",z);
}