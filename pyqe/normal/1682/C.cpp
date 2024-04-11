#include <bits/stdc++.h>

using namespace std;

long long n,a[200069];

int main()
{
	long long t,rr,i,c,z;
	bool bad;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
		}
		sort(a+1,a+n+1);
		z=0;
		c=0;
		bad=0;
		for(i=1;i<=n;i++)
		{
			c++;
			if(i==n||a[i]!=a[i+1])
			{
				z+=min(c,2ll);
				bad|=c==1;
				c=0;
			}
		}
		z=(z+bad)/2;
		printf("%lld\n",z);
	}
}