#include <bits/stdc++.h>

using namespace std;

const long long inf=1e18;
long long n,a[300069];

int main()
{
	long long t,rr,i,ii,k,w,mx,lh,rh,md,zz,c[2],z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		mx=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
			mx=max(mx,a[i]);
		}
		z=inf;
		for(ii=0;ii<2;ii++)
		{
			for(lh=0,rh=n*(mx+1)*2;lh<=rh;)
			{
				md=(lh+rh)/2;
				c[0]=(md+1)/2;
				c[1]=md/2;
				for(i=1;i<=n;i++)
				{
					k=mx+ii-a[i];
					w=min(k/2,c[1]);
					k-=w*2;
					c[1]-=w;
					if(k>c[0])
					{
						break;
					}
					c[0]-=k;
				}
				if(i>n)
				{
					zz=md;
					rh=md-1;
				}
				else
				{
					lh=md+1;
				}
			}
			z=min(z,zz);
		}
		printf("%lld\n",z);
	}
}