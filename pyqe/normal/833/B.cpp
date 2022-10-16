#include <bits/stdc++.h>

using namespace std;

long long n,m,ls[35069],dp[69];

long long av(long long x,long long y)
{
	return (x+y)/2;
}

struct segtree
{
	long long l,r,mx=0,lz=0;
	segtree *p[2];
	
	void bd(long long lh,long long rh)
	{
		long long ii;
		
		l=lh;
		r=rh;
		if(l==r);
		else
		{
			mx=-1e18;
			for(ii=0;ii<2;ii++)
			{
				p[ii]=new segtree;
				p[ii]->bd(!ii?l:av(l,r)+1,!ii?av(l,r):r);
				mx=max(mx,p[ii]->mx);
			}
		}
	}
	void blc()
	{
		long long ii;
		
		for(ii=0;ii<2;ii++)
		{
			p[ii]->mx+=lz;
			p[ii]->lz+=lz;
		}
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
			p[0]->ud(lh,rh,w);
			p[1]->ud(lh,rh,w);
			mx=max(p[0]->mx,p[1]->mx);
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
			return max(p[0]->qr(lh,rh),p[1]->qr(lh,rh));
		}
	}
}
sg[69];

int main()
{
	long long i,j,k;
	
	scanf("%lld%lld",&n,&m);
	for(i=0;i<m;i++)
	{
		sg[i].bd(1,n);
	}
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		for(j=0;j<m;j++)
		{
			sg[j].ud(i+1,i+1,dp[j]);
			sg[j].ud(ls[k]+1,i,1);
			dp[j+1]=sg[j].qr(1,i);
		}
		ls[k]=i;
	}
	printf("%lld\n",dp[m]);
}