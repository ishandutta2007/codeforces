#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long t,rr,k,ml;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		ml=1;
		for(k=n;k>=10;k/=10,ml*=10);
		printf("%lld\n",n-ml);
	}
}