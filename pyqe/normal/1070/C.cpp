#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,d,m,fw[2][1000069],fwp;
pair<long long,pair<long long,long long>> a[400069];

void ud(long long p,long long x,long long w)
{
	for(fwp=x;fwp<=1000000;fwp+=fwp&-fwp)
	{
		fw[p][fwp]+=w;
	}
}

long long qr(long long p,long long x)
{
	long long z=0;
	
	for(fwp=x;fwp>0;fwp-=fwp&-fwp)
	{
		z+=fw[p][fwp];
	}
	return z;
}

int main()
{
	long long i,j,z=0,lh,rh,md,zz,k,l,kk;
	
	scanf("%lld%lld%lld",&n,&d,&m);
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld%lld%lld",&lh,&rh,&k,&l);
		a[i*2]={lh,{k,l}};
		a[i*2+1]={rh+1,{-k,l}};
	}
	sort(a,a+m+m);
	j=0;
	for(i=1;i<=n;i++)
	{
		for(;j<m+m&&a[j].fr<=i;j++)
		{
			k=a[j].sc.fr;
			l=a[j].sc.sc;
			ud(0,l,k);
			ud(1,l,k*l);
		}
		lh=0;
		rh=1000001;
		for(md=(lh+rh)/2;lh<=rh;md=(lh+rh)/2)
		{
			if(qr(0,md)<=d)
			{
				zz=md;
				lh=md+1;
			}
			else
			{
				rh=md-1;
			}
		}
		k=qr(0,zz);
		kk=qr(1,zz);
		z+=kk;
		if(zz<=1000000)
		{
			z+=(d-k)*(zz+1);
		}
	}
	printf("%lld\n",z);
}