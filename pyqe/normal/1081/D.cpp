#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,d,dsu[100069];
pair<long long,pair<long long,long long>> ed[100069];
bitset<100069> spc;

long long fd(long long x)
{
	if(dsu[x]!=x)
	{
		dsu[x]=fd(dsu[x]);
	}
	return dsu[x];
}

int main()
{
	long long i,k,l,w,z=-1e18;
	
	scanf("%lld%lld%lld",&n,&m,&d);
	for(i=0;i<d;i++)
	{
		scanf("%lld",&k);
		spc[k]=1;
	}
	for(i=1;i<=m;i++)
	{
		scanf("%lld%lld%lld",&k,&l,&w);
		ed[i]={w,{k,l}};
	}
	sort(ed+1,ed+m+1);
	for(i=1;i<=n;i++)
	{
		dsu[i]=i;
	}
	for(i=1;i<=m;i++)
	{
		k=ed[i].sc.fr;
		l=ed[i].sc.sc;
		w=ed[i].fr;
		if(!spc[fd(k)])
		{
			swap(k,l);
		}
		if(fd(k)!=fd(l)&&spc[fd(k)]&&spc[fd(l)])
		{
			z=max(z,w);
		}
		dsu[fd(l)]=fd(k);
	}
	for(i=0;i<d;i++)
	{
		printf("%lld%c",z," \n"[i==d-1]);
	}
}