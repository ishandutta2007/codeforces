#include <bits/stdc++.h>

using namespace std;

long long n[2],m,dg[200069];

int main()
{
	long long t,rr,i,ii,k,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld",n,n+1,&m);
		z=m*(m-1)/2;
		for(ii=0;ii<2;ii++)
		{
			for(i=1;i<=n[ii];i++)
			{
				dg[i]=0;
			}
			for(i=0;i<m;i++)
			{
				scanf("%lld",&k);
				dg[k]++;
			}
			for(i=1;i<=n[ii];i++)
			{
				z-=dg[i]*(dg[i]-1)/2;
			}
		}
		printf("%lld\n",z);
	}
}