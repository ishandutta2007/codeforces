#include <bits/stdc++.h>

using namespace std;

long long n,d;

int main()
{
	long long t,rr,i,k,l,c;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&d,&n);
		c=1;
		l=d;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&k);
			if(k==l)
			{
				c--;
			}
			if(k<l)
			{
				l=k-1;
				c++;
			}
		}
		if(l==0)
		{
			c--;
		}
		printf("%lld\n",c);
	}
}