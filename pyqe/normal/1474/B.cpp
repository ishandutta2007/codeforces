#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long t,rr,i,j,ii,z[2];
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1,ii=0;ii<2;ii++)
		{
			for(i+=n;1;i++)
			{
				for(j=2;j*j<=i;j++)
				{
					if(i%j==0)
					{
						break;
					}
				}
				if(j*j>i)
				{
					break;
				}
			}
			z[ii]=i;
		}
		printf("%lld\n",z[0]*z[1]);
	}
}