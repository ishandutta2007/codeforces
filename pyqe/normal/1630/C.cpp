#include <bits/stdc++.h>

using namespace std;

const long long inf=1e18;
long long n,a[200069],pst[200069],ls[200069];

struct segtree
{
	long long l,r,mx[2];
	segtree *p[2];
	
	void bd(long long lh,long long rh)
	{
		l=lh;
		r=rh;
		if(l==r)
		{
			mx[0]=0;
			mx[1]=-l;
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
				mx[ii]=max(p[0]->mx[ii],p[1]->mx[ii]);
			}
		}
	}
	void ud(long long x,long long w)
	{
		if(l>x||r<x);
		else if(l>=x&&r<=x)
		{
			mx[0]=w;
			mx[1]=w-l;
		}
		else
		{
			long long ii;
			
			for(ii=0;ii<2;ii++)
			{
				p[ii]->ud(x,w);
			}
			for(ii=0;ii<2;ii++)
			{
				mx[ii]=max(p[0]->mx[ii],p[1]->mx[ii]);
			}
		}
	}
	long long qr(long long lh,long long rh,long long xx)
	{
		if(l>rh||r<lh)
		{
			return -inf;
		}
		else if(l>=lh&&r<=rh)
		{
			return mx[xx];
		}
		else
		{
			return max(p[0]->qr(lh,rh,xx),p[1]->qr(lh,rh,xx));
		}
	}
}
sg;

int main()
{
	long long i,k;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		if(!pst[a[i]])
		{
			pst[a[i]]=i;
		}
		ls[a[i]]=i;
	}
	sg.bd(0,n);
	for(i=1;i<=n;i++)
	{
		k=-inf;
		if(ls[a[i]]==i&&pst[a[i]]!=i)
		{
			k=max(sg.qr(0,pst[a[i]]-1,0)+i-pst[a[i]]-1,sg.qr(pst[a[i]],i-1,1)+i-1);
		}
		sg.ud(i,k);
	}
	printf("%lld\n",sg.mx[0]);
}