#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,d,nn[2],mn[100069],sq[100069],inf=1e13;
pair<long long,pair<long long,long long>> a[2][100069];

int main()
{
	long long i,j,ii,k,l,l2,w,e,sm,z=inf;
	
	scanf("%lld%lld%lld",&n,&m,&d);
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld%lld%lld",&k,&l,&l2,&w);
		e=!l;
		l+=l2;
		nn[e]++;
		a[e][nn[e]]={k,{l,w}};
	}
	for(ii=0;ii<2;ii++)
	{
		sort(a[ii]+1,a[ii]+nn[ii]+1);
	}
	sm=0;
	for(i=1;i<=n;i++)
	{
		mn[i]=inf;
		sm+=mn[i];
	}
	for(i=1;i<=nn[0];i++)
	{
		l=a[0][i].sc.fr;
		w=a[0][i].sc.sc;
		sm-=mn[l];
		mn[l]=min(mn[l],w);
		sm+=mn[l];
		sq[i]=sm;
	}
	sm=0;
	for(i=1;i<=n;i++)
	{
		mn[i]=inf;
		sm+=mn[i];
	}
	for(j=nn[1],i=nn[0];i;i--)
	{
		k=a[0][i].fr;
		for(;j&&a[1][j].fr>k+d;j--)
		{
			l=a[1][j].sc.fr;
			w=a[1][j].sc.sc;
			sm-=mn[l];
			mn[l]=min(mn[l],w);
			sm+=mn[l];
		}
		sq[i]+=sm;
		z=min(z,sq[i]);
	}
	if(z==inf)
	{
		z=-1;
	}
	printf("%lld\n",z);
}