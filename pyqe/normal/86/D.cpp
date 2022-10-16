#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

const long long sqn=447;
long long n,a[200069],fq[1000069],as[200069],sq[200069];
pair<long long,long long> qq[200069];

bool mos(long long x,long long y)
{
	return mp(qq[x].fr/sqn,qq[x].sc)<mp(qq[y].fr/sqn,qq[y].sc);
}

int main()
{
	long long t,rr,i,k,l,pz,lr[2],p[2]={1,0},z=0;
	
	scanf("%lld%lld",&n,&t);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	for(rr=1;rr<=t;rr++)
	{
		scanf("%lld%lld",&k,&l);
		qq[rr]={k,l};
		as[rr]=rr;
	}
	sort(as+1,as+t+1,mos);
	for(rr=1;rr<=t;rr++)
	{
		pz=as[rr];
		lr[0]=qq[pz].fr;
		lr[1]=qq[pz].sc;
		for(;p[0]>lr[0];)
		{
			p[0]--;
			fq[a[p[0]]]++;
			k=fq[a[p[0]]];
			z+=(k*k-(k-1)*(k-1))*a[p[0]];
		}
		for(;p[1]<lr[1];)
		{
			p[1]++;
			fq[a[p[1]]]++;
			k=fq[a[p[1]]];
			z+=(k*k-(k-1)*(k-1))*a[p[1]];
		}
		for(;p[0]<lr[0];p[0]++)
		{
			fq[a[p[0]]]--;
			k=fq[a[p[0]]];
			z+=(k*k-(k+1)*(k+1))*a[p[0]];
		}
		for(;p[1]>lr[1];p[1]--)
		{
			fq[a[p[1]]]--;
			k=fq[a[p[1]]];
			z+=(k*k-(k+1)*(k+1))*a[p[1]];
		}
		sq[pz]=z;
	}
	for(rr=1;rr<=t;rr++)
	{
		printf("%lld\n",sq[rr]);
	}
}