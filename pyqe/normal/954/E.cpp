#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,d,nn[2],aa[1000069];
pair<long long,long long> a[2][1000069];

int main()
{
	long long i,ii,k,l,w,e,sm,mn=1e18;
	double z=0;
	
	scanf("%lld%lld",&n,&d);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",aa+i);
	}
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		k-=d;
		if(!k)
		{
			z+=aa[i];
			continue;
		}
		e=k<0;
		k=abs(k);
		nn[e]++;
		a[e][nn[e]]={k,aa[i]};
	}
	for(ii=0;ii<2;ii++)
	{
		sort(a[ii]+1,a[ii]+nn[ii]+1);
		sm=0;
		for(i=1;i<=nn[ii];i++)
		{
			k=a[ii][i].fr;
			l=a[ii][i].sc;
			sm+=k*l;
		}
		mn=min(mn,sm);
	}
	for(ii=0;ii<2;ii++)
	{
		sm=mn;
		for(i=1;i<=nn[ii];i++)
		{
			k=a[ii][i].fr;
			l=a[ii][i].sc;
			w=min(k*l,sm);
			z+=(double)w/k;
			sm-=w;
		}
	}
	printf("%.15lf\n",z);
}