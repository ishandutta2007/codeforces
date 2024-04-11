#include <bits/stdc++.h>

using namespace std;

long long n,z=1,dv=998244353;
vector<long long> al[200069];
bitset<200069> vtd;

void dfs(long long x)
{
	long long i,sz=al[x].size(),l,c=0;
	
	vtd[x]=1;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			dfs(l);
			c++;
			z=z*c%dv;
		}
	}
	if(x==1)
	{
		z=z*n%dv;
	}
	else
	{
		z=z*(c+1)%dv;
	}
}

int main()
{
	long long i,k,l;
	
	scanf("%lld",&n);
	for(i=0;i<n-1;i++)
	{
		scanf("%lld%lld",&k,&l);
		al[k].push_back(l);
		al[l].push_back(k);
	}
	dfs(1);
	printf("%lld\n",z);
}