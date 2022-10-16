#include <bits/stdc++.h>

using namespace std;

long long n,a[19];

int main()
{
	long long i,j,k,z,mx=-1e18;
	bool bad;
	
	scanf("%lld",&n);
	for(i=0;n;n/=10,i++)
	{
		a[i]=n%10;
	}
	for(i=-1;i<=18;i++)
	{
		if(i<0||a[i])
		{
			bad=0;
			z=1;
			for(j=18;j+1;j--)
			{
				if(j>=i)
				{
					k=a[j]-(j==i);
				}
				else
				{
					k=9;
				}
				if(k)
				{
					bad=1;
				}
				if(bad)
				{
					z*=k;
				}
			}
			mx=max(mx,z);
		}
	}
	printf("%lld\n",mx);
}