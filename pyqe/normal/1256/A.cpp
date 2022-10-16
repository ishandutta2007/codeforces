#include <bits/stdc++.h>

using namespace std;

long long n,m,d,w;

int main()
{
	long long t,rr;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld%lld",&n,&m,&d,&w);
		if(min(n,w/d)*d+m>=w)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}