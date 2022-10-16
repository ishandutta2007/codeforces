#include <bits/stdc++.h>

using namespace std;

long long n,d,a[200069];

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
		sort(a+1,a+n+1,greater<long long>());
		z=(d-1)/(a[1]+a[2])*2;
		d=(d-1)%(a[1]+a[2])+1;
		printf("%lld\n",z+1+(d>a[1]));
	}
}