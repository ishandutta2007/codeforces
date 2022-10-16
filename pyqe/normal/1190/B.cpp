#include <bits/stdc++.h>

using namespace std;

long long n,z=0,c=0,a[100069],e;
map<long long,long long> fq;

int main()
{
	long long i;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",a+i);
		fq[a[i]]++;
		if(fq[a[i]]>1)
		{
			e=a[i];
			c++;
			if(c>1)
			{
				printf("cslnb\n");
				return 0;
			}
		}
		z+=a[i];
	}
	if(c&&(!e||fq[e-1]==1))
	{
		printf("cslnb\n");
		return 0;
	}
	if((z-n*(n-1)/2)%2==0)
	{
		printf("cslnb\n");
	}
	else
	{
		printf("sjfnb\n");
	}
}