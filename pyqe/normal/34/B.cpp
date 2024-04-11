#include <bits/stdc++.h>

using namespace std;

long long n,d,a[100069];

int main()
{
	long long i,z=0;
	
	scanf("%lld%lld",&n,&d);
	for(i=0;i<n;i++)
	{
		scanf("%lld",a+i);
	}
	sort(a,a+n);
	for(i=0;i<min(n,d)&&a[i]<0;i++)
	{
		z-=a[i];
	}
	printf("%lld\n",z);
}