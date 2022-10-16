#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long t,rr,i,k,l,mx,mn;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		mx=-1e18;
		mn=1e18;
		for(i=0;i<n;i++)
		{
			scanf("%lld%lld",&k,&l);
			mx=max(mx,k);
			mn=min(mn,l);
		}
		printf("%lld\n",max(mx-mn,0ll));
	}
}