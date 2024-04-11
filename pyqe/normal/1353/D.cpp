#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,sq[200069];
priority_queue<pair<long long,long long>> pq;

void ad(long long x,long long y)
{
	if(y)
	{
		pq.push({y,-x});
	}
}

int main()
{
	long long t,rr,i,k,w;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		pq.push({n,-n});
		for(i=1;!pq.empty();i++)
		{
			k=-pq.top().sc;
			w=pq.top().fr;
			pq.pop();
			sq[k-w/2]=i;
			ad(k,w/2);
			ad(k-w/2-1,w-w/2-1);
		}
		for(i=1;i<=n;i++)
		{
			printf("%lld%c",sq[i]," \n"[i==n]);
		}
	}
}