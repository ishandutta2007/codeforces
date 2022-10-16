#include <bits/stdc++.h>

using namespace std;

long long n,a[100069];

int main()
{
	long long t,rr,i,c,mx,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
		}
		sort(a+1,a+n+1);
		c=0;
		mx=0;
		for(i=1;i<=n;i++)
		{
			c=c*(a[i]==a[i-1])+1;
			mx=max(mx,c);
		}
		for(z=n-mx;mx<n;mx*=2,z++);
		printf("%lld\n",z);
	}
}