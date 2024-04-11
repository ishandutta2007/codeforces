#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long t,rr,i,k,sm;
	bool bad;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		sm=0;
		bad=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&k);
			sm+=k;
			bad|=sm<i*(i-1)/2;
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