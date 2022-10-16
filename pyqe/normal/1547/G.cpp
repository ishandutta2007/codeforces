#include <bits/stdc++.h>

using namespace std;

long long n,m,sq[400069];
vector<long long> al[400069],al2[400069];
bitset<400069> vtd,vtd2,spc;

void dfs(long long x)
{
	long long i,sz=al[x].size(),l;
	
	spc[x]=1;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!spc[l])
		{
			dfs(l);
		}
	}
}

void dfs2(long long x)
{
	long long i,sz=al2[x].size(),l;
	
	sq[x]=x==1;
	vtd[x]=1;
	vtd2[x]=1;
	for(i=0;i<sz;i++)
	{
		l=al2[x][i];
		if(!vtd[l])
		{
			dfs2(l);
		}
		if(sq[x]==-1||sq[l]==-1||(vtd2[l]&&spc[x]))
		{
			sq[x]=-1;
		}
		else
		{
			sq[x]=min(sq[x]+sq[l],2ll);
		}
	}
	vtd2[x]=0;
}

int main()
{
	long long t,rr,i,k,l;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&m);
		for(i=1;i<=n;i++)
		{
			al[i].clear();
			al2[i].clear();
			vtd[i]=0;
			spc[i]=0;
		}
		for(i=0;i<m;i++)
		{
			scanf("%lld%lld",&k,&l);
			al[k].push_back(l);
			al2[l].push_back(k);
		}
		dfs(1);
		for(i=1;i<=n;i++)
		{
			if(!vtd[i])
			{
				dfs2(i);
			}
			printf("%lld%c",sq[i]," \n"[i==n]);
		}
	}
}