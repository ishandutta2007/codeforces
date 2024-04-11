#include <bits/stdc++.h>

using namespace std;

long long n,nn=0,ma=1e9,ky[100069],a[200069];

int main()
{
	long long i,k,p,z=0;
	
	for(i=1;(i-1)*(i-1)<=ma;i++)
	{
		nn++;
		ky[nn]=i*i;
	}
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		p=upper_bound(ky+1,ky+nn+1,k)-ky;
		a[i]=min(ky[p]-k,k-ky[p-1]);
		a[i]-=!a[i]+!k;
	}
	sort(a+1,a+n+1);
	for(i=1;i<=n/2;i++)
	{
		z+=max(a[i],0ll);
	}
	for(i=n/2+1;i<=n;i++)
	{
		z+=max(-a[i],0ll);
	}
	printf("%lld\n",z);
}