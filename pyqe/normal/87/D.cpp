#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,nn,dsu[100069],cc[100069],ls[100069],sbt[100069],tg[100069],vl[100069],sq[100069],zs=0,inf=1e18;
pair<long long,long long> ed[100069],as[100069];
vector<pair<long long,long long>> al[100069];
bitset<100069> vtd;

long long fd(long long x)
{
	if(dsu[x]!=x)
	{
		dsu[x]=fd(dsu[x]);
	}
	return dsu[x];
}

void chk(long long x,long long w)
{
	if(ls[x]<w)
	{
		al[x].clear();
		vtd[x]=0;
		ls[x]=w;
	}
}

void dfs(long long x)
{
	long long i,sz=al[x].size(),l,p;
	
	vtd[x]=1;
	sbt[x]=cc[x];
	for(i=0;i<sz;i++)
	{
		l=al[x][i].fr;
		p=al[x][i].sc;
		if(!vtd[l])
		{
			tg[l]=p;
			nn++;
			vl[nn]=l;
			dfs(l);
			sbt[x]+=sbt[l];
		}
	}
}

int main()
{
	long long i,j,r,k,l,w,pz,z=-inf;
	
	scanf("%lld",&n);
	for(i=1;i<=n-1;i++)
	{
		scanf("%lld%lld%lld",&k,&l,&w);
		ed[i]={k,l};
		as[i]={w,i};
	}
	sort(as+1,as+n);
	for(i=1;i<=n;i++)
	{
		dsu[i]=i;
		cc[i]=1;
	}
	for(j=1,i=1;i<=n-1;i++)
	{
		w=as[i].fr;
		pz=as[i].sc;
		k=fd(ed[pz].fr);
		l=fd(ed[pz].sc);
		chk(k,w);
		chk(l,w);
		al[k].push_back({l,pz});
		al[l].push_back({k,pz});
		if(i==n-1||as[i+1].fr>w)
		{
			for(;j<=i;j++)
			{
				pz=as[j].sc;
				k=fd(ed[pz].fr);
				l=fd(ed[pz].sc);
				if(!vtd[k])
				{
					nn=0;
					dfs(k);
					for(r=1;r<=nn;r++)
					{
						w=sbt[vl[r]]*(sbt[k]-sbt[vl[r]])*2;
						if(w>z)
						{
							z=w;
							zs=0;
						}
						if(w==z)
						{
							zs++;
							sq[zs]=tg[vl[r]];
						}
					}
				}
				cc[k]+=cc[l];
				dsu[l]=k;
			}
		}
	}
	sort(sq+1,sq+zs+1);
	printf("%lld %lld\n",z,zs);
	for(i=1;i<=zs;i++)
	{
		printf("%lld%c",sq[i]," \n"[i==zs]);
	}
}