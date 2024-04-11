#include <bits/stdc++.h>

using namespace std;

const long long inf=1e18;
long long n,d,a[5069],pc[5069],sx[5069];

int main()
{
	long long t,rr,i,j,sm,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
			pc[i]=-inf;
			sm=0;
			for(j=i;j;j--)
			{
				sm+=a[j];
				pc[i-j+1]=max(pc[i-j+1],sm);
			}
		}
		sx[n+1]=-inf;
		for(i=n;i>=0;i--)
		{
			sx[i]=max(sx[i+1],pc[i]);
		}
		z=0;
		for(i=0;i<=n;i++)
		{
			z=max(z,pc[i]+d*i);
			printf("%lld%c",max(z,sx[i]+d*i)," \n"[i==n]);
		}
	}
}