#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,d;
pair<long long,long long> a[300069];
priority_queue<long long> pq;

int main()
{
	long long i,k,l,z=0,b=0;
	
	scanf("%lld%lld",&n,&d);
	for(i=0;i<n;i++)
	{
		scanf("%lld%lld",&a[i].sc,&a[i].fr);
	}
	sort(a,a+n,greater<pair<long long,long long>>());
	for(i=0;i<n;i++)
	{
		k=a[i].fr;
		l=a[i].sc;
		pq.push(-l);
		z+=l;
		if(i>=d)
		{
			z+=pq.top();
			pq.pop();
		}
		b=max(b,z*k);
	}
	printf("%lld\n",b);
}