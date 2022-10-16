#include <bits/stdc++.h>

using namespace std;

long long n,a[200069];
array<array<long long,2>,9> a0;

long long md(long long l,long long r)
{
	return (l+r)/2;
}

struct segtree
{
	long long l,r;
	array<array<long long,2>,9> mn;
	segtree *p1,*p2;
	
	array<array<long long,2>,9> mrg(array<array<long long,2>,9> x,array<array<long long,2>,9> y)
	{
		long long i;
		array<array<long long,2>,9> tmp;
		
		for(i=0;i<9;i++)
		{
			tmp[i][0]=min(x[i][0],y[i][0]);
			tmp[i][1]=min(max(x[i][0],y[i][0]),min(x[i][1],y[i][1]));
		}
		return tmp;
	}
	void bd(long long lh,long long rh)
	{
		l=lh;
		r=rh;
		if(l==r)
		{
			long long i,kk=a[l];
			
			for(i=0;i<9;i++,kk/=10)
			{
				mn[i][0]=1e18;
				mn[i][1]=1e18;
				if(kk%10)
				{
					mn[i][0]=a[l];
				}
			}
		}
		else
		{
			p1=new segtree;
			p2=new segtree;
			p1->bd(l,md(l,r));
			p2->bd(md(l,r)+1,r);
			mn=mrg(p1->mn,p2->mn);
		}
	}
	void ud(long long x,long long w)
	{
		if(l>x||r<x);
		else if(l>=x&&r<=x)
		{
			long long i,kk=w;
			
			for(i=0;i<9;i++,kk/=10)
			{
				mn[i][0]=1e18;
				mn[i][1]=1e18;
				if(kk%10)
				{
					mn[i][0]=w;
				}
			}
		}
		else
		{
			p1->ud(x,w);
			p2->ud(x,w);
			mn=mrg(p1->mn,p2->mn);
		}
	}
	array<array<long long,2>,9> qr(long long lh,long long rh)
	{
		if(l>rh||r<lh)
		{
			return a0;
		}
		else if(l>=lh&&r<=rh)
		{
			return mn;
		}
		else
		{
			return mrg(p1->qr(lh,rh),p2->qr(lh,rh));
		}
	}
}
sg;

int main()
{
	long long t,rr,i,ky,k,l,mn;
	array<array<long long,2>,9> tmp;
	
	for(i=0;i<9;i++)
	{
		a0[i][0]=1e18;
		a0[i][1]=1e18;
	}
	scanf("%lld%lld",&n,&t);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	sg.bd(1,n);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld",&ky,&k,&l);
		if(ky==1)
		{
			sg.ud(k,l);
		}
		else if(ky==2)
		{
			tmp=sg.qr(k,l);
			mn=1e18;
			for(i=0;i<9;i++)
			{
				mn=min(mn,tmp[i][0]+tmp[i][1]);
			}
			if(mn==1000000000000000000)
			{
				mn=-1;
			}
			printf("%lld\n",mn);
		}
	}
}