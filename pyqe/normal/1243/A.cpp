#include <bits/stdc++.h>

using namespace std;

long long n,a[100069];

int main()
{
	long long t,rr,i,mx;
	bool bad;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
		}
		sort(a+1,a+n+1,greater<long long>());
		mx=-1e18;
		for(i=1;i<=n;i++)
		{
			mx=max(mx,min(i,a[i]));
		}
		printf("%lld\n",mx);
	}
}