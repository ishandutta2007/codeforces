#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,nn,dsu[1069],a[1069],zs=0;
pair<long long,pair<long long,long long>> ed[250069];
pair<long long,long long> sq[1069];

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
	long long i,j,ii,k,l,w;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%lld",&k);
			ed[(i-1)*n+j]={k,{i,j}};
			if(i==j)
			{
				a[i]=k;
			}
		}
		dsu[i]=i;
	}
	sort(ed+1,ed+n*n+1);
	nn=n;
	for(i=1;i<=n*n;i++)
	{
		w=ed[i].fr;
		k=ed[i].sc.fr;
		l=ed[i].sc.sc;
		if(fd(k)!=fd(l))
		{
			if(a[fd(k)]<a[fd(l)])
			{
				swap(k,l);
			}
			if(a[fd(k)]<w)
			{
				nn++;
				a[nn]=w;
				dsu[nn]=nn;
				for(ii=0;ii<2;ii++)
				{
					zs++;
					sq[zs]={fd(k),nn};
					dsu[fd(k)]=nn;
					swap(k,l);
				}
			}
			else
			{
				zs++;
				sq[zs]={fd(l),fd(k)};
				dsu[fd(l)]=fd(k);
			}
		}
	}
	printf("%lld\n",nn);
	for(i=1;i<=nn;i++)
	{
		printf("%lld%c",a[i]," \n"[i==nn]);
	}
	printf("%lld\n",nn);
	for(i=1;i<=zs;i++)
	{
		k=sq[i].fr;
		l=sq[i].sc;
		printf("%lld %lld\n",k,l);
	}
}