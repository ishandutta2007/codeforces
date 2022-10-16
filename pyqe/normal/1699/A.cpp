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
		if(n%2)
		{
			printf("-1\n");
		}
		else
		{
			printf("0 0 %lld\n",n/2);
		}
	}
}