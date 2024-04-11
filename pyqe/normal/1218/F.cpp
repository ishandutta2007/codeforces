#include <bits/stdc++.h>

using namespace std;

long long n,d,m,a[100069],c[100069];
priority_queue<long long> pq;

int main()
{
	long long i,z=0;
	
	scanf("%lld%lld",&n,&d);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	scanf("%lld",&m);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",c+i);
	}
	for(i=1;i<=n;i++)
	{
		pq.push(-c[i]);
		for(;d<a[i];pq.pop())
		{
			if(pq.empty())
			{
				printf("-1\n");
				return 0;
			}
			z+=-pq.top();
			d+=m;
		}
	}
	printf("%lld\n",z);
}