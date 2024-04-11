#include <bits/stdc++.h>

using namespace std;

long long n,st,fn,a[100069];

int main()
{
	long long i,z=0;
	
	scanf("%lld",&n);
	for(i=1;i<n;i++)
	{
		scanf("%lld",a+i);
	}
	scanf("%lld%lld",&st,&fn);
	for(i=st;i<fn;i++)
	{
		z+=a[i];
	}
	printf("%lld\n",z);
}