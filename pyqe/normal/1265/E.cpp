#include <bits/stdc++.h>

using namespace std;

long long n,a[200069],pwk,fw[200069],fwp,dv=998244353;
bitset<200069> cp;
multiset<long long> ms;
multiset<long long>::iterator it;

long long pw(long long x,long long y)
{
	if(y==0)
	{
		return 1;
	}
	pwk=pw(x,y/2);
	pwk=pwk*pwk%dv;
	if(y%2==1)
	{
		pwk=pwk*x%dv;
	}
	return pwk;
}

void ud(long long x,long long w)
{
	for(fwp=x;fwp<=n;fwp+=fwp&-fwp)
	{
		fw[fwp]=fw[fwp]*w%dv;
	}
}

long long qr(long long lh,long long rh)
{
	long long z=1;
	
	for(fwp=lh-1;fwp>0;fwp-=fwp&-fwp)
	{
		z=z*fw[fwp]%dv;
	}
	z=pw(z,dv-2);
	for(fwp=rh;fwp>0;fwp-=fwp&-fwp)
	{
		z=z*fw[fwp]%dv;
	}
	return z;
}

long long md(long long l,long long r)
{
	return (l+r)/2;
}

struct segtree
{
	long long l,r,sm,lz;
	segtree *p1,*p2;
	
	void bd(long long lh,long long rh)
	{
		l=lh;
		r=rh;
		lz=1;
		if(lh==rh)
		{
			sm=qr(lh,n);
		}
		else
		{
			p1=new segtree;
			p2=new segtree;
			p1->bd(l,md(l,r));
			p2->bd(md(l,r)+1,r);
			sm=(p1->sm+p2->sm)%dv;
		}
	}
	void blc()
	{
		p1->sm=p1->sm*lz%dv;
		p2->sm=p2->sm*lz%dv;
		p1->lz=p1->lz*lz%dv;
		p2->lz=p2->lz*lz%dv;
		lz=1;
	}
	void ud(long long lh,long long rh,long long w)
	{
		if(l>rh||r<lh);
		else if(l>=lh&&r<=rh)
		{
			sm=sm*w%dv;
			lz=lz*w%dv;
		}
		else
		{
			blc();
			p1->ud(lh,rh,w);
			p2->ud(lh,rh,w);
			sm=(p1->sm+p2->sm)%dv;
		}
	}
}
sg;

int main()
{
	long long t=1,rr,i,k,lh,rh;
	
	scanf("%lld",&n);
	for(i=0;i<=n;i++)
	{
		fw[i]=1;
	}
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		a[i]=100*pw(a[i],dv-2)%dv;
		ud(i,a[i]);
	}
	sg.bd(1,n);
	cp[1]=1;
	ms.insert(1);
	ms.insert(n+1);
	for(rr=0;rr<t;rr++)
	{
		printf("%lld\n",sg.sm);
	}
}