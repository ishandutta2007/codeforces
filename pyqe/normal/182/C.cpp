#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,d,a[100069],fw[2][100069],fi,inf=1e18;
pair<long long,long long> as[100069];

void ud(long long xx,long long x,long long w)
{
	for(fi=x;fi<=n;fi+=fi&-fi)
	{
		fw[xx][fi]+=w;
	}
}

long long qr(long long xx,long long lh,long long rh)
{
	long long z=0;
	
	for(fi=rh;fi;fi-=fi&-fi)
	{
		z+=fw[xx][fi];
	}
	for(fi=lh-1;fi;fi-=fi&-fi)
	{
		z-=fw[xx][fi];
	}
	return z;
}

int main()
{
	long long i,ub=0,lh,rh,md,zz,z=-inf;
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		as[i]={a[i],i};
	}
	scanf("%lld",&d);
	sort(as+1,as+n+1);
	for(i=1;i<=n;i++)
	{
		a[i]=lower_bound(as+1,as+n+1,mp(a[i],i))-as;
		if(as[i].fr<0)
		{
			ub=i;
		}
	}
	for(i=1;i<=n;i++)
	{
		ud(0,a[i],1);
		ud(1,a[i],as[a[i]].fr);
		if(i>m)
		{
			ud(0,a[i-m],-1);
			ud(1,a[i-m],-as[a[i-m]].fr);
		}
		if(i>=m)
		{
			for(lh=0,rh=ub;lh<=rh;)
			{
				md=(lh+rh)/2;
				if(qr(0,1,md)<=d)
				{
					zz=md;
					lh=md+1;
				}
				else
				{
					rh=md-1;
				}
			}
			z=max(z,abs(qr(1,zz+1,n)-qr(1,1,zz)));
			for(lh=ub+1,rh=n+1;lh<=rh;)
			{
				md=(lh+rh)/2;
				if(qr(0,md,n)<=d)
				{
					zz=md;
					rh=md-1;
				}
				else
				{
					lh=md+1;
				}
			}
			z=max(z,abs(qr(1,1,zz-1)-qr(1,zz,n)));
		}
	}
	printf("%lld\n",z);
}