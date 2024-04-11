#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long k,c,z=1,i;
	
	scanf("%lld",&k);
	for(i=2;i*i<=k;i++)
	{
		if(k%i==0)
		{
			c=0;
			while(k%i==0)
			{
				k/=i;
				c++;
			}
			z*=c+1;
		}
	}
	if(k>1)
	{
		z*=2;
	}
	printf("%lld\n",z-1);
}