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
		if(d%3!=0)
		{
			if(n%3==0)
			{
				printf("Bob\n");
			}
			else
			{
				printf("Alice\n");
			}
		}
		else
		{
			n%=d+1;
			if(n%3==0&&n<d)
			{
				printf("Bob\n");
			}
			else
			{
				printf("Alice\n");
			}
		}
	}
}