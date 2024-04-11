#include <bits/stdc++.h>

using namespace std;

long long n,d;

int main()
{
	long long t,rr;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		printf("%lld\n",d/(n/2+1));
	}
}