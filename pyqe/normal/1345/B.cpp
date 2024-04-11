#include <bits/stdc++.h>

using namespace std;

long long n,nn=0,ma=1e9,ky[100069];

int main()
{
	long long t,rr,i,z;
	
	for(;ky[nn]<ma;)
	{
		nn++;
		ky[nn]=nn*(nn+1)/2*3-nn;
	}
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		z=0;
		for(i=nn;i;i--)
		{
			z+=n/ky[i];
			n%=ky[i];
		}
		printf("%lld\n",z);
	}
}