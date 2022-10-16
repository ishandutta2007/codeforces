#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long t,rr,k,sm;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(;1;n++)
		{
			sm=0;
			for(k=n;k;k/=10)
			{
				sm+=k%10;
			}
			if(__gcd(n,sm)>1)
			{
				break;
			}
		}
		printf("%lld\n",n);
	}
}