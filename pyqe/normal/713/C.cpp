#include <bits/stdc++.h>

using namespace std;

long long n;
priority_queue<long long> pq;

int main()
{
	long long i,ii,k,z=0;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		if(i-1)
		{
			z+=max(pq.top()+i-k,0ll);
		}
		for(ii=0;ii<2;ii++)
		{
			pq.push(k-i);
		}
		pq.pop();
	}
	printf("%lld\n",z);
}