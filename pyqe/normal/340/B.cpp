#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,nn,cx[2069],inf=1e18;
pair<long long,long long> a[1069];
bitset<1069> spc;

bool dt(long long p1,long long p2,long long p3)
{
	return (a[p2].fr-a[p3].fr)*(a[p1].sc-a[p3].sc)<=(a[p1].fr-a[p3].fr)*(a[p2].sc-a[p3].sc);
}

long long sho(long long p1,long long p2,long long p3)
{
	return abs(a[p1].fr*a[p2].sc+a[p2].fr*a[p3].sc+a[p3].fr*a[p1].sc-a[p1].sc*a[p2].fr-a[p2].sc*a[p3].fr-a[p3].sc*a[p1].fr);
}

int main()
{
	long long i,j,ii,u,y,x,k,l=0,ti,tj,lh,rh,md,zz,sm,z=-inf;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld%lld",&y,&x);
		a[i]={y,x};
	}
	sort(a+1,a+n+1);
	for(ii=0;ii<2;ii++)
	{
		u=!ii*2-1;
		for(i=1+(n-1)*ii;i&&i<=n;i+=u)
		{
			for(;nn-l>=2&&dt(i,cx[nn],cx[nn-1]);nn--);
			nn++;
			cx[nn]=i;
		}
		nn--;
		l=nn;
	}
	for(i=nn+1;i<=nn*2;i++)
	{
		cx[i]=cx[i-nn];
		spc[cx[i]]=1;
	}
	if(nn>=4)
	{
		for(i=1;i<=nn;i++)
		{
			for(j=i+2;j<=min(i+nn-2,nn);j++)
			{
				ti=i;
				tj=j;
				sm=0;
				for(ii=0;ii<2;ii++)
				{
					for(lh=ti+1,rh=tj-1;lh<=rh;)
					{
						md=(lh+rh)/2;
						k=sho(cx[ti],cx[md],cx[tj]);
						if(md==ti+1||k>=sho(cx[ti],cx[md-1],cx[tj]))
						{
							zz=k;
							lh=md+1;
						}
						else
						{
							rh=md-1;
						}
					}
					sm+=zz;
					ti+=nn;
					swap(ti,tj);
				}
				z=max(z,sm);
			}
		}
	}
	else
	{
		k=sho(cx[1],cx[2],cx[3]);
		for(i=1;i<=n;i++)
		{
			if(!spc[i])
			{
				for(j=1;j<=3;j++)
				{
					z=max(z,k-sho(cx[j],cx[j%3+1],i));
				}
			}
		}
	}
	printf("%lld.%lld00000\n",z/2,z%2*5);
}