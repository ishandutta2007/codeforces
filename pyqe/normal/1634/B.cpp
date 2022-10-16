#include <bits/stdc++.h>

using namespace std;

long long n,d,d2;

int main()
{
	long long t,rr,i,k;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld",&n,&d,&d2);
		for(i=0;i<n;i++)
		{
			scanf("%lld",&k);
			d^=k;
		}
		if(d%2==d2%2)
		{
			printf("Alice\n");
		}
		else
		{
			printf("Bob\n");
		}
	}
}