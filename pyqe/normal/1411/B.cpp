#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long t,rr,k;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(;1;n++)
		{
			for(k=n;k;k/=10)
			{
				if(k%10&&n%(k%10))
				{
					break;
				}
			}
			if(!k)
			{
				break;
			}
		}
		printf("%lld\n",n);
	}
}