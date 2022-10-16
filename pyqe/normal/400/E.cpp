#include <bits/stdc++.h>

using namespace std;

int n,a[100069];
long long z=0;

struct segtree
{
	int l,r,z[2],lz[2];
	segtree *p[2];
	
	void bd(int lh,int rh)
	{
		int ii,md=(lh+rh)/2;
		
		l=lh;
		r=rh;
		for(ii=0;ii<2;ii++)
		{
			lz[ii]=0;
		}
		if(l==r)
		{
			for(ii=0;ii<2;ii++)
			{
				z[ii]=0;
			}
		}
		else
		{
			for(ii=0;ii<2;ii++)
			{
				p[ii]=new segtree;
				p[ii]->bd(!ii?l:md+1,!ii?md:r);
			}
		}
	}
	void blc(int ky)
	{
		int ii;
		
		for(ii=0;ii<2;ii++)
		{
			p[ii]->z[ky]+=lz[ky];
			p[ii]->lz[ky]+=lz[ky];
		}
		lz[ky]=0;
	}
	void ud(int ky,int lh,int rh,int w)
	{
		if(l>rh||r<lh);
		else if(l>=lh&&r<=rh)
		{
			z[ky]+=w;
			lz[ky]+=w;
		}
		else
		{
			int ii;
			
			blc(ky);
			for(ii=0;ii<2;ii++)
			{
				p[ii]->ud(ky,lh,rh,w);
			}
		}
	}
	int qr(int ky,int x)
	{
		if(l>x||r<x)
		{
			return 0;
		}
		else if(l>=x&&r<=x)
		{
			return z[ky];
		}
		else
		{
			blc(ky);
			return p[0]->qr(ky,x)+p[1]->qr(ky,x);
		}
	}
}
sg[17];

void ud(int x,int w)
{
	int i,k,l;
	
	for(i=0;i<17;i++)
	{
		k=sg[i].qr(0,x-1);
		l=sg[i].qr(1,x+1);
		if(!(a[x]>>i&1)&&(w>>i&1))
		{
			sg[i].ud(0,x,x+l,k+1);
			sg[i].ud(1,x-k,x,l+1);
			z+=((long long)(k+1)*(l+1))<<i;
		}
		else if((a[x]>>i&1)&&!(w>>i&1))
		{
			sg[i].ud(0,x,x+l,-k-1);
			sg[i].ud(1,x-k,x,-l-1);
			z-=((long long)(k+1)*(l+1))<<i;
		}
	}
	a[x]=w;
}

int main()
{
	int t,rr,i,k,l;
	
	scanf("%d%d",&n,&t);
	for(i=0;i<17;i++)
	{
		sg[i].bd(1,n);
	}
	for(i=1;i<=n;i++)
	{
		scanf("%d",&k);
		ud(i,k);
	}
	for(rr=0;rr<t;rr++)
	{
		scanf("%d%d",&k,&l);
		ud(k,l);
		printf("%lld\n",z);
	}
}