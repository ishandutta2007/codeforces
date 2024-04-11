#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

const long long d=100,inf=1e18;
long long n,m,nn=0,a[200069],as[200069];
pair<long long,long long> rg[400069];

int main()
{
	long long i,k,w,p,p2,c=0,z=0;
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	for(i=1;i<=m;i++)
	{
		scanf("%lld",as+i);
		as[i]+=d;
	}
	sort(as+1,as+m+1);
	as[0]=-inf;
	as[m+1]=inf;
	for(i=1;i<=n;i++)
	{
		p=upper_bound(as+1,as+m+1,i*d)-as-1;
		p2=lower_bound(as+1,as+m+1,i*d)-as;
		w=min(i*d-as[p],as[p2]-i*d);
		if(w)
		{
			nn++;
			rg[nn]={i*d-w,a[i]};
			nn++;
			rg[nn]={i*d+w,-a[i]};
		}
	}
	sort(rg+1,rg+nn+1);
	for(i=1;i<=nn;i++)
	{
		k=rg[i].fr;
		w=rg[i].sc;
		c+=w;
		if(i==nn||k!=rg[i+1].fr)
		{
			z=max(z,c);
		}
	}
	printf("%lld\n",z);
}