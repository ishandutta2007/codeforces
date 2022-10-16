#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,sq[200069],zs;
pair<long long,long long> as[200069];

int main()
{
	long long t,rr,i,k,sm,mx;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&k);
			as[i]={k,i};
		}
		sort(as+1,as+n+1);
		sm=0;
		mx=0;
		for(i=1;i<n;i++)
		{
			sm+=as[i].fr;
			if(sm<as[i+1].fr)
			{
				mx=i;
			}
		}
		zs=0;
		for(i=mx+1;i<=n;i++)
		{
			zs++;
			sq[zs]=as[i].sc;
		}
		sort(sq+1,sq+zs+1);
		printf("%lld\n",zs);
		for(i=1;i<=zs;i++)
		{
			printf("%lld%c",sq[i]," \n"[i==zs]);
		}
	}
}