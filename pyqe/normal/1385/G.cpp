#include <bits/stdc++.h>
 
using namespace std;
 
#define mp make_pair
#define fr first
#define sc second
 
long long n,nn[2],fq[200069],vl[200069][2],av[2][200069],sq[200069],zs;
bitset<200069> xr,vtd,nr;
vector<pair<long long,long long>> al[200069];
 
void dfs(long long x)
{
	long long i,sz=al[x].size(),l,w;
	
	vtd[x]=1;
	nn[nr[x]]++;
	av[nr[x]][nn[nr[x]]]=x;
	for(i=0;i<sz;i++)
	{
		l=al[x][i].fr;
		w=al[x][i].sc;
		if(!vtd[l])
		{
			nr[l]=nr[x]^w;
			dfs(l);
		}
	}
}
 
int main()
{
	long long t,rr,i,j,ii,e,k;
	bool bad;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			fq[i]=0;
			xr[i]=0;
			al[i].clear();
			vtd[i]=0;
		}
		bad=0;
		for(ii=0;ii<2;ii++)
		{
			for(i=1;i<=n;i++)
			{
				scanf("%lld",&k);
				if(fq[k]<2)
				{
					vl[k][fq[k]]=i;
					xr[k]=xr[k]^ii;
					fq[k]++;
				}
				else
				{
					bad=1;
				}
			}
		}
		if(bad)
		{
			printf("-1\n");
			continue;
		}
		for(i=1;i<=n;i++)
		{
			for(ii=0;ii<2;ii++)
			{
				al[vl[i][ii]].push_back({vl[i][!ii],!xr[i]});
			}
		}
		zs=0;
		for(i=1;i<=n;i++)
		{
			if(!vtd[i])
			{
				for(ii=0;ii<2;ii++)
				{
					nn[ii]=0;
				}
				dfs(i);
				e=nn[1]<nn[0];
				for(j=1;j<=nn[e];j++)
				{
					zs++;
					sq[zs]=av[e][j];
				}
			}
		}
		printf("%lld\n",zs);
		for(i=1;i<=zs;i++)
		{
			printf("%lld%c",sq[i]," \n"[i==zs]);
		}
	}
}