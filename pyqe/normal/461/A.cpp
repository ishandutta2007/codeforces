#include <bits/stdc++.h>

using namespace std;

long long n,a[300069];

int main()
{
	long long i,z=0;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++)
	{
		z+=a[i]*min(i+1,n);
	}
	printf("%lld\n",z);
}