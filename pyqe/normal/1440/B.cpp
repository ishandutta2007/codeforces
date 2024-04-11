#include <bits/stdc++.h>

using namespace std;

long long n,m,a[1000069];

int main()
{
	long long t,rr,i,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&m);
		for(i=1;i<=n*m;i++)
		{
			scanf("%lld",a+i);
		}
		sort(a+1,a+n*m+1);
		z=0;
		for(i=1;i<=m;i++)
		{
			z+=a[n*m+1-(n/2+1)*i];
		}
		printf("%lld\n",z);
	}
}