#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,dsu[400069],cc[400069],ps[400069],sq[200069];
pair<long long,bool> a[400069];
pair<long long,long long> as[400069],qq[200069];

long long fd(long long x)
{
	if(dsu[x]!=x)
	{
		dsu[x]=fd(dsu[x]);
	}
	return dsu[x];
}

inline long long val(long long x)
{
	x=fd(x);
	return ps[x]-ps[x-cc[x]];
}

int main()
{
	long long t,rr,i,k,l,pz,z=0;
	
	scanf("%lld%lld%lld",&n,&m,&t);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		a[i]={k,1};
		z+=k;
	}
	for(i=1;i<=m;i++)
	{
		scanf("%lld",&k);
		a[n+i]={k,0};
	}
	sort(a+1,a+n+m+1);
	for(i=1;i<n+m;i++)
	{
		as[i]={a[i+1].fr-a[i].fr,i};
	}
	sort(as+1,as+n+m);
	for(i=1;i<=n+m;i++)
	{
		dsu[i]=i;
		cc[i]=a[i].sc;
		ps[i]=ps[i-1]+a[i].fr;
	}
	for(rr=1;rr<=t;rr++)
	{
		scanf("%lld",&k);
		qq[rr]={k,rr};
	}
	sort(qq+1,qq+t+1);
	for(i=1,rr=1;rr<=t;rr++)
	{
		k=qq[rr].fr;
		pz=qq[rr].sc;
		for(;i<n+m&&as[i].fr<=k;i++)
		{
			l=as[i].sc;
			z-=val(l)+val(l+1);
			cc[fd(l+1)]+=cc[fd(l)];
			dsu[fd(l)]=fd(l+1);
			z+=val(l);
		}
		sq[pz]=z;
	}
	for(rr=1;rr<=t;rr++)
	{
		printf("%lld\n",sq[rr]);
	}
}