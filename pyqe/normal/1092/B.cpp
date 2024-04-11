#include <bits/stdc++.h>

using namespace std;

long long n,a[100069];

int main()
{
	long long i,z=0;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",a+i);
	}
	sort(a,a+n);
	for(i=0;i<n;i+=2)
	{
		z+=a[i+1]-a[i];
	}
	printf("%lld\n",z);
}