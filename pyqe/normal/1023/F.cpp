#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,d,dsu[500069],pr[500069],dh[500069];
vector<pair<long long,bool>> al[500069];
pair<pair<long long,long long>,long long> qq[500069];
bitset<500069> vtd,spc;

long long fd(long long x)
{
	if(dsu[x]!=x)
	{
		dsu[x]=fd(dsu[x]);
	}
	return dsu[x];
}

void bd(long long x)
{
	long long i,sz=al[x].size(),l,e;
	
	vtd[x]=1;
	for(i=0;i<sz;i++)
	{
		l=al[x][i].fr;
		e=al[x][i].sc;
		if(!vtd[l])
		{
			pr[l]=x;
			dh[l]=dh[x]+1;
			spc[l]=e;
			bd(l);
		}
	}
}

int main()
{
	long long i,k,l,w,c=0,z=0;
	
	scanf("%lld%lld%lld",&n,&m,&d);
	for(i=1;i<=n;i++)
	{
		dsu[i]=i;
	}
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld",&k,&l);
		al[k].push_back({l,0});
		al[l].push_back({k,0});
		dsu[fd(l)]=fd(k);
	}
	for(i=1;i<=d;i++)
	{
		scanf("%lld%lld%lld",&k,&l,&w);
		if(fd(k)!=fd(l))
		{
			al[k].push_back({l,1});
			al[l].push_back({k,1});
			dsu[fd(l)]=fd(k);
		}
		qq[i]={{k,l},w};
	}
	bd(1);
	for(i=1;i<=n;i++)
	{
		dsu[i]=i;
	}
	c=n;
	for(i=1;i<=d;i++)
	{
		k=qq[i].fr.fr;
		l=qq[i].fr.sc;
		w=qq[i].sc;
		for(;fd(k)!=fd(l);)
		{
			if(dh[fd(k)]<dh[fd(l)])
			{
				swap(k,l);
			}
			z+=w*!spc[fd(k)];
			dsu[fd(k)]=fd(pr[fd(k)]);
			c--;
		}
	}
	if(c>1)
	{
		z=-1;
	}
	printf("%lld\n",z);
}