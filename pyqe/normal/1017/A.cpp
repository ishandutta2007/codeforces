#include <bits/stdc++.h>

using namespace std;

long long n,d=0;

int main()
{
	long long i,j,k,sm,z=0;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		sm=0;
		for(j=0;j<4;j++)
		{
			scanf("%lld",&k);
			sm+=k;
		}
		if(!i)
		{
			d=sm;
		}
		else if(sm>d)
		{
			z++;
		}
	}
	printf("%lld\n",z+1);
}