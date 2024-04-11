#include <bits/stdc++.h>

using namespace std;

const long long ma=1e9;
long long n;

int main()
{
	long long t,rr,i,k,lm;
	bool bad;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		lm=1;
		bad=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&k);
			lm=min(lm/__gcd(lm,i+1)*(i+1),ma+1);
			bad|=k%lm==0;
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