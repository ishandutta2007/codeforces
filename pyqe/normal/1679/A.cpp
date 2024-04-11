#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long t,rr,z,z2;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		if(n%2||n<4)
		{
			printf("-1\n");
			continue;
		}
		n/=2;
		z=(n+2)/3;
		z2=n/2;
		printf("%lld %lld\n",z,z2);
	}
}