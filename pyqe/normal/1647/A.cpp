#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long t,rr,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		z=min((n-1)%3+1,2ll);
		for(;n;z=3-z)
		{
			printf("%lld",z);
			n-=z;
		}
		printf("\n");
	}
}