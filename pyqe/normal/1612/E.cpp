#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

const long long ma=2e5,mm=20;
long long n,a[200069],wg[200069],ps[200069];
pair<long long,long long> as[200069];

inline void rbd(long long x)
{
	long long i;
	
	for(i=1;i<=ma;i++)
	{
		as[i]={0,i};
	}
	for(i=1;i<=n;i++)
	{
		as[a[i]].fr+=min(wg[i],x);
	}
	sort(as+1,as+ma+1,greater<pair<long long,long long>>());
	for(i=1;i<=ma;i++)
	{
		ps[i]=ps[i-1]+as[i].fr;
	}
}

inline bool cmp(pair<long long,long long> x,pair<long long,long long> y)
{
	return x.fr*y.sc<y.fr*x.sc;
}

int main()
{
	long long i,e;
	pair<long long,long long> z={0,1};
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld%lld",a+i,wg+i);
	}
	for(i=1;i<=ma;i++)
	{
		if(i<=mm)
		{
			rbd(i);
		}
		if(cmp(z,{ps[i],i}))
		{
			z={ps[i],i};
		}
	}
	e=z.sc;
	rbd(e);
	printf("%lld\n",e);
	for(i=1;i<=e;i++)
	{
		printf("%lld%c",as[i].sc," \n"[i==e]);
	}
}