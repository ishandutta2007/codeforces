#include <bits/stdc++.h>

using namespace std;

long long nn=0,ma=1e9,sq[100069];

int main()
{
	long long t,rr,i,k;
	
	for(i=3;i*i/2+1<=ma;i+=2)
	{
		nn++;
		sq[nn]=i*i/2+1;
	}
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&k);
		printf("%lld\n",upper_bound(sq+1,sq+nn+1,k)-sq-1);
	}
}