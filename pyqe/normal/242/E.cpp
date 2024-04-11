#include <bits/stdc++.h>

using namespace std;

long long n,a[100069];

struct segtree
{
	long long l,r,sm[20];
	bitset<20> lz;
	segtree *p[2];
	
	void mrg()
	{
		long long i;
		
		for(i=0;i<20;i++)
		{
			sm[i]=p[0]->sm[i]+p[1]->sm[i];
		}
	}
	void bd(long long lh,long long rh)
	{
		l=lh;
		r=rh;
		if(l==r)
		{
			long long i;
			
			for(i=0;i<20;i++)
			{
				sm[i]=a[l]>>i&1;
				lz[i]=0;
			}
		}
		else
		{
			long long ii,md=(l+r)/2;
			
			for(ii=0;ii<2;ii++)
			{
				p[ii]=new segtree;
				p[ii]->bd(!ii?l:md+1,!ii?md:rh);
			}
			mrg();
		}
	}
	void blc()
	{
		long long i,ii;
		
		for(i=0;i<20;i++)
		{
			if(lz[i])
			{
				for(ii=0;ii<2;ii++)
				{
					p[ii]->sm[i]=p[ii]->r-p[ii]->l+1-p[ii]->sm[i];
					p[ii]->lz[i]=!p[ii]->lz[i];
				}
			}
			lz[i]=0;
		}
	}
	void ud(long long lh,long long rh,long long w)
	{
		if(l>rh||r<lh);
		else if(l>=lh&&r<=rh)
		{
			long long i;
			
			for(i=0;i<20;i++)
			{
				if(w>>i&1)
				{
					sm[i]=r-l+1-sm[i];
					lz[i]=!lz[i];
				}
			}
		}
		else
		{
			long long ii;
			
			blc();
			for(ii=0;ii<2;ii++)
			{
				p[ii]->ud(lh,rh,w);
			}
			mrg();
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
			long long i,z=0;
			
			for(i=0;i<20;i++)
			{
				z+=sm[i]<<i;
			}
			return z;
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
	long long t,rr,i,ky,k,l,w;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	sg.bd(1,n);
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld",&ky,&k,&l);
		if(ky==1)
		{
			printf("%lld\n",sg.qr(k,l));
		}
		else if(ky==2)
		{
			scanf("%lld",&w);
			sg.ud(k,l,w);
		}
	}
}