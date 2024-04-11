#include <bits/stdc++.h>

using namespace std;

int n,a[200069],inf=1e9;

struct segtree
{
	int l,r,mn,lz;
	long long sm;
	segtree *p[2];
	
	void bd(int lh,int rh)
	{
		l=lh;
		r=rh;
		lz=-inf;
		if(l==r)
		{
			mn=a[l];
			sm=a[l];
		}
		else
		{
			int ii,md=(l+r)/2;
			
			for(ii=0;ii<2;ii++)
			{
				p[ii]=new segtree;
				p[ii]->bd(!ii?l:md+1,!ii?md:r);
			}
			mn=p[1]->mn;
			sm=p[0]->sm+p[1]->sm;
		}
	}
	void blc()
	{
		if(lz!=-inf)
		{
			int ii;
			
			for(ii=0;ii<2;ii++)
			{
				p[ii]->mn=lz;
				p[ii]->sm=(long long)lz*(p[ii]->r-p[ii]->l+1);
				p[ii]->lz=lz;
			}
			lz=-inf;
		}
	}
	void ud(int lh,int rh,int w)
	{
		if(l>rh||r<lh);
		else if(l>=lh&&r<=rh)
		{
			mn=w;
			sm=(long long)w*(r-l+1);
			lz=w;
		}
		else
		{
			int ii;
			
			blc();
			for(ii=0;ii<2;ii++)
			{
				p[ii]->ud(lh,rh,w);
			}
			mn=p[1]->mn;
			sm=p[0]->sm+p[1]->sm;
		}
	}
	long long qr(int lh,int rh)
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
	int bln(int x)
	{
		if(l==r)
		{
			return l-1+(mn>x);
		}
		else
		{
			blc();
			return p[p[0]->mn>x]->bln(x);
		}
	}
	int bls(long long x)
	{
		if(l==r)
		{
			return l-1+(sm<=x);
		}
		else
		{
			int e;
			
			blc();
			e=p[0]->sm<=x;
			return p[e]->bls(x-p[0]->sm*e);
		}
	}
}
sg;

int main()
{
	int t,rr,i,ky,k,l,p,tg,z;
	
	scanf("%d%d",&n,&t);
	for(i=1;i<=n;i++)
	{
		scanf("%d",a+i);
	}
	sg.bd(1,n);
	for(rr=0;rr<t;rr++)
	{
		scanf("%d%d%d",&ky,&k,&l);
		if(ky==1)
		{
			sg.ud(sg.bln(l)+1,k,l);
		}
		else
		{
			z=0;
			for(p=k-1;p<n;)
			{
				p=max(p,sg.bln(l));
				tg=sg.bls(sg.qr(1,p)+l);
				z+=tg-p;
				l-=sg.qr(p+1,tg);
				p=tg;
			}
			printf("%d\n",z);
		}
	}
}