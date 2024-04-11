#include <bits/stdc++.h>

using namespace std;

long long n,d,a[2][100069];

int main()
{
	long long t,rr,i,ii,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		z=0;
		for(ii=0;ii<2;ii++)
		{
			for(i=1;i<=n;i++)
			{
				scanf("%lld",&a[ii][i]);
				z+=a[ii][i]*!ii;
			}
		}
		sort(a[0]+1,a[0]+n+1);
		sort(a[1]+1,a[1]+n+1,greater<long long>());
		for(i=1;i<=d;i++)
		{
			z+=max(a[1][i]-a[0][i],0ll);
		}
		printf("%lld\n",z);
	}
}