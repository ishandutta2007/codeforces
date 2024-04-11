#include <bits/stdc++.h>

using namespace std;

long long n,d,fq[100069];
vector<long long> vl[100069];

struct segtree
{
	long long l,r,sm;
	segtree *p[2];
	
	void bd(long long lh,long long rh)
	{
		l=lh;
		r=rh;
		sm=0;
		if(l!=r)
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
			return p[0]->qr(lh,rh)+p[1]->qr(lh,rh);
		}
	}
}
sg[100069];

int main()
{
	long long t,rr,i,k,l,z=0;
	
	scanf("%lld%lld",&n,&d);
	sg[0].bd(1,n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		sg[i]=sg[i-1];
		sg[i].ud(i,1);
		vl[k].push_back(i);
		fq[k]++;
		if(fq[k]>d)
		{
			sg[i].ud(vl[k][fq[k]-1-d],-1);
		}
	}
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&k,&l);
		k=(k+z)%n+1;
		l=(l+z)%n+1;
		if(k>l)
		{
			swap(k,l);
		}
		z=sg[l].qr(k,l);
		printf("%lld\n",z);
	}
}