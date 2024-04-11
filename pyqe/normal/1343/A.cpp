#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long t,rr,i,k;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=2;1;i++)
		{
			k=(1ll<<i)-1;
			if(n%k==0)
			{
				printf("%lld\n",n/k);
				break;
			}
		}
	}
}