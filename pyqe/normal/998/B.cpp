#include <bits/stdc++.h>

using namespace std;

long long n,d,a[100069],ct[100069],nn=0;

int main()
{
	long long i,sm=0;
	
	scanf("%lld%lld",&n,&d);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	for(i=1;i<=n;i++)
	{
		sm+=a[i]%2*2-1;
		if(i<n&&!sm)
		{
			nn++;
			ct[nn]=abs(a[i]-a[i+1]);
		}
	}
	sort(ct+1,ct+nn+1);
	for(i=1;i<=nn&&d>=ct[i];i++)
	{
		d-=ct[i];
	}
	printf("%lld\n",i-1);
}