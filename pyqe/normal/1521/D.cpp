#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,dg[100069],zs;
vector<long long> al[100069];
bitset<100069> vtd,spc;
pair<long long,long long> ed[100069];
pair<pair<long long,long long>,pair<long long,long long>> sq[100069];

void dfs(long long x)
{
	long long i,sz=al[x].size(),l;
	vector<long long> v;
	
	vtd[x]=1;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			dfs(l);
			if(spc[l])
			{
				dg[x]--;
				zs++;
				sq[zs].fr={x,l};
			}
			else
			{
				v.push_back(l);
			}
		}
	}
	if(dg[x]>2&&x!=1)
	{
		dg[x]--;
		spc[x]=1;
	}
	sz=v.size();
	for(i=0;i<sz;i++)
	{
		l=v[i];
		if(dg[x]>2)
		{
			dg[x]--;
			dg[l]--;
			zs++;
			sq[zs].fr={x,l};
		}
		else
		{
			m++;
			ed[m]={x,l};
		}
	}
}

long long trv(long long x)
{
	long long i,sz=al[x].size(),l,z=x;
	
	vtd[x]=1;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			z=trv(l);
		}
	}
	return z;
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
			dg[i]=0;
			vtd[i]=0;
			spc[i]=0;
		}
		for(i=0;i<n-1;i++)
		{
			scanf("%lld%lld",&k,&l);
			al[k].push_back(l);
			al[l].push_back(k);
			dg[k]++;
			dg[l]++;
		}
		zs=0;
		m=0;
		dfs(1);
		for(i=1;i<=n;i++)
		{
			al[i].clear();
			dg[i]=0;
			vtd[i]=0;
		}
		for(i=1;i<=m;i++)
		{
			k=ed[i].fr;
			l=ed[i].sc;
			al[k].push_back(l);
			al[l].push_back(k);
			dg[k]++;
			dg[l]++;
		}
		zs=0;
		l=0;
		for(i=1;i<=n;i++)
		{
			if(dg[i]<2&&!vtd[i])
			{
				k=trv(i);
				if(l)
				{
					zs++;
					sq[zs].sc={l,i};
				}
				l=k;
			}
		}
		printf("%lld\n",zs);
		for(i=1;i<=zs;i++)
		{
			printf("%lld %lld %lld %lld\n",sq[i].fr.fr,sq[i].fr.sc,sq[i].sc.fr,sq[i].sc.sc);
		}
	}
}