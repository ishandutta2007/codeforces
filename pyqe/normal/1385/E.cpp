#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,nn,pst[200069];
pair<long long,long long> ed[200069];
vector<long long> al[200069];
bitset<200069> vtd,vtd2;
bool r0;

void dfs(long long x)
{
	long long i,sz=al[x].size(),l;
	
	vtd[x]=1;
	vtd2[x]=1;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			dfs(l);
		}
		else if(vtd2[l])
		{
			r0=1;
		}
		if(r0)
		{
			return;
		}
	}
	vtd2[x]=0;
	nn++;
	pst[x]=nn;
}

int main()
{
	long long t,rr,i,ky,k,l;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&m);
		for(i=1;i<=n;i++)
		{
			al[i].clear();
			vtd[i]=0;
			vtd2[i]=0;
		}
		for(i=1;i<=m;i++)
		{
			scanf("%lld%lld%lld",&ky,&k,&l);
			ed[i]={k,l};
			if(ky)
			{
				al[k].push_back(l);
			}
		}
		nn=0;
		r0=0;
		for(i=1;i<=n;i++)
		{
			if(!vtd[i])
			{
				dfs(i);
			}
		}
		if(r0)
		{
			printf("NO\n");
		}
		else
		{
			printf("YES\n");
			for(i=1;i<=m;i++)
			{
				k=ed[i].fr;
				l=ed[i].sc;
				if(pst[k]<pst[l])
				{
					swap(k,l);
				}
				printf("%lld %lld\n",k,l);
			}
		}
	}
}