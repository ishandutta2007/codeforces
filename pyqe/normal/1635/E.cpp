#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,nn=0,sq[200069];
vector<pair<long long,bool>> al[200069];
bitset<200069> vtd,kd,vtd2;
vector<long long> al2[200069];

void dfs(long long x)
{
	long long i,sz=al[x].size(),l,e;
	
	vtd[x]=1;
	for(i=0;i<sz;i++)
	{
		l=al[x][i].fr;
		e=al[x][i].sc;
		if(!vtd[l])
		{
			kd[l]=!kd[x];
			dfs(l);
		}
		else if(kd[l]==kd[x])
		{
			printf("NO\n");
			exit(0);
		}
		if(kd[x]^e)
		{
			al2[x].push_back(l);
		}
	}
}

void dfs2(long long x)
{
	long long i,sz=al2[x].size(),l;
	
	vtd[x]=1;
	vtd2[x]=1;
	for(i=0;i<sz;i++)
	{
		l=al2[x][i];
		if(!vtd[l])
		{
			dfs2(l);
		}
		else if(vtd2[l])
		{
			printf("NO\n");
			exit(0);
		}
	}
	vtd2[x]=0;
	nn++;
	sq[x]=nn;
}

int main()
{
	long long i,ky,k,l;
	
	scanf("%lld%lld",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld%lld",&ky,&k,&l);
		al[k].push_back({l,ky-1});
		al[l].push_back({k,ky-1});
	}
	for(i=1;i<=n;i++)
	{
		if(!vtd[i])
		{
			dfs(i);
		}
	}
	vtd.reset();
	for(i=1;i<=n;i++)
	{
		if(!vtd[i])
		{
			dfs2(i);
		}
	}
	printf("YES\n");
	for(i=1;i<=n;i++)
	{
		printf("%c %lld\n","LR"[kd[i]],sq[i]);
	}
}