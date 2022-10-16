#include <bits/stdc++.h>

using namespace std;

long long n;
bitset<400069> a;

int main()
{
	long long i,mx=0,c=0,k;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		a[i]=k;
	}
	for(i=n;i<n+n;i++)
	{
		a[i]=a[i-n];
	}
	for(i=0;i<n+n;i++)
	{
		if(a[i])
		{
			c++;
			if(i==n+n-1||!a[i+1])
			{
				mx=max(mx,c);
				c=0;
			}
		}
	}
	printf("%lld\n",mx);
}