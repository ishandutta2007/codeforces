#include <bits/stdc++.h>

using namespace std;

long long n,d,a[200069];

int main()
{
	long long i,k,sm=0,mx=0,z;
	
	scanf("%lld%lld",&d,&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		a[i]*=-1;
		sm+=a[i];
		mx=max(mx,sm);
	}
	if(sm<=0)
	{
		if(d>mx)
		{
			printf("-1\n");
		}
		else
		{
			for(i=1;i<=n;i++)
			{
				d-=a[i];
				if(d<=0)
				{
					break;
				}
			}
			z=i;
			printf("%lld\n",z);
		}
	}
	else
	{
		k=(max(d-mx,0ll)+sm-1)/sm;
		d-=k*sm;
		z+=k*n;
		for(i=1;i<=n;i++)
		{
			d-=a[i];
			if(d<=0)
			{
				break;
			}
		}
		z+=i;
		printf("%lld\n",z);
	}
}