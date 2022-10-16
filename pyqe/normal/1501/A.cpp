#include <bits/stdc++.h>

using namespace std;

long long n,a[100069][2];

int main()
{
	long long t,rr,i,ii,k,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			for(ii=0;ii<2;ii++)
			{
				scanf("%lld",&a[i][ii]);
			}
		}
		z=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&k);
			z+=a[i][0]-a[i-1][1]+k;
			if(i<n)
			{
				z=max(z+(a[i][1]-a[i][0]+1)/2,a[i][1]);
			}
		}
		printf("%lld\n",z);
	}
}