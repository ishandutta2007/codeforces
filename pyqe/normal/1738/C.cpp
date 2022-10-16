#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long t,rr,i,ii,k,c[2],z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(ii=0;ii<2;ii++)
		{
			c[ii]=0;
		}
		for(i=0;i<n;i++)
		{
			scanf("%lld",&k);
			c[abs(k)%2]++;
		}
		if(c[1]%4==0)
		{
			z=1;
		}
		else if(c[1]%4==1)
		{
			if(c[0]%2==0)
			{
				z=0;
			}
			else
			{
				z=1;
			}
		}
		else if(c[1]%4==2)
		{
			z=0;
		}
		else
		{
			z=1;
		}
		if(z)
		{
			printf("Alice\n");
		}
		else
		{
			printf("Bob\n");
		}
	}
}