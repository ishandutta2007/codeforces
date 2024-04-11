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
		if(n>=d*d&&n%2==d%2)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}