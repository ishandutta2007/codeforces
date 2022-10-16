#include <bits/stdc++.h>

using namespace std;

const long long d=1000;
long long n,fq[2][2069];

int main()
{
	long long i,ii,u,y,x,z=0;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld%lld",&y,&x);
		for(ii=0;ii<2;ii++)
		{
			u=!ii*2-1;
			fq[ii][y+x*u+d*ii]++;
		}
	}
	for(ii=0;ii<2;ii++)
	{
		for(i=1;i<=d*2;i++)
		{
			z+=fq[ii][i]*(fq[ii][i]-1)/2;
		}
	}
	printf("%lld\n",z);
}