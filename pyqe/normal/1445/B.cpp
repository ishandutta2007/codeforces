#include <bits/stdc++.h>

using namespace std;

long long n,m,n2,m2;

int main()
{
	long long t,rr;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld%lld",&n,&m,&n2,&m2);
		printf("%lld\n",max(n+m,n2+m2));
	}
}