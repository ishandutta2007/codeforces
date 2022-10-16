#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m;
vector<long long> al[200069];
pair<long long,long long> ed[200069];
bitset<200069> vtd,sq;

void dfs(long long x)
{
	long long i,sz=al[x].size(),l;
	
	vtd[x]=1;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			sq[l]=!sq[x];
			dfs(l);
		}
		else if(sq[l]==sq[x])
		{
			printf("NO\n");
			exit(0);
		}
	}
}

int main()
{
	long long i,k,l;
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=m;i++)
	{
		scanf("%lld%lld",&k,&l);
		al[k].push_back(l);
		al[l].push_back(k);
		ed[i]={k,l};
	}
	dfs(1);
	printf("YES\n");
	for(i=1;i<=m;i++)
	{
		k=ed[i].fr;
		printf("%d",(bool)sq[k]);
	}
	printf("\n");
}