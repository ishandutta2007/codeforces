#include <bits/stdc++.h>

using namespace std;

long long n,a[400069],as[400069],pst[400069],sbt[400069];
vector<long long> al[400069];
bitset<400069> vtd;

long long av(long long x,long long y)
{
	return (x+y)/2;
}

struct segtree
{
	long long l,r,z,lz=0;
	segtree *p[2];
	
	void bd(long long lh,long long rh)
	{
		l=lh;
		r=rh;
		if(l==r)
		{
			z=1ll<<as[l];
		}
		else
		{
			long long ii;
			
			z=0;
			for(ii=0;ii<2;ii++)
			{
				p[ii]=new segtree;
				p[ii]->bd(!ii?l:av(l,r)+1,!ii?av(l,r):r);
				z|=p[ii]->z;
			}
		}
	}
	void blc()
	{
		if(lz)
		{
			long long ii;
			
			for(ii=0;ii<2;ii++)
			{
				p[ii]->z=1ll<<lz;
				p[ii]->lz=lz;
			}
		}
		lz=0;
	}
	void ud(long long lh,long long rh,long long w)
	{
		if(l>rh||r<lh);
		else if(l>=lh&&r<=rh)
		{
			z=1ll<<w;
			lz=w;
		}
		else
		{
			long long ii;
			
			blc();
			z=0;
			for(ii=0;ii<2;ii++)
			{
				p[ii]->ud(lh,rh,w);
				z|=p[ii]->z;
			}
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
			return z;
		}
		else
		{
			blc();
			return p[0]->qr(lh,rh)|p[1]->qr(lh,rh);
		}
	}
}
sg;

void dfs(long long x)
{
	long long i,sz=al[x].size(),l;
	
	vtd[x]=1;
	n++;
	as[n]=a[x];
	pst[x]=n;
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
	long long t,rr,i,ky,k,l,z;
	
	scanf("%lld%lld",&n,&t);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	for(i=0;i<n-1;i++)
	{
		scanf("%lld%lld",&k,&l);
		al[k].push_back(l);
		al[l].push_back(k);
	}
	n=0;
	dfs(1);
	sg.bd(1,n);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&ky,&k);
		if(ky==1)
		{
			scanf("%lld",&l);
			sg.ud(pst[k],pst[k]+sbt[k]-1,l);
		}
		else
		{
			z=__builtin_popcountll(sg.qr(pst[k],pst[k]+sbt[k]-1));
			printf("%lld\n",z);
		}
	}
}