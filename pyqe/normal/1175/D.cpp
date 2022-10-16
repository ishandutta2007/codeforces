#include <bits/stdc++.h>

using namespace std;

long long n,d,a[300069],sm[300069],z;

int main()
{
	long long i;
	
	scanf("%lld%lld",&n,&d);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	for(i=n;i;i--)
	{
		sm[i]=sm[i+1]+a[i];
	}
	z=sm[1];
	sm[1]=-1e18;
	sort(sm+1,sm+n+1,greater<long long>());
	for(i=1;i<d;i++)
	{
		z+=sm[i];
	}
	printf("%lld\n",z);
}