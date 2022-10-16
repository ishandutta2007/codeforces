#include <bits/stdc++.h>

using namespace std;

long long n,m,d;

int main()
{
	long long t,rr;
	bool bad;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld",&n,&m,&d);
		bad=0;
		for(;m;)
		{
			bad|=d<=n&&d%m==n%m;
			n%=m;
			swap(n,m);
		}
		if(bad)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}