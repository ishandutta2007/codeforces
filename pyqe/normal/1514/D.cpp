#include <bits/stdc++.h>

using namespace std;

long long n;

struct segtree
{
	long long l,r,sm;
	segtree *p[2];
	
	void bd(long long lh,long long rh)
	{
		l=lh;
		r=rh;
		sm=0;
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
	void ud(long long x,long long w)
	{
		if(l>=x&&r<=x)
		{
			sm+=w;
		}
		else
		{
			long long ii;
			segtree *tmp;
			
			for(ii=0;ii<2;ii++)
			{
				if(!(p[ii]->l>x||p[ii]->r<x))
				{
					tmp=p[ii];
					p[ii]=new segtree;
					*p[ii]=*tmp;
					p[ii]->ud(x,w);
				}
			}
			sm=p[0]->sm+p[1]->sm;
		}
	}
	long long qr(long long x,segtree *sr)
	{
		if(sm-sr->sm<x)
		{
			return 0;
		}
		else if(l==r)
		{
			return sm-sr->sm;
		}
		else
		{
			return max(p[0]->qr(x,sr->p[0]),p[1]->qr(x,sr->p[1]));
		}
	}
}
sg[300069];

int main()
{
	long long t,rr,i,k,l,w;
	
	scanf("%lld%lld",&n,&t);
	sg[0].bd(1,n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		sg[i]=sg[i-1];
		sg[i].ud(k,1);
	}
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&k,&l);
		w=sg[l].qr((l-k+2)/2,&sg[k-1]);
		printf("%lld\n",max(w-(l-k+1-w),1ll));
	}
}