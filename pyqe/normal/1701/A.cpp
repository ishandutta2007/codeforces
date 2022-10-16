#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long t,rr,ii,jj,k,c,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		c=0;
		for(ii=0;ii<2;ii++)
		{
			for(jj=0;jj<2;jj++)
			{
				scanf("%lld",&k);
				c+=k;
			}
		}
		if(!c)
		{
			z=0;
		}
		else if(c==4)
		{
			z=2;
		}
		else
		{
			z=1;
		}
		printf("%lld\n",z);
	}
}