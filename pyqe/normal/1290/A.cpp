#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,d,a[100069];
deque<pair<long long,long long>> dq;

int main()
{
	long long t,rr,i,k,mx;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld",&n,&m,&d);
		d=min(d,m-1);
		mx=-1e18;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
			if(i>=n-m+1)
			{
				k=max(a[i],a[i-n+m]);
				for(;!dq.empty()&&k<=dq.back().fr;dq.pop_back());
				dq.push_back({k,i});
				if(i>=n-d)
				{
					for(;dq.front().sc<i-m+1+d;dq.pop_front());
					mx=max(mx,dq.front().fr);
				}
			}
		}
		for(;!dq.empty();dq.pop_front());
		printf("%lld\n",mx);
	}
}