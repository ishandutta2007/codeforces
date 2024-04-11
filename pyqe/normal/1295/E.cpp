#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,a[200069];
pair<long long,long long> pst[200069];

long long av(long long x,long long y)
{
	return (x+y)/2;
}

struct segtree
{
	long long l,r,mn,lz;
	segtree *p[2];
	
	void bd(long long lh,long long rh)
	{
		long long ii;
		
		l=lh;
		r=rh;
		mn=0;
		lz=0;
		if(l==r);
		else
		{
			for(ii=0;ii<2;ii++)
			{
				p[ii]=new segtree;
				p[ii]->bd(!ii?l:av(l,r)+1,!ii?av(l,r):r);
			}
		}
	}
	void blc()
	{
		long long ii;
		
		for(ii=0;ii<2;ii++)
		{
			p[ii]->mn+=lz;
			p[ii]->lz+=lz;
		}
		lz=0;
	}
	void ud(long long lh,long long rh,long long w)
	{
		long long ii;
		
		if(l>rh||r<lh);
		else if(l>=lh&&r<=rh)
		{
			mn+=w;
			lz+=w;
		}
		else
		{
			blc();
			mn=1e18;
			for(ii=0;ii<2;ii++)
			{
				p[ii]->ud(lh,rh,w);
				mn=min(mn,p[ii]->mn);
			}
		}
	}
	long long qr(long long lh,long long rh)
	{
		if(l>rh||r<lh)
		{
			return 1e18;
		}
		else if(l>=lh&&r<=rh)
		{
			return mn;
		}
		else
		{
			blc();
			return min(p[0]->qr(lh,rh),p[1]->qr(lh,rh));
		}
	}
}
sg;

int main()
{
	long long i,j,k,mn;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&pst[i].fr);
		pst[i].sc=i;
	}
	sort(pst+1,pst+n+1);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	sg.bd(0,n);
	for(i=1;i<=n;i++)
	{
		sg.ud(i,n,a[i]);
	}
	mn=sg.qr(1,n-1);
	for(i=1;i<=n;i++)
	{
		k=pst[i].sc;
		sg.ud(0,k-1,+a[k]);
		sg.ud(k,n,-a[k]);
		mn=min(mn,sg.qr(1,n-1));
	}
	printf("%lld\n",mn);
}