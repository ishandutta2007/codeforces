#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,a[100069];

long long av(long long x,long long y)
{
	return (x+y)/2;
}

struct segtree
{
	long long l,r,sm;
	pair<long long,long long> mxe;
	segtree *p[2];
	
	void bd(long long lh,long long rh)
	{
		l=lh;
		r=rh;
		if(l==r)
		{
			mxe={a[l],l};
			sm=a[l];
		}
		else
		{
			long long ii;
			
			mxe={-1e18,-1};
			sm=0;
			for(ii=0;ii<2;ii++)
			{
				p[ii]=new segtree;
				p[ii]->bd(!ii?l:av(l,r)+1,!ii?av(l,r):r);
				mxe=max(mxe,p[ii]->mxe);
				sm+=p[ii]->sm;
			}
		}
	}
	void ud(long long x,long long w)
	{
		if(l>x||r<x);
		else if(l>=x&&r<=x)
		{
			mxe.fr=w;
			sm=w;
		}
		else
		{
			long long ii;
			
			mxe={-1e18,-1};
			sm=0;
			for(ii=0;ii<2;ii++)
			{
				p[ii]->ud(x,w);
				mxe=max(mxe,p[ii]->mxe);
				sm+=p[ii]->sm;
			}
		}
	}
	pair<long long,long long> qxe(long long lh,long long rh)
	{
		if(l>rh||r<lh)
		{
			return {-1e18,-1};
		}
		else if(l>=lh&&r<=rh)
		{
			return mxe;
		}
		else
		{
			return max(p[0]->qxe(lh,rh),p[1]->qxe(lh,rh));
		}
	}
	long long qs(long long lh,long long rh)
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
			return p[0]->qs(lh,rh)+p[1]->qs(lh,rh);
		}
	}
}
sg;

int main()
{
	long long t,rr,i,ky,k,l,w,mx,e;
	pair<long long,long long> tmp;
	
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
			printf("%lld\n",sg.qs(k,l));
		}
		else if(ky==2)
		{
			scanf("%lld",&w);
			for(mx=1e18;mx>=w;)
			{
				tmp=sg.qxe(k,l);
				mx=tmp.fr;
				e=tmp.sc;
				if(mx>=w)
				{
					sg.ud(e,a[e]%w);
					a[e]%=w;
				}
			}
		}
		else if(ky==3)
		{
			sg.ud(k,l);
			a[k]=l;
		}
	}
}