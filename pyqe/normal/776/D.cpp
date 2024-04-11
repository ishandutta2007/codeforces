#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m;
vector<long long> el[100069];
vector<pair<long long,long long>> al[100069];
bitset<100069> a,vtd,sq;

void dfs(long long x)
{
	long long i,sz=al[x].size(),l,ww;
	
	vtd[x]=1;
	for(i=0;i<sz;i++)
	{
		l=al[x][i].fr;
		ww=al[x][i].sc;
		if(!vtd[l])
		{
			sq[l]=sq[x]^ww;
			dfs(l);
		}
		else if(sq[l]!=sq[x]^ww)
		{
			printf("NO\n");
			exit(0);
		}
	}
}

int main()
{
	long long i,j,k,l,mm;
	
	scanf("%lld%lld",&m,&n);
	for(i=1;i<=m;i++)
	{
		scanf("%lld",&k);
		a[i]=!k;
	}
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&mm);
		for(j=0;j<mm;j++)
		{
			scanf("%lld",&k);
			el[k].push_back(i);
		}
	}
	for(i=1;i<=m;i++)
	{
		k=el[i][0];
		l=el[i][1];
		al[k].push_back({l,a[i]});
		al[l].push_back({k,a[i]});
	}
	for(i=1;i<=n;i++)
	{
		if(!vtd[i])
		{
			dfs(i);
		}
	}
	printf("YES\n");
}