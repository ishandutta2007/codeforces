#include <bits/stdc++.h>

using namespace std;

long long n,m,d;

int main()
{
	long long t,rr;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld",&n,&m,&d);
		if(abs(n-m)<=d*min(n,m))
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}