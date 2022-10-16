#include <bits/stdc++.h>

using namespace std;

long long n,a[100069];

int main()
{
	long long i,z=0,k,l;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld%lld",&k,&l);
		z+=k*(n-1);
		a[i]=l-k;
	}
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++)
	{
		z+=a[i]*(n-i);
	}
	printf("%lld\n",z);
}