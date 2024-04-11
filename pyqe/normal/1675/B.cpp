#include <bits/stdc++.h>

using namespace std;

long long n,a[100069];

int main()
{
	long long t,rr,i,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
		}
		z=0;
		for(i=n-1;i;i--)
		{
			for(;a[i]&&a[i]>=a[i+1];a[i]/=2,z++);
			if(a[i]>=a[i+1])
			{
				z=-1;
				break;
			}
		}
		printf("%lld\n",z);
	}
}