#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,a[200069];
priority_queue<pair<long long,long long>> pq;

int main()
{
	long long i,k,w,tg,z=0;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++)
	{
		if(i>1&&a[i]==a[i-1])
		{
			continue;
		}
		if(!pq.empty())
		{
			for(;1;)
			{
				w=-pq.top().fr;
				k=pq.top().sc;
				tg=a[i]/k*k;
				if(w==tg)
				{
					break;
				}
				pq.pop();
				pq.push({-tg,k});
			}
			z=max(z,a[i]+pq.top().fr);
		}
		pq.push({-a[i],a[i]});
	}
	printf("%lld\n",z);
}