#include <bits/stdc++.h>

using namespace std;

const long long dv=998244353;
long long n,ttl=0,a[200069],ps[200069];

int main()
{
	long long t,rr,i,ii,jj,sm,lh,rh,md,zz,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		ttl=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
			ttl+=a[i];
			ps[i]=ps[max(i-2,0ll)]+a[i];
		}
		z=0;
		for(ii=0;ii<2;ii++)
		{
			for(jj=0;jj<2;jj++)
			{
				sm=a[1]*ii+a[n]*jj;
				for(i=1+!ii;i<n-jj;i++)
				{
					sm+=a[i]*(i>1);
					if(sm*2>=ttl)
					{
						break;
					}
					for(lh=0,rh=(n-jj-1-i)/2;lh<=rh;)
					{
						md=(lh+rh)/2;
						if((sm+ps[i+md*2]-ps[i])*2<ttl)
						{
							zz=md;
							lh=md+1;
						}
						else
						{
							rh=md-1;
						}
					}
					z=(z+zz+1)%dv;
				}
			}
		}
		sm=0;
		for(i=1;i<=n&&(sm+a[n+1-i])*2<ttl;sm+=a[n+1-i],i++);
		z=(z+i)%dv;
		printf("%lld\n",z);
	}
}