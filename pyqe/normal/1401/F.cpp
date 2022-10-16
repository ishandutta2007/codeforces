#include <bits/stdc++.h>

using namespace std;

long long nh,n,a[300069];

struct segtree
{
	long long l,r,lz[18],sm,dh;
	segtree *p[2];
	
	void bd(long long lh,long long rh)
	{
		long long i;
		
		l=lh;
		r=rh;
		for(i=0;i<nh;i++)
		{
			lz[i]=0;
		}
		if(l==r)
		{
			sm=a[l];
		}
		else
		{
			long long ii,md=(l+r)/2;
			
			for(ii=0;ii<2;ii++)
			{
				p[ii]=new segtree;
				p[ii]->dh=dh-1;
				p[ii]->bd(!ii?l:md+1,!ii?md:r);
			}
			sm=p[0]->sm+p[1]->sm;
		}
	}
	void blc()
	{
		long long i,ii,md=(l+r)/2;
		
		if(lz[dh-1])
		{
			swap(p[0],p[1]);
		}
		p[0]->l=l;
		p[0]->r=md;
		p[1]->l=md+1;
		p[1]->r=r;
		for(i=0;i<nh;i++)
		{
			for(ii=0;ii<2;ii++)
			{
				p[ii]->lz[i]^=lz[i];
			}
			lz[i]=0;
		}
	}
	void ud(long long x,long long w)
	{
		if(l>x||r<x);
		else if(l>=x&&r<=x)
		{
			sm=w;
		}
		else
		{
			long long ii;
			
			blc();
			for(ii=0;ii<2;ii++)
			{
				p[ii]->ud(x,w);
			}
			sm=p[0]->sm+p[1]->sm;
		}
	}
	long long qr(long long lh,long long rh)
	{
		if(l>rh||r<lh)
		{
			return 0;
		}
		else if(l>=lh&&r<=rh)
		{
			return sm;
		}
		else
		{
			blc();
			return p[0]->qr(lh,rh)+p[1]->qr(lh,rh);
		}
	}
}
sg;

int main()
{
	long long t,rr,i,ky,k,l;
	
	scanf("%lld%lld",&nh,&t);
	n=1ll<<nh;
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	sg.dh=nh;
	sg.bd(1,n);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&ky,&k);
		if(ky==1)
		{
			scanf("%lld",&l);
			sg.ud(k,l);
		}
		else if(ky==2)
		{
			for(i=0;i<k;i++)
			{
				sg.lz[i]^=1;
			}
		}
		else if(ky==3)
		{
			sg.lz[k]^=1;
		}
		else
		{
			scanf("%lld",&l);
			printf("%lld\n",sg.qr(k,l));
		}
	}
}