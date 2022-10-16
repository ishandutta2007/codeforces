#include <bits/stdc++.h>

using namespace std;

long long n,m,d,ma=1e9;

int main()
{
	long long t,rr,i,z,lh,rh,md,zz;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld",&m,&d,&n);
		n-=d;
		m-=d;
		if(n*2<=m)
		{
			z=2;
		}
		else if(n>m)
		{
			z=1;
		}
		else
		{
			for(lh=1,rh=ma;lh<=rh;)
			{
				md=(lh+rh)/2;
				if(m*md>=n*(md*2-1))
				{
					zz=md;
					lh=md+1;
				}
				else
				{
					rh=md-1;
				}
			}
			zz+=(n*(zz*2+1)-m*(zz+1))*(zz*2-1)<(m*zz-n*(zz*2-1))*(zz*2+1);
			z=zz*2-1;
		}
		printf("%lld\n",z);
	}
}