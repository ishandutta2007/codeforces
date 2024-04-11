#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,nn=0,a[300069],pst[300069],pn[300069],qq[300069],fw[300069],fi,sq[300069],inf=1e18;
pair<long long,long long> qs[300069];

struct segtree
{
	long long l,r,mn,rp,lz;
	segtree *p[2];
	
	void bd(long long lh,long long rh)
	{
		l=lh;
		r=rh;
		lz=0;
		if(l==r)
		{
			mn=a[l];
			rp=l;
		}
		else
		{
			long long ii,md=(l+r)/2;
			
			for(ii=0;ii<2;ii++)
			{
				p[ii]=new segtree;
				p[ii]->bd(!ii?l:md+1,!ii?md:r);
			}
			mn=min(p[0]->mn,p[1]->mn);
			rp=-inf;
			for(ii=0;ii<2;ii++)
			{
				if(p[ii]->mn==mn)
				{
					rp=max(rp,p[ii]->rp);
				}
			}
		}
	}
	void blc()
	{
		long long ii;
		
		for(ii=0;ii<2;ii++)
		{
			p[ii]->mn+=lz;
			p[ii]->lz+=lz;
		}
		lz=0;
	}
	void ud(long long lh,long long rh,long long w)
	{
		if(l>rh||r<lh);
		else if(l>=lh&&r<=rh)
		{
			mn+=w;
			lz+=w;
		}
		else
		{
			long long ii;
			
			blc();
			for(ii=0;ii<2;ii++)
			{
				p[ii]->ud(lh,rh,w);
			}
			mn=min(p[0]->mn,p[1]->mn);
			rp=-inf;
			for(ii=0;ii<2;ii++)
			{
				if(p[ii]->mn==mn)
				{
					rp=max(rp,p[ii]->rp);
				}
			}
		}
	}
}
sg;

void ud(long long x,long long w)
{
	for(fi=x;fi<=nn;fi+=fi&-fi)
	{
		fw[fi]+=w;
	}
}

long long qr(long long x)
{
	long long z=0;
	
	for(fi=x;fi;fi-=fi&-fi)
	{
		z+=fw[fi];
	}
	return z;
}

int main()
{
	long long t,rr,i,k,l,w,pz;
	
	scanf("%lld%lld",&n,&t);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		a[i]=i-k;
		if(a[i]<0)
		{
			a[i]=inf;
		}
		pst[i]=inf;
	}
	sg.bd(1,n);
	for(;!sg.mn;)
	{
		k=sg.rp;
		nn++;
		pst[k]=nn;
		sg.ud(k,k,inf);
		sg.ud(k,n,-1);
	}
	pn[0]=nn+1;
	for(i=1;i<=n;i++)
	{
		pn[i]=min(pn[i-1],pst[i]);
	}
	for(rr=1;rr<=t;rr++)
	{
		scanf("%lld%lld",&k,&l);
		qq[rr]=pn[k]-1;
		qs[rr]={n-l,rr};
	}
	sort(qs+1,qs+t+1);
	for(i=0,rr=1;rr<=t;rr++)
	{
		w=qs[rr].fr;
		pz=qs[rr].sc;
		k=qq[pz];
		for(;i<w;)
		{
			i++;
			ud(pst[i],1);
		}
		sq[pz]=qr(k);
	}
	for(rr=1;rr<=t;rr++)
	{
		printf("%lld\n",sq[rr]);
	}
}