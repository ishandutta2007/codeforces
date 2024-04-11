#include <bits/stdc++.h>

using namespace std;

long long n;
priority_queue<long long> pq;

int main()
{
	long long i,k,z=0;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		pq.push(-k);
	}
	for(;n>1;)
	{
		k=-pq.top();
		pq.pop();
		n--;
		if(n%2==0)
		{
			k+=-pq.top();
			pq.pop();
			n--;
		}
		k+=-pq.top();
		pq.pop();
		n--;
		z+=k;
		pq.push(-k);
		n++;
	}
	printf("%lld\n",z);
}