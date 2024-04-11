#include <bits/stdc++.h>

using namespace std;

long long n,ma=2e5,a[200069],fq[200069];
multiset<long long> vl[200069];

struct segtree
{
	long long l,r,mn,sm,lx,rx,mx,lz;
	segtree *p[2];
	
	void mrg()
	{
		mn=min(p[0]->mn,p[1]->mn);
		sm=p[0]->sm*(p[0]->mn==mn)+p[1]->sm*(p[1]->mn==mn)+max(p[0]->rx,p[1]->lx)*(max(p[0]->mn,p[1]->mn)==mn);
		lx=p[0]->lx*(p[0]->mn==mn)+max(p[0]->mx,p[1]->lx)*(p[0]->mn!=mn);
		rx=p[1]->rx*(p[1]->mn==mn)+max(p[1]->mx,p[0]->rx)*(p[1]->mn!=mn);
		mx=max(p[0]->mx,p[1]->mx);
	}
	void bd(long long lh,long long rh)
	{
		l=lh;
		r=rh;
		lz=0;
		if(l==r)
		{
			mn=0;
			sm=0;
			lx=0;
			rx=0;
			mx=0;
		}
		else
		{
			long long ii,md=(l+r)/2;
			
			for(ii=0;ii<2;ii++)
			{
				p[ii]=new segtree;
				p[ii]->bd(!ii?l:md+1,!ii?md:r);
			}
			mrg();
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
			mrg();
		}
	}
	void ins(long long x,long long w)
	{
		if(l>x||r<x);
		else if(l>=x&&r<=x)
		{
			lx=w;
			mx=w;
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
}
sg;

void ud(bool ky,long long x)
{
	if(fq[x])
	{
		long long u=2ll*!ky-1,k,l;
		
		k=*vl[x].begin();
		l=*prev(vl[x].end());
		sg.ud(k,l-1,u);
		sg.ins(k,fq[x]*!ky);
	}
}

int main()
{
	long long t,rr,i,k,l;
	
	scanf("%lld%lld",&n,&t);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		vl[a[i]].insert(i);
		fq[a[i]]++;
	}
	sg.bd(1,n);
	for(i=1;i<=ma;i++)
	{
		ud(0,i);
	}
	for(rr=0;rr<=t;rr++)
	{
		if(rr)
		{
			scanf("%lld%lld",&k,&l);
			ud(1,a[k]);
			ud(1,l);
			vl[a[k]].erase(k);
			fq[a[k]]--;
			vl[l].insert(k);
			fq[l]++;
			ud(0,a[k]);
			ud(0,l);
			a[k]=l;
		}
		printf("%lld\n",n-sg.sm-sg.lx);
	}
}