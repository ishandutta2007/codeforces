#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,rt,a[1069],dg[1069],lf[1069],sr[1069],lf2[1069],zs=0;
vector<pair<long long,long long>> al[1069];
bitset<1069> vtd;
pair<pair<long long,long long>,long long> sq[100069];

void bd(long long x)
{
	long long i,sz=al[x].size(),l,w;
	
	vtd[x]=1;
	lf[x]=x;
	sr[x]=x;
	for(i=0;i<sz;i++)
	{
		l=al[x][i].fr;
		w=al[x][i].sc;
		if(!vtd[l])
		{
			a[l]=w;
			bd(l);
			lf2[x]=lf[x];
			lf[x]=lf[l];
			sr[x]=l;
			al[x][i].sc=lf[l];
		}
	}
}

void dfs(long long x,long long w)
{
	long long i,j,sz=al[x].size(),l,tg[3],ww;
	
	vtd[x]=1;
	for(i=0;i<sz;i++)
	{
		l=al[x][i].fr;
		if(vtd[l])
		{
			if(sr[l]!=x)
			{
				lf2[x]=lf[l];
			}
			else
			{
				lf2[x]=lf2[l];
			}
			al[x][i].sc=lf2[x];
		}
	}
	for(i=0;i<sz;i++)
	{
		l=al[x][i].fr;
		if(!vtd[l])
		{
			ww=a[l]-w*(l==sr[x]);
			if(dg[x]>=3)
			{
				for(j=0;j<3;j++)
				{
					tg[j]=al[x][(i+j)%sz].sc;
				}
				for(j=0;j<3;j++)
				{
					zs++;
					sq[zs]={{tg[j],tg[(j+2)%3]},ww/2*((j<2)*2-1)};
				}
			}
			else if(dg[x]==1)
			{
				zs++;
				sq[zs]={{x,lf[l]},ww};
			}
			dfs(l,a[l]);
		}
	}
}

int main()
{
	long long i,k,l,w;
	
	scanf("%lld",&n);
	for(i=0;i<n-1;i++)
	{
		scanf("%lld%lld%lld",&k,&l,&w);
		al[k].push_back({l,w});
		al[l].push_back({k,w});
		dg[k]++;
		dg[l]++;
	}
	for(i=1;i<=n;i++)
	{
		if(dg[i]==2)
		{
			if(al[i][0].sc!=al[i][1].sc)
			{
				printf("NO\n");
				return 0;
			}
		}
		else
		{
			rt=i;
		}
	}
	bd(rt);
	vtd.reset();
	dfs(rt,0);
	printf("YES\n%lld\n",zs);
	for(i=1;i<=zs;i++)
	{
		k=sq[i].fr.fr;
		l=sq[i].fr.sc;
		w=sq[i].sc;
		printf("%lld %lld %lld\n",k,l,w);
	}
}