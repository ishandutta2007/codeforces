#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,sbt[200069],z,sq[200069],zs,inf=1e18;
vector<pair<long long,long long>> al[200069];
bitset<200069> vtd;

void bd(long long x)
{
	long long i,sz=al[x].size(),l,w;
	
	vtd[x]=1;
	for(i=0;i<sz;i++)
	{
		l=al[x][i].fr;
		w=al[x][i].sc;
		if(!vtd[l])
		{
			bd(l);
			sbt[x]+=sbt[l]+w;
		}
	}
}

void trv(long long x,long long w)
{
	long long i,sz=al[x].size(),l,ww;
	
	vtd[x]=1;
	if(w<z)
	{
		z=w;
		zs=0;
	}
	if(w==z)
	{
		zs++;
		sq[zs]=x;
	}
	for(i=0;i<sz;i++)
	{
		l=al[x][i].fr;
		ww=al[x][i].sc;
		if(!vtd[l])
		{
			trv(l,w+!ww*2-1);
		}
	}
}

int main()
{
	long long i,k,l;
	
	scanf("%lld",&n);
	for(i=0;i<n-1;i++)
	{
		scanf("%lld%lld",&k,&l);
		al[k].push_back({l,0});
		al[l].push_back({k,1});
	}
	bd(1);
	vtd.reset();
	z=inf;
	trv(1,sbt[1]);
	sort(sq+1,sq+zs+1);
	printf("%lld\n",z);
	for(i=1;i<=zs;i++)
	{
		printf("%lld%c",sq[i]," \n"[i==zs]);
	}
}