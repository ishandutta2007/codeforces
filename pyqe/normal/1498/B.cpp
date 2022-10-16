#include <bits/stdc++.h>

using namespace std;

long long n,d,a[100069];
priority_queue<long long> pq;

int main()
{
	long long t,rr,i,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
		}
		sort(a+1,a+n+1,greater<long long>());
		for(;!pq.empty();pq.pop());
		z=0;
		for(i=1;i<=n;i++)
		{
			if(pq.empty()||pq.top()<a[i])
			{
				z++;
				pq.push(d);
			}
			pq.push(pq.top()-a[i]);
			pq.pop();
		}
		printf("%lld\n",z);
	}
}