#include <bits/stdc++.h>

using namespace std;

long long n,d;

int main()
{
	long long t,rr,i,k,mn,mx;
	bool bad;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		bad=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&k);
			if(i==1)
			{
				mn=k;
				mx=k;
			}
			else
			{
				mn=max(mn-d+1,k);
				mx=min(mx+d-1,k+d-1);
			}
			bad|=mn>mx||(i==n&&mn!=k);
		}
		if(!bad)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}