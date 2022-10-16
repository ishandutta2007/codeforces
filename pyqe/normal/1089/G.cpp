#include <bits/stdc++.h>

using namespace std;

long long n,nn,a[15];

int main()
{
	long long t,rr,i,k,z,mn;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		n--;
		nn=0;
		for(i=0;i<7;i++)
		{
			scanf("%lld",&k);
			if(k)
			{
				nn++;
				a[nn]=i;
			}
		}
		for(i=1;i<=nn;i++)
		{
			a[nn+i]=a[i]+7;
		}
		z=n/nn*7;
		mn=1e18;
		for(i=1;i<=nn;i++)
		{
			mn=min(mn,a[i+n%nn]-a[i]+1);
		}
		printf("%lld\n",z+mn);
	}
}