#include <bits/stdc++.h>

using namespace std;

long long n,ttl,a[200069];
priority_queue<long long> pq;

int main()
{
	long long t,rr,i,k,p;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		ttl=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
			ttl+=a[i];
		}
		sort(a+1,a+n+1,greater<long long>());
		pq.push(ttl);
		for(p=1,i=0;!pq.empty()&&i<n*2-1;i++)
		{
			k=pq.top();
			if(p<=n&&k==a[p])
			{
				pq.pop();
				p++;
			}
			else if(p<=n&&k<a[p])
			{
				break;
			}
			else
			{
				pq.pop();
				pq.push(k/2);
				pq.push((k+1)/2);
			}
		}
		if(pq.empty())
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
			for(;!pq.empty();pq.pop());
		}
	}
}