#include <bits/stdc++.h>

using namespace std;

long long n,m;

int main()
{
	long long t,rr,i;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&m);
		printf("%lld\n",((n-1)/m+1)*m-n);
	}
}