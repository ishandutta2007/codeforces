#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long t,rr,i,k,mn,mx;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		mn=1e18;
		mx=-1e18;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&k);
			if(k<i-1)
			{
				mn=min(mn,i-1);
			}
			if(k<n-i)
			{
				mx=max(mx,i+1);
			}
		}
		if(mn>=mx)
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}
}