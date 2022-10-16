#include <bits/stdc++.h>

using namespace std;

const long long inf=1e18;
long long n,a[100069];

int main()
{
	long long t,rr,i;
	double z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
		}
		sort(a+1,a+n+1);
		for(i=1;i<=n;i++)
		{
			a[i]+=a[i-1];
		}
		z=-inf;
		for(i=1;i<n;i++)
		{
			z=max(z,(double)a[i]/i+(double)(a[n]-a[i])/(n-i));
		}
		printf("%.20lf\n",z);
	}
}