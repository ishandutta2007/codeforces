#include <bits/stdc++.h>

using namespace std;

const long long inf=1e18;
long long n,d,a[200069];

inline long long val(long long x,long long y)
{
	long long k,z=0;
	
	k=x/(y+1);
	z+=k*k*(y+1-x%(y+1));
	k++;
	z+=k*k*(x%(y+1));
	return z;
}

int main()
{
	long long i,lh,rh,md,zz,sm,c,lh2,rh2,md2,zz2,zm,zc;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	for(i=n;i;i--)
	{
		a[i]-=a[i-1];
	}
	scanf("%lld",&d);
	for(lh=2,rh=inf;lh<=rh;)
	{
		md=(lh+rh)/2;
		sm=0;
		c=0;
		for(i=1;i<=n;i++)
		{
			for(zz2=0,lh2=1,rh2=a[i]-1;lh2<=rh2;)
			{
				md2=(lh2+rh2)/2;
				if(val(a[i],md2-1)-val(a[i],md2)>=md)
				{
					zz2=md2;
					lh2=md2+1;
				}
				else
				{
					rh2=md2-1;
				}
			}
			sm+=val(a[i],zz2);
			c+=zz2;
		}
		if(sm<=d)
		{
			zz=md;
			zm=sm;
			zc=c;
			lh=md+1;
		}
		else
		{
			rh=md-1;
		}
	}
	printf("%lld\n",zc-(d-zm)/zz);
}