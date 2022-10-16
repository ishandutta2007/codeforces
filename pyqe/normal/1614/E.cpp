#include <bits/stdc++.h>

using namespace std;

const int ma=1e9;
int n,lz=-1;

struct segtree
{
	int l,r,sm;
	segtree *p[2];
	
	void bd(int lh,int rh)
	{
		l=lh;
		r=rh;
		sm=r-l+1;
		p[0]=0;
	}
	inline void blc()
	{
		if(!p[0])
		{
			int ii,md=(l+r)/2;
			
			for(ii=0;ii<2;ii++)
			{
				p[ii]=new segtree;
				p[ii]->bd(!ii?l:md+1,!ii?md:r);
			}
		}
	}
	void ud(int x,int w)
	{
		if(x<=0)
		{
			lz--;
		}
		else if(x>sm);
		else if(l==r)
		{
			sm+=w;
		}
		else
		{
			int e;
			
			blc();
			e=x>p[0]->sm;
			p[e]->ud(x-p[0]->sm*e,w);
			sm=p[0]->sm+p[1]->sm;
		}
	}
	int qr(int x)
	{
		if(l>x)
		{
			return 0;
		}
		else if(r<=x)
		{
			return sm;
		}
		else
		{
			if(!p[0])
			{
				return x-l+1;
			}
			else
			{
				return p[0]->qr(x)+p[1]->qr(x);
			}
		}
	}
}
sg;

int main()
{
	int i,j,k,sz,z=0;
	
	scanf("%d",&n);
	sg.bd(0,ma);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&k,&sz);
		sg.ud(k-lz+1,-1);
		sg.ud(k-lz,-1);
		lz++;
		for(j=0;j<sz;j++)
		{
			scanf("%d",&k);
			k=(k+z)%(ma+1);
			z=sg.qr(k)+lz;
			printf("%d\n",z);
		}
	}
}