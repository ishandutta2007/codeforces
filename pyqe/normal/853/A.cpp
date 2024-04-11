#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,d,a[300069],sq[300069];
priority_queue<pair<long long,long long>> pq;

int main()
{
	long long i,k,l,z=0;
	
	scanf("%lld%lld",&n,&d);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	for(i=1;i<=min(d,n);i++)
	{
		pq.push({a[i],i});
	}
	for(i=1;i<=n;i++)
	{
		if(d+i<=n)
		{
			pq.push({a[d+i],d+i});
		}
		k=pq.top().fr;
		l=pq.top().sc;
		pq.pop();
		z+=k*(d+i-l);
		sq[l]=d+i;
	}
	printf("%lld\n",z);
	for(i=1;i<=n;i++)
	{
		printf("%lld%c",sq[i]," \n"[i==n]);
	}
}