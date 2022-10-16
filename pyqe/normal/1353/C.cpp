#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long t,rr;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		n/=2;
		printf("%lld\n",n*(n+1)*(n*2+1)/3*4);
	}
}