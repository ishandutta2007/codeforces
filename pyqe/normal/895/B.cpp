#include <bits/stdc++.h>

using namespace std;

long long n,m,d,a[100069];

int main()
{
	long long i,k,z=0;
	
	scanf("%lld%lld%lld",&n,&m,&d);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++)
	{
		k=((a[i]-1)/m+d)*m;
		z+=upper_bound(a+1,a+n+1,k+m-1)-lower_bound(a+1,a+n+1,max(k,a[i]));
	}
	printf("%lld\n",z);
}