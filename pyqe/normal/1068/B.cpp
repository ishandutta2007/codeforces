#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long i,z=0;
	
	scanf("%lld",&n);
	for(i=1;i*i<=n;i++)
	{
		if(n%i==0)
		{
			z++;
			if(i!=n/i)
			{
				z++;
			}
		}
	}
	printf("%lld\n",z);
}