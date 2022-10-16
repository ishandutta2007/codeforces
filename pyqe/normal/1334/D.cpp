#include <bits/stdc++.h>

using namespace std;

long long n; 

int main()
{
	long long t,rr,i,lb,rb,lh,rh,md,zz,sm,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld",&n,&lb,&rb);
		for(i=lb;i<=rb;i++)
		{
			if(i<=n*(n-1))
			{
				for(lh=0,rh=n-1;lh<=rh;)
				{
					md=(lh+rh)/2;
					if(n*(n-1)-(n-md)*(n-md-1)<i)
					{
						zz=md;
						lh=md+1;
					}
					else
					{
						rh=md-1;
					}
				}
				sm=n*(n-1)-(n-zz)*(n-zz-1);
				if((i-sm)%2)
				{
					z=zz+1;
				}
				else
				{
					z=(i-sm)/2+zz+1;
				}
			}
			else
			{
				z=1;
			}
			printf("%lld%c",z," \n"[i==rb]);
		}
	}
}