#include <bits/stdc++.h>

using namespace std;

long long n,nn=1,pr[200069],dg[200069],su[200069];
vector<long long> al[200069];
bitset<200069> vtd;

void dfs(long long x)
{
	long long i,sz=al[x].size(),l;
	
	vtd[x]=1;
	dg[x]=0;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			pr[l]=x;
			dfs(l);
			dg[x]++;
		}
	}
}

int main()
{
	long long i,j,k,l;
	
	scanf("%lld",&n);
	for(i=0;i<n-1;i++)
	{
		scanf("%lld%lld",&k,&l);
		al[k].push_back(l);
		al[l].push_back(k);
	}
	dfs(1);
	vtd.reset();
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		if(vtd[k]||pr[k]!=su[i])
		{
			printf("No\n");
			return 0;
		}
		vtd[k]=1;
		for(j=0;nn<n&&j<dg[k];j++)
		{
			nn++;
			su[nn]=k;
		}
	}
	printf("Yes\n");
}