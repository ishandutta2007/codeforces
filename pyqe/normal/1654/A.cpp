#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long t,rr,i,k,mx,mx2;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		mx=0;
		mx2=0;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&k);
			mx2=max(mx2,min(mx,k));
			mx=max(mx,k);
		}
		printf("%lld\n",mx+mx2);
	}
}