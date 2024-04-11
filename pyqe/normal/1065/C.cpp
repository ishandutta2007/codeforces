#include <bits/stdc++.h>

using namespace std;

long long n,d,ma=2e5,fq[200069],inf=1e18;

int main()
{
	long long i,k,sm=0,z=0;
	
	scanf("%lld%lld",&n,&d);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		fq[k]++;
	}
	for(i=ma;i;i--)
	{
		fq[i-1]+=fq[i];
	}
	for(i=ma;fq[i]<n;i--)
	{
		if(sm+fq[i]>d)
		{
			sm=0;
			z++;
		}
		sm+=fq[i];
	}
	z+=!!sm;
	printf("%lld\n",z);
}