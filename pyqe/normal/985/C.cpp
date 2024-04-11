#include <bits/stdc++.h>

using namespace std;

long long n,m,d,a[100069];

int main()
{
	long long i,c=0,z=0;
	
	scanf("%lld%lld%lld",&n,&m,&d);
	for(i=1;i<=n*m;i++)
	{
		scanf("%lld",a+i);
	}
	sort(a+1,a+n*m+1);
	for(i=0;i<n*m&&a[i+1]<=a[1]+d;i++);
	z=a[1];
	for(;i-1&&c<n;i--)
	{
		if(i<=(n-c-1)*m+1)
		{
			z+=a[i];
			c++;
		}
	}
	printf("%lld\n",z*(c==n-1));
}