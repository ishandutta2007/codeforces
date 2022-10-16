#include <bits/stdc++.h>

using namespace std;

long long n,nn=0,pst[500069],sbt[500069];
vector<long long> al[500069];
bitset<500069> vtd;

struct segtree
{
	long long l,r,mx,lz;
	segtree *p[2];
	
	void bd(long long lh,long long rh)
	{
		l=lh;
		r=rh;
		mx=0;
		lz=0;
		if(l!=r)
		{
			long long ii,md=(l+r)/2;
			
			for(ii=0;ii<2;ii++)
			{
				p[ii]=new segtree;
				p[ii]->bd(!ii?l:md+1,!ii?md:r);
			}
		}
	}
	void blc()
	{
		long long ii;
		
		for(ii=0;ii<2;ii++)
		{
			p[ii]->mx=max(p[ii]->mx,lz);
			p[ii]->lz=max(p[ii]->lz,lz);
		}
		lz=0;
	}
	void ud(long long lh,long long rh,long long w)
	{
		if(l>rh||r<lh);
		else if(l>=lh&&r<=rh)
		{
			mx=max(mx,w);
			lz=max(lz,w);
		}
		else
		{
			long long ii;
			
			blc();
			for(ii=0;ii<2;ii++)
			{
				p[ii]->ud(lh,rh,w);
			}
			mx=max(p[0]->mx,p[1]->mx);
		}
	}
	long long qr(long long lh,long long rh)
	{
		if(l>rh||r<lh)
		{
			return 0;
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
sg[2];

void dfs(long long x)
{
	long long i,sz=al[x].size(),l;
	
	vtd[x]=1;
	nn++;
	pst[x]=nn;
	sbt[x]=1;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			dfs(l);
			sbt[x]+=sbt[l];
		}
	}
}

int main()
{
	long long t,rr,i,ii,ky,k,l;
	
	scanf("%lld",&n);
	for(i=0;i<n-1;i++)
	{
		scanf("%lld%lld",&k,&l);
		al[k].push_back(l);
		al[l].push_back(k);
	}
	dfs(1);
	for(ii=0;ii<2;ii++)
	{
		sg[ii].bd(1,n);
	}
	scanf("%lld",&t);
	for(rr=1;rr<=t;rr++)
	{
		scanf("%lld%lld",&ky,&k);
		if(ky==1)
		{
			sg[0].ud(pst[k],pst[k]+sbt[k]-1,rr);
		}
		else if(ky==2)
		{
			sg[1].ud(pst[k],pst[k],rr);
		}
		else
		{
			printf("%lld\n",(long long)(sg[0].qr(pst[k],pst[k])>sg[1].qr(pst[k],pst[k]+sbt[k]-1)));
		}
	}
}