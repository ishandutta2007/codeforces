#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long t,rr,ml;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(ml=1;n%2==0;n/=2,ml*=2);
		printf("%lld %lld\n",n/2-ml+1,n/2+ml);
	}
}