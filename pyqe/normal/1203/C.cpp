#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long i,k,gd=0,z=0;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		gd=__gcd(gd,k);
	}
	for(i=1;i*i<=gd;i++)
	{
		if(gd%i==0)
		{
			z+=1+(i!=gd/i);
		}
	}
	printf("%lld\n",z);
}