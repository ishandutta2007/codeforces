#include <bits/stdc++.h>

using namespace std;

long long n,a[1069];

int main()
{
	long long i,u,e,c=0,z;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	c=0;
	for(z=0;1;z++)
	{
		e=(z%2);
		u=!e*2-1;
		for(i=1+(n-1)*e;i&&i<=n;i+=u)
		{
			if(a[i]<=c)
			{
				c++;
				a[i]=n+1;
			}
		}
		if(c==n)
		{
			break;
		}
	}
	printf("%lld\n",z);
}