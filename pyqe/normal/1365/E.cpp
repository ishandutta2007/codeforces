#include <bits/stdc++.h>

using namespace std;

long long n,a[569],inf=1e18;

int main()
{
	long long i,j,r,z=-inf;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	for(i=1;i<=n;i++)
	{
		for(j=i;j<=n;j++)
		{
			for(r=j;r<=n;r++)
			{
				z=max(z,a[i]|a[j]|a[r]);
			}
		}
	}
	printf("%lld\n",z);
}