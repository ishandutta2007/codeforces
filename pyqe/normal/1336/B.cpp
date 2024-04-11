#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long nn[3],n[3],aa[100069],a[3][100069],inf=4e18;

long long val(array<long long,3> x)
{
	long long i,k,sm=0;
	
	for(i=0;i<3;i++)
	{
		k=x[i]-x[(i+1)%3];
		sm+=k*k;
	}
	return sm;
}

int main()
{
	long long t,rr,i,j,r,ii,k,pm[3],lh,rh,md,zz,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		for(i=0;i<3;i++)
		{
			scanf("%lld",nn+i);
		}
		for(i=0;i<3;i++)
		{
			for(j=1;j<=nn[i];j++)
			{
				scanf("%lld",aa+j);
			}
			sort(aa+1,aa+nn[i]+1);
			n[i]=0;
			for(j=1;j<=nn[i];j++)
			{
				if(j==1||aa[j]>aa[j-1])
				{
					n[i]++;
					a[i][n[i]]=aa[j];
				}
			}
		}
		z=inf;
		for(i=0;i<3;i++)
		{
			for(ii=0;ii<2;ii++)
			{
				for(j=0;j<3;j++)
				{
					pm[j]=(i+j*(1+ii))%3;
				}
				for(r=1,j=1;j<=n[pm[0]];j++)
				{
					for(;r<=n[pm[1]]&&a[pm[1]][r]<a[pm[0]][j];r++);
					if(r<=n[pm[1]])
					{
						zz=1;
						for(lh=2,rh=n[pm[2]];lh<=rh;)
						{
							md=(lh+rh)/2;
							if(val({a[pm[0]][j],a[pm[1]][r],a[pm[2]][md]})<=val({a[pm[0]][j],a[pm[1]][r],a[pm[2]][md-1]}))
							{
								zz=md;
								lh=md+1;
							}
							else
							{
								rh=md-1;
							}
						}
						z=min(z,val({a[pm[0]][j],a[pm[1]][r],a[pm[2]][zz]}));
					}
				}
			}
		}
		printf("%lld\n",z);
	}
}