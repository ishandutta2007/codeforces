#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long t,rr,i,k,mn,mx;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		mn=1e18;
		mx=-1e18;
		for(i=0;i<3;i++)
		{
			scanf("%lld",&k);
			mn=min(mn,k);
			mx=max(mx,k);
		}
		printf("%lld\n",max(mx-mn-2,0ll)*2);
	}
}