#include <bits/stdc++.h>

using namespace std;

long long n,fq[1069];

int main()
{
	long long t,rr,i,j,k,c,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			fq[i]=0;
		}
		for(i=0;i<n;i++)
		{
			scanf("%lld",&k);
			fq[k]++;
		}
		z=0;
		for(i=1;i<=n*2;i++)
		{
			c=0;
			for(j=1;j<=min(i-j,n);j++)
			{
				if(i-j<=n)
				{
					if(j!=i-j)
					{
						c+=min(fq[j],fq[i-j]);
					}
					else
					{
						c+=fq[j]/2;
					}
				}
			}
			z=max(z,c);
		}
		printf("%lld\n",z);
	}
}