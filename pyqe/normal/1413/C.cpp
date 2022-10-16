#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,d=6,a[6],od[100069],inf=1e18;
priority_queue<pair<long long,long long>> pq;

int main()
{
	long long i,k,l,mn=inf,z=inf;
	
	for(i=0;i<d;i++)
	{
		scanf("%lld",a+i);
	}
	sort(a,a+d);
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		pq.push({k-a[0],i});
		mn=min(mn,k-a[0]);
	}
	for(;1;)
	{
		k=pq.top().fr;
		l=pq.top().sc;
		pq.pop();
		z=min(z,k-mn);
		od[l]++;
		if(od[l]==d)
		{
			break;
		}
		k+=a[od[l]-1]-a[od[l]];
		pq.push({k,l});
		mn=min(mn,k);
	}
	printf("%lld\n",z);
}