#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,a[150069],sq[150069],zs=0;
priority_queue<pair<long long,long long>> pq;

int main()
{
	long long i,k,l=0,w,p=0;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		pq.push({-k,-i});
	}
	for(;!pq.empty();)
	{
		w=-pq.top().fr;
		k=-pq.top().sc;
		pq.pop();
		if(w==l)
		{
			pq.push({-w*2,-k});
			l=0;
			p=0;
		}
		else
		{
			a[p]=l;
			l=w;
			p=k;
		}
	}
	if(l)
	{
		a[p]=l;
	}
	for(i=1;i<=n;i++)
	{
		if(a[i])
		{
			zs++;
			sq[zs]=a[i];
		}
	}
	printf("%lld\n",zs);
	for(i=1;i<=zs;i++)
	{
		printf("%lld%c",sq[i]," \n"[i==zs]);
	}
}