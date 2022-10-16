#include <bits/stdc++.h>

using namespace std;

long long n,a[200069];

int main()
{
	long long i,j,k,z=0;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		a[i]-=k;
	}
	sort(a+1,a+n+1);
	for(j=0,i=n;i;i--)
	{
		for(;j<n&&a[i]+a[j+1]<=0;j++);
		z+=max(i-1-j,0ll);
	}
	printf("%lld\n",z);
}