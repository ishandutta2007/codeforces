#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,ne=0,a[2][100069],vl[100069],dsu[100069],inf=1e18;
pair<long long,long long> ed[200069],as[200069];

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
	long long i,j,ii,k,l,w,p,sz,mx,e,z=0;
	pair<long long,long long> mxe;
	
	scanf("%lld%lld",&m,&n);
	for(ii=0;ii<2;ii++)
	{
		for(i=1;i<=m;i++)
		{
			scanf("%lld",&a[ii][i]);
		}
		swap(n,m);
	}
	for(i=1;i<=m;i++)
	{
		scanf("%lld",&sz);
		mxe={-inf,-1};
		for(j=1;j<=sz;j++)
		{
			scanf("%lld",vl+j);
			z+=a[0][i]+a[1][vl[j]];
			mxe=max(mxe,{a[0][i]+a[1][vl[j]],vl[j]});
		}
		mx=mxe.fr;
		e=mxe.sc;
		z-=mx;
		for(j=1;j<=sz;j++)
		{
			if(vl[j]!=e)
			{
				ne++;
				ed[ne]={e,vl[j]};
				as[ne]={a[0][i]+a[1][vl[j]],ne};
			}
		}
	}
	sort(as+1,as+ne+1,greater<pair<long long,long long>>());
	for(i=1;i<=n;i++)
	{
		dsu[i]=i;
	}
	for(i=1;i<=ne;i++)
	{
		w=as[i].fr;
		p=as[i].sc;
		k=ed[p].fr;
		l=ed[p].sc;
		z-=w*(fd(k)!=fd(l));
		dsu[fd(l)]=fd(k);
	}
	printf("%lld\n",z);
}