#include <bits/stdc++.h>

using namespace std;

long long ttl=0,a[6];

int main()
{
	long long i,j,r,z;
	
	for(i=1;i<=5;i++)
	{
		scanf("%lld",a+i);
		ttl+=a[i];
	}
	z=ttl;
	for(i=1;i<=5;i++)
	{
		for(j=i+1;j<=5;j++)
		{
			for(r=j;r<=5;r++)
			{
				if(a[i]==a[j]&&a[j]==a[r])
				{
					z=min(z,ttl-a[i]-a[j]-a[r]*(j!=r));
				}
			}
		}
	}
	printf("%lld\n",z);
}