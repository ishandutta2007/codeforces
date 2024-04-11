#include <bits/stdc++.h>

using namespace std;

long long n,rt,fq[200069];

int main()
{
	long long i,j,k,z=0;
	
	scanf("%lld%lld",&n,&rt);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		if(i==rt&&k)
		{
			z++;
			k=0;
		}
		fq[k]++;
	}
	for(j=0;fq[j];j++);
	for(i=n;i>j;i--)
	{
		for(;fq[i%n]-!(i%n)&&i>j;fq[i%n]--)
		{
			fq[j]++;
			z++;
			for(;fq[j];j++);
		}
	}
	printf("%lld\n",z);
}