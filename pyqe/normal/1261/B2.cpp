#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,a[200069],fw[200069],fwp,sq[200069];
pair<long long,long long> pst[200069];
pair<pair<long long,long long>,long long> qq[200069];

void ud(long long x,long long w)
{
	for(fwp=x;fwp<=n;fwp+=fwp&-fwp)
	{
		fw[fwp]+=w;
	}
}

long long qr(long long x)
{
	long long z=0;
	
	for(fwp=x;fwp>0;fwp-=fwp&-fwp)
	{
		z+=fw[fwp];
	}
	return z;
}

int main()
{
	long long t,i,j,k,l,pz,lh,rh,md,zz;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		pst[i]={-a[i],i};
	}
	sort(pst+1,pst+n+1);
	scanf("%lld",&t);
	for(i=0;i<t;i++)
	{
		scanf("%lld%lld",&qq[i].fr.fr,&qq[i].fr.sc);
		qq[i].sc=i;
	}
	sort(qq,qq+t);
	for(j=1,i=0;i<t;i++)
	{
		k=qq[i].fr.fr;
		l=qq[i].fr.sc;
		pz=qq[i].sc;
		for(;j<=k;j++)
		{
			ud(pst[j].sc,1);
		}
		lh=1;
		rh=n;
		for(;lh<=rh;)
		{
			md=(lh+rh)/2;
			if(qr(md)>=l)
			{
				zz=md;
				rh=md-1;
			}
			else
			{
				lh=md+1;
			}
		}
		sq[pz]=a[zz];
	}
	for(i=0;i<t;i++)
	{
		printf("%lld\n",sq[i]);
	}
}