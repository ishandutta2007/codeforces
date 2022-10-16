#include <bits/stdc++.h>

using namespace std;

long long n,sq[100069],zs=0;

int main()
{
	long long i,k,z[3],e=0,z2=0;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		if(k<0&&e<3)
		{
			z[e]=k;
			e++;
		}
		else if(k>0&&!z2)
		{
			z2=k;
		}
		else
		{
			zs++;
			sq[zs]=k;
		}
	}
	if(z2)
	{
		for(i=1;i<e;i++)
		{
			zs++;
			sq[zs]=z[i];
		}
		printf("1 %lld\n1 %lld\n",z[0],z2);
	}
	else
	{
		printf("1 %lld\n2 %lld %lld\n",z[0],z[1],z[2]);
	}
	printf("%lld",zs);
	for(i=1;i<=zs;i++)
	{
		printf(" %lld",sq[i]);
	}
	printf("\n");
}