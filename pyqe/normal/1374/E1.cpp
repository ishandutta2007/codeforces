#include <bits/stdc++.h>

using namespace std;

long long n,d,inf=1e18;
priority_queue<long long> pq[4];

long long val(long long x)
{
	if(!pq[x].empty())
	{
		return -pq[x].top();
	}
	else
	{
		return inf;
	}
}

void ers(long long x)
{
	if(!pq[x].empty())
	{
		pq[x].pop();
	}
}

int main()
{
	long long i,k,w,mk,z=0;
	
	scanf("%lld%lld",&n,&d);
	for(i=0;i<n;i++)
	{
		scanf("%lld%lld",&w,&k);
		mk=k*2;
		scanf("%lld",&k);
		mk|=k;
		pq[mk].push(-w);
	}
	for(i=0;i<d;i++)
	{
		if(val(3)<=val(1)+val(2))
		{
			z+=val(3);
			ers(3);
		}
		else
		{
			z+=val(1)+val(2);
			ers(1);
			ers(2);
		}
		if(z>=inf)
		{
			printf("-1\n");
			return 0;
		}
	}
	printf("%lld\n",z);
}