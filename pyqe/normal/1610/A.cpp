#include <bits/stdc++.h>

using namespace std;

long long n,m;

int main()
{
	long long t,rr;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&m);
		printf("%lld\n",(long long)(n>1)+(m>1));
	}
}