#include <bits/stdc++.h>

using namespace std;

const long long inf=1e18;
long long n,d,a[200069];

inline long long dvd(long long x,long long y)
{
	return x/y-(x%y<0);
}

int main()
{
	long long t,rr,i,sm,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
		}
		sort(a+1,a+n+1);
		sm=0;
		z=inf;
		for(i=1;i<=n;i++)
		{
			sm+=a[i];
			z=min(z,max(a[1]-dvd(d-(sm-a[1]),n-i+1),0ll)+n-i);
		}
		printf("%lld\n",z);
	}
}