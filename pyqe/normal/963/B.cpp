#include <bits/stdc++.h>

using namespace std;

long long n,rt,pr[200069],sq[200069],zs=0;
vector<long long> al[200069];
bitset<200069> dg,vtd;

void trv(long long x)
{
	long long i,sz=al[x].size(),l;
	
	vtd[x]=1;
	zs++;
	sq[zs]=x;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			trv(l);
		}
	}
}

void dfs(long long x)
{
	long long i,sz=al[x].size(),l;
	
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		dfs(l);
	}
	if(!dg[x])
	{
		trv(x);
		dg[pr[x]]=!dg[pr[x]];
	}
}

int main()
{
	long long i;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",pr+i);
		if(!pr[i])
		{
			rt=i;
		}
		else
		{
			al[pr[i]].push_back(i);
			dg[i]=!dg[i];
			dg[pr[i]]=!dg[pr[i]];
		}
	}
	dfs(rt);
	if(zs<n)
	{
		printf("NO\n");
	}
	else
	{
		printf("YES\n");
		for(i=1;i<=zs;i++)
		{
			printf("%lld\n",sq[i]);
		}
	}
}