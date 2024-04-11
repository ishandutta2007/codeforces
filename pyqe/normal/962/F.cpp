#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,dsu[100069],dis[100069],cdis=0,pc[100069],ls[100069],sq[100069],zs=0;
pair<long long,long long> ed[100069];
vector<pair<long long,long long>> al[100069];
bitset<100069> vtd,vtd2;
pair<long long,long long> mds[100069];
vector<long long> cc[100069];

long long fd(long long x)
{
	if(dsu[x]!=x)
	{
		dsu[x]=fd(dsu[x]);
	}
	return dsu[x];
}

void bct(long long x,long long ls)
{
	long long i,sz=al[x].size(),l,p;
	
	vtd[x]=1;
	vtd2[x]=1;
	dis[x]=cdis;
	mds[x]={cdis,-1};
	cdis++;
	for(i=0;i<sz;i++)
	{
		l=al[x][i].fr;
		p=al[x][i].sc;
		if(p==ls)
		{
			continue;
		}
		if(!vtd[l])
		{
			pc[x]=p;
			bct(l,p);
		}
		if(vtd2[l])
		{
			dsu[fd(p)]=fd(pc[l]);
			mds[x]=min(mds[x],{dis[l],p});
		}
		else if(mds[l].fr<=dis[x])
		{
			dsu[fd(p)]=fd(mds[l].sc);
			mds[x]=min(mds[x],{mds[l].fr,p});
		}
	}
	cdis--;
	vtd2[x]=0;
}

int main()
{
	long long i,j,ii,k,l,p[2],sz,c;
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=m;i++)
	{
		scanf("%lld%lld",&k,&l);
		ed[i]={k,l};
		al[k].push_back({l,i});
		al[l].push_back({k,i});
		dsu[i]=i;
	}
	for(i=1;i<=n;i++)
	{
		if(!vtd[i])
		{
			bct(i,0);
		}
	}
	for(i=1;i<=m;i++)
	{
		cc[fd(i)].push_back(i);
	}
	for(i=1;i<=m;i++)
	{
		sz=cc[i].size();
		c=0;
		for(j=0;j<sz;j++)
		{
			k=cc[i][j];
			p[0]=ed[k].fr;
			p[1]=ed[k].sc;
			for(ii=0;ii<2;ii++)
			{
				c+=ls[p[ii]]<i;
				ls[p[ii]]=i;
			}
		}
		if(c==sz)
		{
			for(j=0;j<sz;j++)
			{
				k=cc[i][j];
				zs++;
				sq[zs]=k;
			}
		}
	}
	sort(sq+1,sq+zs+1);
	printf("%lld\n",zs);
	for(i=1;i<=zs;i++)
	{
		printf("%lld%c",sq[i]," \n"[i==zs]);
	}
}