#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long c=0,z=0,b=0,n,i,k;
	bool g=false;
	
	scanf("%lld",&n);
	for(i=0;i<=n;i++)
	{
		if(i<n)
		{
			scanf("%lld",&k);
		}
		if(k==1||i==n)
		{
			if(i<n)
			{
				z++;
			}
			if(c>b)
			{
				b=c;
			}
			c--;
		}
		else
		{
			g=true;
			if(c<0)
			{
				c=0;
			}
			c++;
		}
	}
	if(!g)
	{
		b--;
	}
	printf("%lld\n",z+b);
}