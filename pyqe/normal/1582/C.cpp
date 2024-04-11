#include <bits/stdc++.h>

using namespace std;

const long long d=26;
long long n,nn=0,a[100069],ca[100069],wg[100069];

int main()
{
	long long t,rr,i,j,c,z;
	char ch;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf(" %c",&ch);
			a[i]=ch-'a';
		}
		z=n+1;
		for(i=0;i<d;i++)
		{
			nn=0;
			wg[nn]=0;
			for(j=1;j<=n;j++)
			{
				if(a[j]==i)
				{
					wg[nn]++;
				}
				else
				{
					nn++;
					ca[nn]=a[j];
					wg[nn]=0;
				}
			}
			for(j=1;j<nn+1-j;j++)
			{
				if(ca[j]!=ca[nn+1-j])
				{
					break;
				}
			}
			if(j<nn+1-j)
			{
				continue;
			}
			c=0;
			for(j=1;j<=nn+1-j;j++)
			{
				c+=wg[j-1]+wg[nn+1-j]-min(wg[j-1],wg[nn+1-j])*2;
			}
			z=min(z,c);
		}
		if(z==n+1)
		{
			z=-1;
		}
		printf("%lld\n",z);
	}
}