#include <bits/stdc++.h>

using namespace std;

long long n,nn,a[300069],mn[300069],mx[300069];
bitset<300069> vtd;

int main()
{
	long long t,rr,i,k,c,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		nn=0;
		vtd.reset();
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&k);
			if(!vtd[k])
			{
				nn++;
				a[nn]=k;
				mn[k]=i;
				vtd[k]=1;
			}
			mx[k]=i;
		}
		sort(a+1,a+nn+1);
		z=0;
		c=0;
		for(i=1;i<=nn;i++)
		{
			if(mn[a[i]]>mx[a[i-1]])
			{
				c++;
			}
			else
			{
				c=1;
			}
			z=max(z,c);
		}
		printf("%lld\n",nn-z);
	}
}