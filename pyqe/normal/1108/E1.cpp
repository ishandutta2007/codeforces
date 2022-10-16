#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,nn=0,a[100069],as[669],mn[669],mx[669],fq[669],sq[369],zs=0,inf=1e18;
pair<long long,long long> rg[369];

int main()
{
	long long i,j,ii,k,l,sz,w,sm,e;
	pair<long long,long long> z={0,-1};
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	for(i=1;i<=m;i++)
	{
		scanf("%lld%lld",&k,&l);
		k--;
		rg[i]={k,l};
		nn++;
		as[nn]=k;
		nn++;
		as[nn]=l;
	}
	nn++;
	as[nn]=0;
	nn++;
	as[nn]=n;
	sort(as+1,as+nn+1);
	sz=nn;
	nn=0;
	for(i=1;i<=sz;i++)
	{
		nn+=!nn||as[i]!=as[nn];
		as[nn]=as[i];
		mn[nn]=inf;
		mx[nn]=-inf;
	}
	for(i=1;i<=m;i++)
	{
		k=rg[i].fr;
		l=rg[i].sc;
		for(ii=0;ii<2;ii++)
		{
			k=lower_bound(as+1,as+nn+1,k)-as;
			swap(k,l);
		}
		rg[i]={k,l};
	}
	for(i=2;i<=nn;i++)
	{
		for(j=as[i-1]+1;j<=as[i];j++)
		{
			mn[i]=min(mn[i],a[j]);
			mx[i]=max(mx[i],a[j]);
		}
	}
	for(i=2;i<=nn;i++)
	{
		for(j=1;j<=m;j++)
		{
			k=rg[j].fr;
			l=rg[j].sc;
			if(k>=i||l<i)
			{
				fq[k]--;
				fq[l]++;
			}
		}
		w=inf;
		sm=0;
		for(j=1;j<=nn;j++)
		{
			w=min(w,mn[j]+sm);
			sm+=fq[j];
			fq[j]=0;
		}
		z=max(z,{mx[i]-w,i});
	}
	e=z.sc;
	for(i=1;i<=m;i++)
	{
		k=rg[i].fr;
		l=rg[i].sc;
		if(k>=e||l<e)
		{
			zs++;
			sq[zs]=i;
		}
	}
	printf("%lld\n%lld\n",z.fr,zs);
	for(i=1;i<=zs;i++)
	{
		printf("%lld%c",sq[i]," \n"[i==zs]);
	}
}