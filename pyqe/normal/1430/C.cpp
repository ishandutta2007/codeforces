#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long t,rr,i;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		printf("2\n");
		for(i=n-1;i;i--)
		{
			printf("%lld %lld\n",i,min(i+2,n));
		}
	}
}