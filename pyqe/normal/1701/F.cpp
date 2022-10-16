#include <bits/stdc++.h>

using namespace std;

const long long ma=2e5;
long long d;
bitset<200069> vtd;

inline long long tri(long long x)
{
	return x*(x-1)/2;
}

struct segtree
{
	long long l,r,c,sm,sm2,lz;
	segtree *p[2];
	
	void bd(long long lh,long long rh)
	{
		l=lh;
		r=rh;
		c=0;
		sm=0;
		sm2=0;
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
	inline void ad(long long w)
	{
		sm2+=sm*w+c*tri(w);
		sm+=c*w;
		lz+=w;
	}
	inline void blc()
	{
		long long ii;
		
		for(ii=0;ii<2;ii++)
		{
			p[ii]->ad(lz);
		}
		lz=0;
	}
	inline void mrg()
	{
		sm2=p[0]->sm2+p[1]->sm2;
		sm=p[0]->sm+p[1]->sm;
		c=p[0]->c+p[1]->c;
	}
	void ins(long long x,long long w)
	{
		if(l>x||r<x);
		else if(l>=x&&r<=x)
		{
			sm2=tri(w);
			sm=w;
			c=1;
		}
		else
		{
			long long ii;
			
			blc();
			for(ii=0;ii<2;ii++)
			{
				p[ii]->ins(x,w);
			}
			mrg();
		}
	}
	void ers(long long x)
	{
		if(l>x||r<x);
		else if(l>=x&&r<=x)
		{
			sm2=0;
			sm=0;
			c=0;
		}
		else
		{
			long long ii;
			
			blc();
			for(ii=0;ii<2;ii++)
			{
				p[ii]->ers(x);
			}
			mrg();
		}
	}
	void udr(long long lh,long long rh,long long w)
	{
		if(l>rh||r<lh);
		else if(l>=lh&&r<=rh)
		{
			ad(w);
		}
		else
		{
			long long ii;
			
			blc();
			for(ii=0;ii<2;ii++)
			{
				p[ii]->udr(lh,rh,w);
			}
			mrg();
		}
	}
	long long qrc(long long lh,long long rh)
	{
		if(l>rh||r<lh)
		{
			return 0;
		}
		else if(l>=lh&&r<=rh)
		{
			return c;
		}
		else
		{
			blc();
			return p[0]->qrc(lh,rh)+p[1]->qrc(lh,rh);
		}
	}
}
sg;

int main()
{
	long long t,rr,k,w;
	
	scanf("%lld%lld",&t,&d);
	sg.bd(1,ma);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&k);
		if(!vtd[k])
		{
			w=sg.qrc(max(k-d,1ll),k-1);
			sg.ins(k,w);
			sg.udr(k+1,min(k+d,ma),1);
		}
		else
		{
			sg.ers(k);
			sg.udr(k+1,min(k+d,ma),-1);
		}
		vtd[k]=!vtd[k];
		printf("%lld\n",sg.sm2);
	}
}