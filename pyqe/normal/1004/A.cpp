#include <bits/stdc++.h>

using namespace std;

long long n,d,a[169];

int main()
{
	long long i,z=2;
	
	scanf("%lld%lld",&n,&d);
	for(i=0;i<n;i++)
	{
		scanf("%lld",a+i);
	}
	sort(a,a+n);
	for(i=1;i<n;i++)
	{
		if(a[i]-a[i-1]>=d+d)
		{
			z++;
		}
		if(a[i]-a[i-1]>d+d)
		{
			z++;
		}
	}
	printf("%lld\n",z);
}