#include <bits/stdc++.h>

using namespace std;

long long n,m;

bool qr(long long ky,long long lh,long long rh,long long lh2,long long rh2)
{
	long long w,w2,y,x,y2,x2,e;
	
	if(lh>rh)
	{
		return 1;
	}
	w=rh-lh+1;
	w2=m;
	y=lh;
	x=1;
	y2=lh2;
	x2=1;
	if(ky)
	{
		swap(w,w2);
		swap(y,x);
		swap(y2,x2);
	}
	printf("? %lld %lld %lld %lld %lld %lld\n",w,w2,y,x,y2,x2);
	fflush(stdout);
	scanf("%lld",&e);
	return e;
}

int main()
{
	long long i,j,ii,k,ml,c,lh,rh,md,zz,z=1;
	
	scanf("%lld%lld",&n,&m);
	for(ii=0;ii<2;ii++)
	{
		k=n;
		ml=1;
		for(i=2;i<=k;i++)
		{
			for(c=0;k%i==0;k/=i,c++);
			for(zz=0,lh=1,rh=c;lh<=rh;)
			{
				md=(lh+rh)/2;
				for(j=0;j<md;j++)
				{
					ml*=i;
				}
				if((ml%2==0&&qr(ii,1,n/2,n/2+1,n)&&qr(ii,n/ml+1,n/2,n/2+1,n-n/ml))||(ml%2&&qr(ii,1,n/ml*(ml/2),n/ml*(ml/2)+1,n-n/ml)&&qr(ii,n/ml+1,n/ml*(ml/2+1),n/ml*(ml/2+1)+1,n)))
				{
					zz=md;
					lh=md+1;
				}
				else
				{
					rh=md-1;
				}
				for(j=0;j<md;j++)
				{
					ml/=i;
				}
			}
			for(j=0;j<zz;j++)
			{
				ml*=i;
			}
		}
		c=0;
		for(i=1;i<=ml;i++)
		{
			c+=ml%i==0;
		}
		z*=c;
		swap(n,m);
	}
	printf("! %lld\n",z);
	fflush(stdout);
}