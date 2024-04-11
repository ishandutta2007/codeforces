#include <bits/stdc++.h>

using namespace std;

long long n,nn,a[1000069];

int main()
{
	long long t,rr,i,z;
	char ch;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		nn=0;
		for(i=1;i<=n;i++)
		{
			scanf(" %c",&ch);
			if(ch=='*')
			{
				nn++;
				a[nn]=i-nn;
			}
		}
		z=0;
		for(i=2;i<=nn;i++)
		{
			z+=(a[i]-a[i-1])*min(i-1,nn+1-i);
		}
		printf("%lld\n",z);
	}
}