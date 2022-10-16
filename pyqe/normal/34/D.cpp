#include <bits/stdc++.h>

using namespace std;

long long n,rt,rt2,sq[50069];
vector<long long> al[50069];
bitset<50069> vtd;

void dfs(long long x)
{
	long long i,sz=al[x].size(),l;
	
	vtd[x]=1;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			sq[l]=x;
			dfs(l);
		}
	}
}

int main()
{
	long long i,k;
	
	scanf("%lld%lld%lld",&n,&rt,&rt2);
	for(i=1;i<=n;i++)
	{
		if(i!=rt)
		{
			scanf("%lld",&k);
			al[i].push_back(k);
			al[k].push_back(i);
		}
	}
	dfs(rt2);
	for(i=1;i<=n;i++)
	{
		if(i!=rt2)
		{
			printf("%lld%c",sq[i]," \n"[i==n-(rt2==n)]);
		}
	}
}