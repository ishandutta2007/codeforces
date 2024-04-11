#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long i,gd=0;
	
	scanf("%lld",&n);
	for(i=2;i*i<=n;i++)
	{
		if(n%i==0)
		{
			gd=__gcd(gd,i);
			for(;n%i==0;n/=i);
		}
	}
	if(n>1)
	{
		gd=__gcd(gd,n);
	}
	if(gd==0)
	{
		gd=1;
	}
	printf("%lld\n",gd);
}