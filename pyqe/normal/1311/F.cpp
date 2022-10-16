#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n;
pair<long long,long long> a[200069];

long long av(long long x,long long y)
{
	return (x+y+200000000)/2-100000000;
}

struct segtree
{
	long long l,r,sm=0,fq=0;
	segtree *p[2];
	
	void bd(long long lh,long long rh)
	{
		l=lh;
		r=rh;
		p[0]=0;
		p[1]=0;
	}
	void ud(long long x,long long w)
	{
		if(l>x||r<x);
		else if(l>=x&&r<=x)
		{
			sm+=w;
			fq++;
		}
		else
		{
			long long ii;
			
			sm=0;
			fq=0;
			for(ii=0;ii<2;ii++)
			{
				if(!p[ii])
				{
					p[ii]=new segtree;
					p[ii]->bd(!ii?l:av(l,r)+1,!ii?av(l,r):r);
				}
				p[ii]->ud(x,w);
				sm+=p[ii]->sm;
				fq+=p[ii]->fq;
			}
		}
	}
	long long qr(long long lh,long long rh,long long w)
	{
		if(l>rh||r<lh)
		{
			return 0;
		}
		else if(l>=lh&&r<=rh)
		{
			return fq*w-sm;
		}
		else
		{
			long long ii;
			
			for(ii=0;ii<2;ii++)
			{
				if(!p[ii])
				{
					p[ii]=new segtree;
					p[ii]->bd(!ii?l:av(l,r)+1,!ii?av(l,r):r);
				}
			}
			return p[0]->qr(lh,rh,w)+p[1]->qr(lh,rh,w);
		}
	}
}
sg;

int main()
{
	long long i,k,l,z=0;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&a[i].fr);
	}
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&a[i].sc);
	}
	sort(a+1,a+n+1);
	sg.bd(-1e8,1e8);
	for(i=1;i<=n;i++)
	{
		k=a[i].fr;
		l=a[i].sc;
		z+=sg.qr(-1e8,l,k);
		sg.ud(l,k);
	}
	printf("%lld\n",z);
}