#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long t,rr,i,k,l,c,c2,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		c=1;
		c2=0;
		z=0;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&k);
			if(i)
			{
				if(k<l)
				{
					c--;
					if(!c)
					{
						c=c2;
						c2=0;
					}
				}
				z+=!c2;
				c2++;
			}
			l=k;
		}
		printf("%lld\n",z);
	}
}