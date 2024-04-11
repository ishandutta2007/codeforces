#include <bits/stdc++.h>

using namespace std;

long long n,d=2020;

int main()
{
	long long t,rr;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		if(n%d<=n/d)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}