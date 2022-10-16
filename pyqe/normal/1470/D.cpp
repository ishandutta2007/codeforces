#include <bits/stdc++.h>

using namespace std;

long long n,m,dsu[300069],sq[300069],zs;
vector<long long> al[300069];
bitset<300069> vtd,spc;

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
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(spc[l])
		{
			break;
		}
	}
	if(i==sz)
	{
		zs++;
		sq[zs]=x;
		spc[x]=1;
	}
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			dfs(l);
		}
	}
}

int main()
{
	long long t,rr,i,k,l,c;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&m);
		for(i=1;i<=n;i++)
		{
			al[i].clear();
			dsu[i]=i;
			vtd[i]=0;
			spc[i]=0;
		}
		for(i=0;i<m;i++)
		{
			scanf("%lld%lld",&k,&l);
			al[k].push_back(l);
			al[l].push_back(k);
			dsu[fd(l)]=fd(k);
		}
		c=0;
		for(i=1;i<=n;i++)
		{
			c+=fd(i)==i;
		}
		if(c>1)
		{
			printf("NO\n");
			continue;
		}
		zs=0;
		dfs(1);
		printf("YES\n%lld\n",zs);
		for(i=1;i<=zs;i++)
		{
			printf("%lld%c",sq[i]," \n"[i==zs]);
		}
	}
}