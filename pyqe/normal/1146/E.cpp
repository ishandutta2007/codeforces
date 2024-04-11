#include <bits/stdc++.h>

using namespace std;

long long n,a[100069];

long long av(long long x,long long y)
{
	return (x+y+1000000)/2-500000;
}

struct segtree
{
	long long l,r,sm,lz;
	segtree *p1,*p2;
	
	void bd(long long lh,long long rh)
	{
		l=lh;
		r=rh;
		sm=0;
		lz=0;
		if(l==r);
		else
		{
			p1=new segtree;
			p2=new segtree;
			p1->bd(l,av(l,r));
			p2->bd(av(l,r)+1,r);
		}
	}
	void blc()
	{
		if(lz==3)
		{
			p1->sm=p1->r-p1->l+1-p1->sm;
			p2->sm=p2->r-p2->l+1-p2->sm;
			p1->lz=3-p1->lz;
			p2->lz=3-p2->lz;
		}
		else if(lz)
		{
			p1->sm=(p1->r-p1->l+1)*(lz-1);
			p2->sm=(p2->r-p2->l+1)*(lz-1);
			p1->lz=lz;
			p2->lz=lz;
		}
		lz=0;
	}
	void ud(long long lh,long long rh,long long w)
	{
		if(l>rh||r<lh);
		else if(l>=lh&&r<=rh)
		{
			if(w==3)
			{
				sm=r-l+1-sm;
				lz=3-lz;
			}
			else if(w)
			{
				sm=(r-l+1)*(w-1);
				lz=w;
			}
		}
		else
		{
			blc();
			p1->ud(lh,rh,w);
			p2->ud(lh,rh,w);
			sm=p1->sm+p2->sm;
		}
	}
	long long qr(long long x)
	{
		if(l>x||r<x)
		{
			return 0;
		}
		else if(l>=x&&r<=x)
		{
			return sm;
		}
		else
		{
			blc();
			return p1->qr(x)+p2->qr(x);
		}
	}
}
sg;

int main()
{
	long long t,rr,i,ky,k;
	char ch;
	
	scanf("%lld%lld",&n,&t);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	sg.bd(-100000,100000);
	for(rr=0;rr<t;rr++)
	{
		scanf(" %c%lld",&ch,&k);
		ky=ch=='<';
		if(ky)
		{
			k=-k;
		}
		if(k>=0)
		{
			sg.ud(-100000,-k-1,ky+1);
			sg.ud(k+1,100000,!ky+1);
		}
		else
		{
			sg.ud(-100000,k,ky+1);
			sg.ud(k+1,-k-1,3);
			sg.ud(-k,100000,!ky+1);
		}
	}
	for(i=1;i<=n;i++)
	{
		k=a[i];
		if(sg.qr(k))
		{
			k=-k;
		}
		printf("%lld%c",k," \n"[i==n]);
	}
}