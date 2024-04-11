#include <bits/stdc++.h>

using namespace std;

long long n,d[3],ma=1e9,a[100069],ps[100069],sm[2],inf=1e18;

void val(long long x)
{
	long long k=upper_bound(a+1,a+n+1,x)-a-1;
	
	sm[0]=x*k-ps[k];
	sm[1]=ps[n]-ps[k]-x*(n-k);
}

long long cal()
{
	long long k=min(sm[0],sm[1]);
	
	return d[0]*(sm[0]-k)+d[1]*(sm[1]-k)+d[2]*k;
}

int main()
{
	long long i,ii,iii,lh,rh,md,zz,br,lb,rb,w[2],z=inf;
	
	scanf("%lld",&n);
	for(i=0;i<3;i++)
	{
		scanf("%lld",d+i);
	}
	d[2]=min(d[2],d[0]+d[1]);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++)
	{
		ps[i]=ps[i-1]+a[i];
	}
	for(lh=0,rh=ma;lh<=rh;)
	{
		md=(lh+rh)/2;
		val(md);
		if(sm[0]<=sm[1])
		{
			zz=md;
			lh=md+1;
		}
		else
		{
			rh=md-1;
		}
	}
	br=zz;
	for(ii=0;ii<2;ii++)
	{
		lb=!ii?0:br;
		rb=!ii?br+1:ma;
		zz=lb;
		for(lh=lb+1,rh=rb;lh<=rh;)
		{
			md=(lh+rh)/2;
			for(iii=0;iii<2;iii++)
			{
				val(md-iii);
				w[iii]=cal();
			}
			if(w[0]<=w[1])
			{
				zz=md;
				lh=md+1;
			}
			else
			{
				rh=md-1;
			}
		}
		val(zz);
		z=min(z,cal());
	}
	printf("%lld\n",z);
}