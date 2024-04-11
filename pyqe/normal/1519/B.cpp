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
		if(n-1+n*(m-1)==d)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}