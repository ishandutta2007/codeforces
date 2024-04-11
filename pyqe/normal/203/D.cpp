#include <bits/stdc++.h>

using namespace std;

long long n[2],m,d,a[2],inf=1e9;

int main()
{
	long long i,ii,lh,rh,md,zz;
	double tm,k,z;
	
	scanf("%lld%lld%lld%lld%lld%lld",n,n+1,&m,a,&d,a+1);
	tm=(double)m/-d;
	for(ii=0;ii<2;ii++)
	{
		k=tm*a[ii]+(double)n[ii]/2*!ii;
		for(lh=-inf,rh=inf;lh<=rh;)
		{
			md=(lh+rh)/2;
			if((double)(n[ii]*md)-1e-9<=k)
			{
				zz=md;
				lh=md+1;
			}
			else
			{
				rh=md-1;
			}
		}
		z=k-n[ii]*zz;
		if(zz%2)
		{
			z=n[ii]-z;
		}
		printf("%.10lf%c",z," \n"[ii]);
	}
}