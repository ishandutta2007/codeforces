#include <bits/stdc++.h>

using namespace std;

long long n,z=0;
vector<long long> al[200069];
bitset<200069> vtd,spc;

void dfs(long long x)
{
	long long i,sz=al[x].size(),l,c=0;
	
	vtd[x]=1;
	spc[x]=0;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			dfs(l);
			c+=!spc[l];
		}
	}
	if(x==1)
	{
		z+=max(c,1ll);
	}
	else if(c)
	{
		z+=c-1;
		spc[x]=1;
	}
}

int main()
{
	long long t,rr,i,k,l;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			al[i].clear();
			vtd[i]=0;
		}
		for(i=0;i<n-1;i++)
		{
			scanf("%lld%lld",&k,&l);
			al[k].push_back(l);
			al[l].push_back(k);
		}
		z=0;
		dfs(1);
		printf("%lld\n",z);
	}
}