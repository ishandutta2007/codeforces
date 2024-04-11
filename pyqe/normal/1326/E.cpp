#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,a[300069],inf=1e18;

struct segtree
{
	long long l,r,ans,lz=0;
	pair<long long,long long> mx;
	segtree *p[2];
	
	void bd(long long lh,long long rh)
	{
		l=lh;
		r=rh;
		if(l==r)
		{
			mx={a[l],l};
			ans=0;
		}
		else
		{
			long long ii,md=(l+r)/2;
			
			mx={-inf,-1};
			ans=-inf;
			for(ii=0;ii<2;ii++)
			{
				p[ii]=new segtree;
				p[ii]->bd(!ii?l:md+1,!ii?md:r);
				mx=max(mx,p[ii]->mx);
				ans=max(ans,p[ii]->ans);
			}
		}
	}
	void blc()
	{
		long long ii;
		
		for(ii=0;ii<2;ii++)
		{
			p[ii]->ans+=lz;
			p[ii]->lz+=lz;
		}
		lz=0;
	}
	void udx(long long x,long long w)
	{
		if(l>x||r<x);
		else if(l>=x&&r<=x)
		{
			mx.fr=w;
		}
		else
		{
			long long ii;
			
			mx={-inf,-1};
			for(ii=0;ii<2;ii++)
			{
				p[ii]->udx(x,w);
				mx=max(mx,p[ii]->mx);
			}
		}
	}
	pair<long long,long long> qrx(long long lh,long long rh)
	{
		if(l>rh||r<lh)
		{
			return {-inf,-1};
		}
		else if(l>=lh&&r<=rh)
		{
			return mx;
		}
		else
		{
			return max(p[0]->qrx(lh,rh),p[1]->qrx(lh,rh));
		}
	}
	void uda(long long lh,long long rh,long long w)
	{
		if(l>rh||r<lh);
		else if(l>=lh&&r<=rh)
		{
			ans+=w;
			lz+=w;
		}
		else
		{
			long long ii;
			
			blc();
			ans=-inf;
			for(ii=0;ii<2;ii++)
			{
				p[ii]->uda(lh,rh,w);
				ans=max(ans,p[ii]->ans);
			}
		}
	}
	long long qra(long long lh,long long rh)
	{
		if(l>rh||r<lh)
		{
			return -inf;
		}
		else if(l>=lh&&r<=rh)
		{
			return ans;
		}
		else
		{
			blc();
			return max(p[0]->qra(lh,rh),p[1]->qra(lh,rh));
		}
	}
}
sg;

int main()
{
	long long i,k,lh,rh,md,zz,z,e;
	pair<long long,long long> tmp;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	sg.bd(1,n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		tmp=sg.qrx(1,n);
		z=tmp.fr;
		printf("%lld%c",z," \n"[i==n]);
		sg.uda(k,n,1);
		for(lh=1,rh=n;lh<=rh;)
		{
			md=(lh+rh)/2;
			if(sg.qra(1,md)>0)
			{
				zz=md;
				rh=md-1;
			}
			else
			{
				lh=md+1;
			}
		}
		tmp=sg.qrx(1,zz);
		e=tmp.sc;
		sg.udx(e,-inf);
		sg.uda(e,n,-1);
	}
}