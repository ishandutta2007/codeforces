#include <bits/stdc++.h>

using namespace std;

long long n,d,a[100069];

int main()
{
	long long t,rr,i,sm,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
		}
		sort(a+1,a+n+1,greater<long long>());
		sm=0;
		for(i=1;i<=n;i++)
		{
			sm+=a[i];
			if(d*i>sm)
			{
				break;
			}
		}
		z=i-1;
		printf("%lld\n",z);
	}
}