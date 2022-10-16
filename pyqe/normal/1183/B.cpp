#include <bits/stdc++.h>

using namespace std;

long long n,d;

int main()
{
	long long t,rr,i,k,mn,mx;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		mn=1e18;
		mx=-1e18;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&k);
			mn=min(mn,k);
			mx=max(mx,k);
		}
		if(mn+d>=mx-d)
		{
			printf("%lld\n",mn+d);
		}
		else
		{
			printf("-1\n");
		}
	}
}