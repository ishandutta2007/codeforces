#include <bits/stdc++.h>

using namespace std;

long long n,a[200069];

int main()
{
	long long i,j,z=0;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		a[i]=abs(a[i]);
	}
	sort(a+1,a+n+1);
	for(j=0,i=1;i<=n;i++)
	{
		for(;j+1<i&&a[j+1]<(a[i]+1)/2;j++);
		z+=i-1-j;
	}
	printf("%lld\n",z);
}