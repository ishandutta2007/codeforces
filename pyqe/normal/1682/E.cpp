#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,a[200069],od[200069],sq[200069],zs=0;
bitset<200069> vtd;
vector<pair<long long,long long>> al[200069];
vector<long long> al2[200069];

void dfs(long long x)
{
	long long i,sz=al2[x].size(),l;
	
	vtd[x]=1;
	for(i=0;i<sz;i++)
	{
		l=al2[x][i];
		if(!vtd[l])
		{
			dfs(l);
		}
	}
	zs++;
	sq[zs]=x;
}

int main()
{
	long long i,j,ii,k,l,sz,p,p2,c;
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	for(i=1;i<=n;i++)
	{
		if(!vtd[i])
		{
			c=0;
			for(p=i;!vtd[p];p=a[p],c++)
			{
				vtd[p]=1;
				od[p]=c;
			}
		}
	}
	for(i=1;i<=m;i++)
	{
		scanf("%lld%lld",&k,&l);
		for(ii=0;ii<2;ii++)
		{
			al[k].push_back({(od[l]+n-od[k])%n,i});
			swap(k,l);
		}
	}
	for(i=1;i<=n;i++)
	{
		sort(al[i].begin(),al[i].end());
		sz=al[i].size();
		for(j=1;j<sz;j++)
		{
			p=al[i][j].sc;
			p2=al[i][j-1].sc;
			al2[p].push_back(p2);
		}
	}
	vtd.reset();
	for(i=1;i<=m;i++)
	{
		if(!vtd[i])
		{
			dfs(i);
		}
	}
	for(i=1;i<=zs;i++)
	{
		printf("%lld%c",sq[i]," \n"[i==zs]);
	}
}