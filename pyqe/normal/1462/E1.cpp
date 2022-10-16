#include <bits/stdc++.h>

using namespace std;

long long n,a[200069];

int main()
{
	long long t,rr,i,j,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
		}
		sort(a+1,a+n+1);
		z=0;
		for(j=1,i=1;i<=n;i++)
		{
			for(;a[j]<a[i]-2;j++);
			z+=(i-j)*(i-j-1)/2;
		}
		printf("%lld\n",z);
	}
}