#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,a[200069],dsu[200069];
pair<long long,pair<long long,long long>> ed[400069];

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
	long long i,k,l,w,mn,e,z=0;
	pair<long long,long long> mne={1e18,-1};
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		mne=min(mne,{a[i],i});
		dsu[i]=i;
	}
	mn=mne.fr;
	e=mne.sc;
	for(i=1;i<=m;i++)
	{
		scanf("%lld%lld%lld",&k,&l,&w);
		ed[i]={w,{k,l}};
	}
	for(i=1;i<=n;i++)
	{
		ed[m+i]={mn+a[i],{e,i}};
	}
	sort(ed+1,ed+m+n+1);
	for(i=1;i<=m+n;i++)
	{
		k=ed[i].sc.fr;
		l=ed[i].sc.sc;
		w=ed[i].fr;
		if(fd(k)!=fd(l))
		{
			z+=w;
			dsu[fd(l)]=fd(k);
		}
	}
	printf("%lld\n",z);
}