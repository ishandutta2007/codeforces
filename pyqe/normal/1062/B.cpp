#include <bits/stdc++.h>

using namespace std;

long long n,nn;

int main()
{
	long long i,c,z=1,mx=0,w=0;
	
	scanf("%lld",&nn);
	n=nn;
	for(i=2;i*i<=n;i++)
	{
		if(n%i==0)
		{
			z*=i;
			for(c=0;n%i==0;n/=i,c++);
			mx=max(mx,c);
		}
	}
	if(n>1)
	{
		z*=n;
		mx=max(mx,1ll);
	}
	for(mx--;mx>0;mx/=2,w++);
	for(n=z,i=0;i<w&&n<nn;i++,n=n*n);
	printf("%lld %lld\n",z,(n!=nn)+w);
}