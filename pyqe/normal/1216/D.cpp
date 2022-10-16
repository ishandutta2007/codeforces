#include <bits/stdc++.h>

using namespace std;

long long n,a[200069],mx=0;

int main()
{
	long long i,gd=0,c=0;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",a+i);
		mx=max(mx,a[i]);
	}
	for(i=0;i<n;i++)
	{
		a[i]=mx-a[i];
		gd=__gcd(gd,a[i]);
	}
	if(gd!=0)
	{
		for(i=0;i<n;i++)
		{
			c+=a[i]/gd;
		}
	}
	printf("%lld %lld\n",c,gd);
}