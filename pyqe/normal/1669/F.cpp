#include <bits/stdc++.h>

using namespace std;

long long n,ttl=0,a[200069],ps[2][200069];

int main()
{
	long long t,rr,i,j,ii,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		ttl=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
			ttl+=a[i];
		}
		for(ii=0;ii<2;ii++)
		{
			for(i=1;i<=n;i++)
			{
				ps[ii][i]=ps[ii][i-1]+a[i];
			}
			for(i=1;i<n+1-i;i++)
			{
				swap(a[i],a[n+1-i]);
			}
		}
		z=0;
		for(j=1,i=1;i<=n;i++)
		{
			for(;j<=n&&ps[1][j]<ps[0][i];j++);
			if(j<=n&&ps[1][j]==ps[0][i]&&ps[0][i]*2<=ttl)
			{
				z=i+j;
			}
		}
		printf("%lld\n",z);
	}
}