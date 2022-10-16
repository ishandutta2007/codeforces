#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,d,a[500069],dsu[500069],ls[500069],p2[500069],dv=1e9+7;
pair<long long,long long> ed[500069],as[500069];

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
	long long i,k,l,w,pz,c,z;
	
	scanf("%lld%lld%lld",&n,&m,&d);
	p2[0]=1;
	for(i=1;i<=max(n,d);i++)
	{
		p2[i]=p2[i-1]*2%dv;
	}
	z=p2[d]*p2[n]%dv;
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	for(i=1;i<=m;i++)
	{
		scanf("%lld%lld",&k,&l);
		ed[i]={k,l};
		as[i]={a[k]^a[l],i};
	}
	sort(as+1,as+m+1);
	for(i=1;i<=n;i++)
	{
		ls[i]=-1;
	}
	c=n;
	for(i=1;i<=m;i++)
	{
		w=as[i].fr;
		pz=as[i].sc;
		k=ed[pz].fr;
		l=ed[pz].sc;
		if(ls[k]<w)
		{
			dsu[k]=k;
			ls[k]=w;
		}
		if(ls[l]<w)
		{
			dsu[l]=l;
			ls[l]=w;
		}
		c-=fd(k)!=fd(l);
		dsu[fd(l)]=fd(k);
		if(i==m||w<as[i+1].fr)
		{
			z=(z+dv-p2[n]+p2[c])%dv;
			c=n;
		}
	}
	printf("%lld\n",z);
}