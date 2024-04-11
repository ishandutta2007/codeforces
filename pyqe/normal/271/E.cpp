#include <bits/stdc++.h>

using namespace std;

long long n,m,z=0;

void ad(long long x)
{
	for(;x<=m;x*=2)
	{
		z+=m-x;
	}
}

int main()
{
	long long i,k,gd=0;
	
	scanf("%lld%lld",&n,&m);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		for(k--;k%2==0;k/=2);
		gd=__gcd(gd,k);
	}
	for(i=1;i*i<=gd;i++)
	{
		if(gd%i==0)
		{
			ad(i);
			if(gd/i!=i)
			{
				ad(gd/i);
			}
		}
	}
	printf("%lld\n",z);
}