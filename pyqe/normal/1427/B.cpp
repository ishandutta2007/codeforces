#include <bits/stdc++.h>

using namespace std;

long long n,d,nn,a[100069];

int main()
{
	long long t,rr,i,c,z=0;
	char ch;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		nn=0;
		a[nn]=0;
		c=0;
		z=0;
		for(i=0;i<n;i++)
		{
			scanf(" %c",&ch);
			if(ch=='W')
			{
				z+=2;
				if(!i||a[nn])
				{
					z--;
					nn++;
					a[nn]=0;
				}
			}
			else
			{
				a[nn]++;
				c++;
			}
		}
		z+=min(d,c)*2-(!nn&&d);
		nn=max(nn-1,0ll);
		sort(a+1,a+nn+1);
		for(i=1;i<=nn;i++)
		{
			d-=a[i];
			z+=d>=0;
		}
		printf("%lld\n",z);
	}
}