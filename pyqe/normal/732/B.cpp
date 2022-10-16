#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long n,k,i,z=0;
	
	scanf("%lld%lld",&n,&k);
	long long a[n];
	for(i=0;i<n;i++)
	{
		scanf("%lld",a+i);
		if(i>0&&a[i]+a[i-1]<k)
		{
			z+=k-a[i]-a[i-1];
			a[i]=k-a[i-1];
		}
	}
	printf("%lld\n",z);
	for(i=0;i<n;i++)
	{
		if(i>0)
		{
			printf(" ");
		}
		printf("%lld",a[i]);
	}
}