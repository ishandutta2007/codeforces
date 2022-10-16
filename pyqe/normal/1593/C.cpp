#include <bits/stdc++.h>

using namespace std;

long long n,d,a[400069];

int main()
{
	long long t,rr,i,sm,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&d,&n);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
			a[i]=d-a[i];
		}
		sort(a+1,a+n+1);
		sm=0;
		z=0;
		for(i=1;i<=n;i++)
		{
			if(sm+a[i]<d)
			{
				z++;
				sm+=a[i];
			}
		}
		printf("%lld\n",z);
	}
}