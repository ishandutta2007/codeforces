#include <bits/stdc++.h>

using namespace std;

long long n;
bitset<500069> a;

struct val
{
	long long mx=0,c[2]={0,0};
	bool ft[2]={1,1},jd=1;
}
v0;

struct segtree
{
	long long l,r;
	val ans[2];
	bool lz;
	segtree *p[2];
	
	val mrg(val x,val y)
	{
		if(x.mx&&y.mx)
		{
			long long w;
			val z;
			
			z.mx=max(x.mx,y.mx);
			z.c[0]=x.c[0];
			z.c[1]=y.c[1];
			z.ft[0]=x.ft[0];
			z.ft[1]=y.ft[1];
			z.jd=0;
			if(x.ft[1]||y.ft[0])
			{
				w=x.c[1]+y.c[0];
				z.mx=max(z.mx,w);
				if(x.jd)
				{
					z.c[0]=w;
				}
				if(y.jd)
				{
					z.c[1]=w;
				}
				z.jd=x.jd&&y.jd;
			}
			return z;
		}
		else if(!x.mx)
		{
			return y;
		}
		else
		{
			return x;
		}
	}
	void bd(long long lh,long long rh)
	{
		l=lh;
		r=rh;
		lz=0;
		if(l==r)
		{
			long long ii,jj;
			
			for(ii=0;ii<2;ii++)
			{
				ans[ii].mx=1;
				for(jj=0;jj<2;jj++)
				{
					ans[ii].c[jj]=1;
				}
				ans[ii].ft[!a[l]^ii]=0;
			}
		}
		else
		{
			long long ii,md=(l+r)/2;
			
			for(ii=0;ii<2;ii++)
			{
				p[ii]=new segtree;
				p[ii]->bd(!ii?l:md+1,!ii?md:r);
			}
			for(ii=0;ii<2;ii++)
			{
				ans[ii]=mrg(p[0]->ans[ii],p[1]->ans[ii]);
			}
		}
	}
	void blc()
	{
		if(lz)
		{
			long long ii;
			
			for(ii=0;ii<2;ii++)
			{
				swap(p[ii]->ans[0],p[ii]->ans[1]);
				p[ii]->lz^=1;
			}
			lz=0;
		}
	}
	val qr(long long lh,long long rh)
	{
		if(l>rh||r<lh)
		{
			return v0;
		}
		else if(l>=lh&&r<=rh)
		{
			swap(ans[0],ans[1]);
			lz^=1;
			return ans[0];
		}
		else
		{
			long long ii;
			val tmp;
			
			blc();
			tmp=mrg(p[0]->qr(lh,rh),p[1]->qr(lh,rh));
			for(ii=0;ii<2;ii++)
			{
				ans[ii]=mrg(p[0]->ans[ii],p[1]->ans[ii]);
			}
			return tmp;
		}
	}
}
sg;

int main()
{
	long long t,rr,i,k,l;
	char ch;
	
	scanf("%lld%lld",&n,&t);
	for(i=1;i<=n;i++)
	{
		scanf(" %c",&ch);
		a[i]=ch=='>';
	}
	sg.bd(1,n);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&k,&l);
		printf("%lld\n",sg.qr(k,l).mx);
	}
}