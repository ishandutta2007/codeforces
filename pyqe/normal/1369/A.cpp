#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long t,rr;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		if(n%4==0)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}