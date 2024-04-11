#include <bits/stdc++.h>

using namespace std;
long long n,d,a[100069];

int main()
{
	long long i,j;
	double z=-1;
	
	scanf("%lld%lld",&n,&d);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	for(j=n,i=n;i;i--)
	{
		for(;a[j]>a[i]+d;j--);
		if(j>i+1)
		{
			z=max(z,(double)(a[j]-a[i+1])/(a[j]-a[i]));
		}
	}
	if(z!=-1)
	{
		printf("%.20lf\n",z);
	}
	else
	{
		printf("-1\n");
	}
}