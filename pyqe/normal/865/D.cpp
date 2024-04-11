#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n;
priority_queue<pair<long long,long long>> pq;

int main()
{
	long long i,k,l,w,z=0;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		pq.push({-k,0});
		l=-pq.top().fr;
		w=pq.top().sc;
		pq.pop();
		z+=k-l;
		if(!w)
		{
			pq.push({-l,1});
		}
	}
	printf("%lld\n",z);
}