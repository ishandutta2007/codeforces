#include <bits/stdc++.h>

using namespace std;

const long long ma=2e5+69;
long long n,a[200069];

struct segtree
{
	long long l,r,sm,lz;
	segtree *p[2];
	
	void bd(long long lh,long long rh)
	{
		l=lh;
		r=rh;
		sm=0;
		lz=0;
		if(l<r)
		{
			long long ii,md=(l+r)/2;
			
			for(ii=0;ii<2;ii++)
			{
				p[ii]=new segtree;
				p[ii]->bd(!ii?l:md+1,!ii?md:r);
			}
		}
	}
	inline void blc()
	{
		long long ii;
		
		for(ii=0;ii<2;ii++)
		{
			p[ii]->sm+=lz*(p[ii]->r-p[ii]->l+1);
			p[ii]->lz+=lz;
		}
		lz=0;
	}
	void ud(long long lh,long long rh,long long w)
	{
		if(l>rh||r<lh);
		else if(l>=lh&&r<=rh)
		{
			sm+=w*(r-l+1);
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
			sm=(p[0]->sm+p[1]->sm);
		}
	}
	long long qr(long long lh,long long rh,long long e)
	{
		if(l>rh||r<lh)
		{
			return 0;
		}
		else if(l>=lh&&r<=rh)
		{
			return (r-l+1)*!e+sm*(e*2-1);
		}
		else
		{
			blc();
			return p[0]->qr(lh,rh,e)+p[1]->qr(lh,rh,e);
		}
	}
	long long bl(long long w,long long e)
	{
		if(l==r)
		{
			return l;
		}
		else
		{
			long long k;
			
			blc();
			k=(p[0]->r-p[0]->l+1)*!e+p[0]->sm*(e*2-1);
			if(w<k)
			{
				return p[0]->bl(w,e);
			}
			else
			{
				return p[1]->bl(w-k,e);
			}
		}
	}
}
sg;

inline void udd(long long x,long long e)
{
	long long k,p;
	
	k=sg.qr(1,x-1,!e);
	p=sg.bl(k,!e);
	sg.ud(x,p-1,!e*2-1);
	sg.ud(p,p,e*2-1);
}

inline long long qrr()
{
	long long k,p;
	
	k=sg.qr(1,ma,1);
	p=sg.bl(k-1,1);
	return p;
}

int main()
{
	long long t,rr,i,k,l;
	
	scanf("%lld%lld",&n,&t);
	sg.bd(1,ma);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		udd(a[i],1);
	}
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&k,&l);
		udd(a[k],0);
		a[k]=l;
		udd(l,1);
		printf("%lld\n",qrr());
	}
}