#include <bits/stdc++.h>

using namespace std;

long long n,d,a[200069],ps[200069];

int main()
{
	long long t,rr,i,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
		}
		z=0;
		for(i=1;i<n;i++)
		{
			ps[i]=ps[i-1]+(a[i]<a[i+1]*2);
			if(i>=d)
			{
				z+=ps[i]-ps[i-d]==d;
			}
		}
		printf("%lld\n",z);
	}
}