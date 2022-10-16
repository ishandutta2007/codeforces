#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,a[300069];
bitset<300069> vtd;
deque<pair<long long,long long>> dq;

bool chk(long long x)
{
	long long i,k;
	
	for(i=1;i<=n-x+1;i++)
	{
		vtd[i]=0;
	}
	for(;!dq.empty();dq.pop_front());
	for(i=1;i<=n;i++)
	{
		for(;!dq.empty()&&dq.back().sc>=a[i];dq.pop_back());
		dq.push_back({i,a[i]});
		for(;dq.front().fr<i-x+1;dq.pop_front());
		if(i>=x)
		{
			k=dq.front().sc;
			if(k>n-x+1||vtd[k])
			{
				return 0;
			}
			vtd[k]=1;
		}
	}
	return 1;
}

int main()
{
	long long t,rr,i,lh,rh,md,zz;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
		}
		zz=n+1;
		for(lh=2,rh=n;lh<=rh;)
		{
			md=(lh+rh)/2;
			if(chk(md))
			{
				zz=md;
				rh=md-1;
			}
			else
			{
				lh=md+1;
			}
		}
		printf("%lld",(long long)chk(1));
		for(i=2;i<=n;i++)
		{
			printf("%lld",(long long)(i>=zz));
		}
		printf("\n");
	}
}