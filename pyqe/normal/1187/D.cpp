#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,a[2][300069],fq[300069];
map<long long,long long> pst;

long long av(long long x,long long y)
{
	return (x+y)/2;
}

struct segtree
{
	long long l,r,mx;
	segtree *p[2];
	
	void bd(long long lh,long long rh)
	{
		l=lh;
		r=rh;
		if(l==r)
		{
			mx=a[1][l];
		}
		else
		{
			long long ii;
			
			mx=-1e18;
			for(ii=0;ii<2;ii++)
			{
				p[ii]=new segtree;
				p[ii]->bd(!ii?l:av(l,r)+1,!ii?av(l,r):r);
				mx=max(mx,p[ii]->mx);
			}
		}
	}
	void ud(long long x,long long w)
	{
		if(l>x||r<x);
		else if(l>=x&&r<=x)
		{
			mx=w;
		}
		else
		{
			long long ii;
			
			mx=-1e18;
			for(ii=0;ii<2;ii++)
			{
				p[ii]->ud(x,w);
				mx=max(mx,p[ii]->mx);
			}
		}
	}
	long long qr(long long lh,long long rh)
	{
		if(lh>rh||l>rh||r<lh)
		{
			return -1e18;
		}
		else if(l>=lh&&r<=rh)
		{
			return mx;
		}
		else
		{
			return max(p[0]->qr(lh,rh),p[1]->qr(lh,rh));
		}
	}
}
sg;

int main()
{
	long long t,rr,i,ii,k;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(ii=0;ii<2;ii++)
		{
			for(i=1;i<=n;i++)
			{
				scanf("%lld",&k);
				a[ii][i]=k*1000000+fq[k];
				fq[k]++;
			}
			for(i=1;i<=n;i++)
			{
				fq[a[ii][i]/1000000]=0;
			}
		}
		pst.clear();
		for(i=1;i<=n;i++)
		{
			pst[a[1][i]]=i;
		}
		sg.bd(1,n);
		for(i=1;i<=n;i++)
		{
			if(!pst[a[0][i]]||sg.qr(1,pst[a[0][i]]-1)>a[0][i])
			{
				i=-1;
				break;
			}
			sg.ud(pst[a[0][i]],0);
		}
		if(i==-1)
		{
			printf("NO\n");
		}
		else
		{
			printf("YES\n");
		}
	}
}