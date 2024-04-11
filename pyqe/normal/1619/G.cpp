#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

const long long inf=1e18;
long long n,d,nn,a[200069],dsu[200069],ex[200069];
pair<pair<long long,long long>,long long> as[200069];

long long fd(long long x)
{
	if(dsu[x]!=x)
	{
		dsu[x]=fd(dsu[x]);
	}
	return dsu[x];
}

int main()
{
	long long t,rr,i,ii,l,y,x,p,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		for(i=1;i<=n;i++)
		{
			scanf("%lld%lld%lld",&y,&x,a+i);
			as[i]={{y,x},i};
			dsu[i]=i;
		}
		for(ii=0;ii<2;ii++)
		{
			sort(as+1,as+n+1);
			for(i=1;i<=n;i++)
			{
				y=as[i].fr.fr;
				x=as[i].fr.sc;
				p=as[i].sc;
				if(i>1&&y==as[i-1].fr.fr&&x-as[i-1].fr.sc<=d)
				{
					l=as[i-1].sc;
					a[fd(p)]=min(a[fd(p)],a[fd(l)]);
					dsu[fd(l)]=fd(p);
				}
			}
			for(i=1;i<=n;i++)
			{
				swap(as[i].fr.fr,as[i].fr.sc);
			}
		}
		nn=0;
		for(i=1;i<=n;i++)
		{
			if(fd(i)==i)
			{
				nn++;
				ex[nn]=a[i];
			}
		}
		sort(ex+1,ex+nn+1,greater<long long>());
		ex[nn+1]=-inf;
		z=inf;
		for(i=1;i<=nn;i++)
		{
			z=min(z,max(i-1,ex[i+1]));
		}
		printf("%lld\n",z);
	}
}