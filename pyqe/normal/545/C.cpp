#include <bits/stdc++.h>

using namespace std;

long long n,inf=1e18;

int main()
{
	long long i,k,l=-inf,l2=-inf,w,z=0;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld%lld",&k,&w);
		if(k<=l2)
		{
			z--;
			l2=l;
		}
		z++;
		if(k-w>l2)
		{
			l2=k;
		}
		else
		{
			l2=k+w;
		}
		l=k;
	}
	printf("%lld\n",z);
}