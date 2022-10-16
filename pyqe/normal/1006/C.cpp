#include <bits/stdc++.h>

using namespace std;

long long n,a[200069],ps[200069],ss[200069];

int main()
{
	long long i,j,z=0;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		ps[i]=a[i]+ps[i-1];
	}
	for(i=n;i>0;i--)
	{
		ss[i]=a[i]+ss[i+1];
	}
	for(i=0,j=n+1;i<j;i++)
	{
		for(;ss[j]<ps[i];j--);
		if(i>=j)
		{
			break;
		}
		if(ps[i]==ss[j])
		{
			z=ps[i];
		}
	}
	printf("%lld\n",z);
}