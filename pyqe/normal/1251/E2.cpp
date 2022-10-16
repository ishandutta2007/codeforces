#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n;
pair<long long,long long> a[200069];
priority_queue<long long> pq;

int main()
{
	long long t,rr,i,c,k,w,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=0;i<n;i++)
		{
			scanf("%lld%lld",&a[i].fr,&a[i].sc);
		}
		sort(a,a+n,greater<pair<long long,long long>>());
		z=0;
		c=0;
		for(i=0;i<n;i++)
		{
			k=a[i].fr;
			w=a[i].sc;
			pq.push(-w);
			c++;
			if(c>n-k)
			{
				z-=pq.top();
				pq.pop();
				c--;
			}
		}
		for(;!pq.empty();)
		{
			pq.pop();
		}
		printf("%lld\n",z);
	}
}