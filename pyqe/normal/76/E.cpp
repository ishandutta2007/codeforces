#include <bits/stdc++.h>

using namespace std;

long long n,a[100069][2];

int main()
{
	long long i,ii,sm,z=0;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		for(ii=0;ii<2;ii++)
		{
			scanf("%lld",&a[i][ii]);
		}
	}
	for(ii=0;ii<2;ii++)
	{
		sm=0;
		for(i=0;i<n;i++)
		{
			z+=a[i][ii]*a[i][ii]*(n-1);
			z-=2*sm*a[i][ii];
			sm+=a[i][ii];
		}
	}
	printf("%lld\n",z);
}