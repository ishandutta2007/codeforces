#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

const long long inf=1e18;
long long n,cr,nx=0,ttl=0,ex[100069],od[100069],rt[100069],sbt[100069],pr[100069],an[100069],dh[100069],fh[100069];
vector<long long> al[100069];
bitset<100069> vtd,vtd2;
bool r0=0,r02=0;

struct segtree
{
	long long l,r,sm;
	bool lz;
	segtree *p[2];
	
	void bd(long long lh,long long rh)
	{
		l=lh;
		r=rh;
		sm=0;
		lz=0;
		if(l<r)
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
		if(lz)
		{
			long long ii;
			
			for(ii=0;ii<2;ii++)
			{
				p[ii]->sm=p[ii]->r-p[ii]->l+1-p[ii]->sm;
				p[ii]->lz^=1;
			}
			lz=0;
		}
	}
	void ud(long long lh,long long rh)
	{
		if(l>rh||r<lh);
		else if(l>=lh&&r<=rh)
		{
			ttl+=r-l+1-sm*2;
			sm=r-l+1-sm;
			lz^=1;
		}
		else
		{
			long long ii;
			
			blc();
			for(ii=0;ii<2;ii++)
			{
				p[ii]->ud(lh,rh);
			}
			sm=p[0]->sm+p[1]->sm;
		}
	}
}
sg[100069];

void cyc(long long x,long long b4)
{
	long long i,sz=al[x].size(),l;
	
	vtd[x]=1;
	vtd2[x]=1;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			cyc(l,x);
		}
		else if(vtd2[l]&&l!=b4)
		{
			cr=l;
			r0=1;
		}
		if(r0)
		{
			if(!r02)
			{
				nx++;
				ex[nx]=x;
				od[x]=nx;
				r02|=x==cr;
			}
			return;
		}
	}
	vtd2[x]=0;
}

void bd(long long x)
{
	long long i,sz=al[x].size(),l,e;
	pair<long long,long long> mxe={-inf,-1};
	
	vtd[x]=1;
	sbt[x]=1;
	an[x]=x;
	fh[x]=dh[x];
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l]&&!od[l])
		{
			rt[l]=rt[x];
			pr[l]=x;
			dh[l]=dh[x]+1;
			bd(l);
			sbt[x]+=sbt[l];
			mxe=max(mxe,{sbt[l],l});
		}
	}
	e=mxe.sc;
	if(e+1)
	{
		an[e]=x;
		fh[x]=fh[e];
	}
}

void anc(long long x)
{
	long long i,sz=al[x].size(),l;
	
	vtd[x]=1;
	if(an[x]==x)
	{
		sg[x].bd(dh[x],fh[x]);
	}
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l]&&!od[l])
		{
			if(an[l]==x)
			{
				an[l]=an[x];
			}
			anc(l);
		}
	}
}

void lca(long long x,long long y)
{
	for(;an[x]!=an[y];x=pr[an[x]])
	{
		if(dh[an[x]]<dh[an[y]])
		{
			swap(x,y);
		}
		sg[an[x]].ud(dh[an[x]],dh[x]);
	}
	if(dh[x]>dh[y])
	{
		swap(x,y);
	}
	sg[an[x]].ud(dh[x]+1,dh[y]);
}

int main()
{
	long long t,rr,i,k,l;
	
	scanf("%lld%lld",&n,&t);
	for(i=0;i<n;i++)
	{
		scanf("%lld%lld",&k,&l);
		al[k].push_back(l);
		al[l].push_back(k);
	}
	cyc(1,0);
	vtd.reset();
	for(i=1;i<=nx;i++)
	{
		rt[ex[i]]=ex[i];
		bd(ex[i]);
	}
	vtd.reset();
	for(i=1;i<=nx;i++)
	{
		anc(ex[i]);
	}
	sg[0].bd(1,nx);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&k,&l);
		if(rt[k]==rt[l])
		{
			lca(k,l);
		}
		else
		{
			lca(k,rt[k]);
			lca(l,rt[l]);
			k=od[rt[k]];
			l=od[rt[l]];
			if(mp((l+nx-k)%nx,ex[k%nx+1])>mp((k+nx-l)%nx,ex[(k+nx-2)%nx+1]))
			{
				swap(k,l);
			}
			if(k<l)
			{
				sg[0].ud(k,l-1);
			}
			else
			{
				sg[0].ud(k,nx);
				sg[0].ud(1,l-1);
			}
		}
		printf("%lld\n",n-ttl+(sg[0].sm==nx));
	}
}