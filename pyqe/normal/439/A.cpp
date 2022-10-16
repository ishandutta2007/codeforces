#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long n,d,i,z=0,c=0,k;
	
	scanf("%lld%lld",&n,&d);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		if(i>0)
		{
			z+=10;
			c+=2;
		}
		z+=k;
		if(z>d)
		{
			break;
		}
	}
	if(z>d)
	{
		printf("-1\n");
	}
	else
	{
		c+=(d-z)/5;
		printf("%lld\n",c);
	}
}