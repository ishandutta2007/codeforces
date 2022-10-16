#include <bits/stdc++.h>

using namespace std;

long long n,fq[20];

int main()
{
	long long i,j,k,z=0;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		for(j=0;k;k/=2,j++)
		{
			fq[j]+=k%2;
		}
	}
	for(i=1;i<=n;i++)
	{
		k=0;
		for(j=19;j+1;j--)
		{
			k=k*2+(i<=fq[j]);
		}
		z+=k*k;
	}
	printf("%lld\n",z);
}