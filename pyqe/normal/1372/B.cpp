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
		for(i=2;i*i<=n;i++)
		{
			if(n%i==0)
			{
				break;
			}
		}
		if(i*i>n)
		{
			i=n;
		}
		printf("%lld %lld\n",n/i,n-n/i);
	}
}