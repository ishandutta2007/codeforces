#include <bits/stdc++.h>

using namespace std;

const long long inf=1e18;
long long n,a[200069],a2[200069];

int main()
{
	long long t,rr,i,ii,u,w,sm,mn,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
			a2[i]=a[i];
		}
		a[0]=inf;
		a[n+1]=inf;
		z=0;
		for(ii=0;ii<2;ii++)
		{
			u=!ii*2-1;
			sm=0;
			for(i=1+(n-1)*ii;i&&i<=n;i+=u)
			{
				w=max(a[i]-a[i-u],0ll);
				z+=w;
				sm+=w;
				a2[i]-=sm;
			}
		}
		z+=abs(a2[1]);
		printf("%lld\n",z);
	}
}