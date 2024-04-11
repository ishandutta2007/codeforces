#include <bits/stdc++.h>

using namespace std;

long long f(long long x)
{
	long long z=0;
	
	for(;x;x/=10)
	{
		if(x%10)
		{
			z=z*10+x%10;
		}
	}
	for(;z;z/=10)
	{
		x=x*10+z%10;
	}
	return x;
}

int main()
{
	long long k,l;
	
	scanf("%lld%lld",&k,&l);
	if(f(k)+f(l)==f(k+l))
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
}