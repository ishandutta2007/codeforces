#include <bits/stdc++.h>

using namespace std;

long long n,a[2][100069],inf=1e18;

int main()
{
	long long t,rr,i,ii,mn[2],z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(ii=0;ii<2;ii++)
		{
			mn[ii]=inf;
			for(i=1;i<=n;i++)
			{
				scanf("%lld",&a[ii][i]);
				mn[ii]=min(mn[ii],a[ii][i]);
			}
		}
		z=0;
		for(i=1;i<=n;i++)
		{
			z+=max(a[0][i]-mn[0],a[1][i]-mn[1]);
		}
		printf("%lld\n",z);
	}
}