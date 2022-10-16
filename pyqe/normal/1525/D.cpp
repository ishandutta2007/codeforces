#include <bits/stdc++.h>

using namespace std;

long long n,ps[100069];
priority_queue<long long> pq;

int main()
{
	long long i,ii,k,z=0;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		ps[i]=ps[i-1]+!k*2-1;
	}
	for(i=1;i<=n;i++)
	{
		k=min(max(ps[i],0ll),ps[n]);
		z+=abs(ps[i]-k);
		if(i-1)
		{
			z+=max(pq.top()-k,0ll);
		}
		for(ii=0;ii<2;ii++)
		{
			pq.push(k);
		}
		pq.pop();
	}
	printf("%lld\n",z);
}