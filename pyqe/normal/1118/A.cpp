#include <bits/stdc++.h>

using namespace std;

long long n,d,d2;

int main()
{
	long long t,rr;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld",&n,&d,&d2);
		printf("%lld\n",n/2*(min(d2,d*2))+n%2*d);
	}
}