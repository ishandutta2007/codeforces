#include <bits/stdc++.h>

using namespace std;

long long n[2],a[2][300069];

long long av(long long x,long long y)
{
	return (x+y)/2;
}

struct segtree
{
	long long l,r,mx,lz;
	segtree *p1,*p2;
	
	void bd(long long lh,long long rh)
	{
		l=lh;
		r=rh;
		mx=0;
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
		p1->mx+=lz;
		p2->mx+=lz;
		p1->lz+=lz;
		p2->lz+=lz;
		lz=0;
	}
	void ud(long long lh,long long rh,long long w)
	{
		if(l>rh||r<lh);
		else if(l>=lh&&r<=rh)
		{
			mx+=w;
			lz+=w;
		}
		else
		{
			blc();
			p1->ud(lh,rh,w);
			p2->ud(lh,rh,w);
			mx=max(p1->mx,p2->mx);
		}
	}
	long long qr(long long lh,long long rh)
	{
		if(l>rh||r<lh)
		{
			return -1e18;
		}
		else if(l>=lh&&r<=rh)
		{
			return mx;
		}
		else
		{
			blc();
			return max(p1->qr(lh,rh),p2->qr(lh,rh));
		}
	}
}
sg;

int main()
{
	long long t,rr,i,ii,ky,k,l,u,ls,lh,rh,md,zz;
	
	scanf("%lld%lld",n,n+1);
	sg.bd(1,1000000);
	for(ii=0;ii<2;ii++)
	{
		u=-ii*2+1;
		for(i=1;i<=n[ii];i++)
		{
			scanf("%lld",&a[ii][i]);
			sg.ud(1,a[ii][i],u);
		}
	}
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld",&ky,&k,&l);
		ky--;
		u=-ky*2+1;
		sg.ud(1,a[ky][k],-u);
		a[ky][k]=l;
		sg.ud(1,l,u);
		zz=-1;
		for(lh=1,rh=1000000;lh<=rh;)
		{
			md=av(lh,rh);
			if(sg.qr(md,1000000)>0)
			{
				zz=md;
				lh=md+1;
			}
			else
			{
				rh=md-1;
			}
		}
		printf("%lld\n",zz);
	}
}