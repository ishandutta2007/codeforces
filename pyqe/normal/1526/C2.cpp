#include <bits/stdc++.h>

using namespace std;

long long n;
priority_queue<long long> pq;

int main()
{
	long long i,k,sm=0,z=0;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		pq.push(-k);
		z++;
		sm+=k;
		if(sm<0)
		{
			sm+=pq.top();
			pq.pop();
			z--;
		}
	}
	printf("%lld\n",z);
}