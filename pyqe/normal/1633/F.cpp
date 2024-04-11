#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

const long long inf=1e18;
long long n,ttl=0,sbt[200069],an[200069],dh[200069],fh[200069],pr[200069],ped[200069],sq[200069],z=0,zs;
vector<pair<long long,long long>> al[200069];
bitset<200069> vtd,spc,dp;

struct segtree
{
	long long l,r,c,wg[2],wg2[2],fq[2];
	bool lz,lz2;
	segtree *p[2];
	
	inline void blc()
	{
		if(lz)
		{
			long long ii;
			
			for(ii=0;ii<2;ii++)
			{
				p[ii]->c=p[ii]->r-p[ii]->l+1-p[ii]->c;
				swap(p[ii]->wg[0],p[ii]->wg[1]);
				p[ii]->lz^=1;
			}
			lz=0;
		}
	}
	inline void mrg()
	{
		long long ii;
		
		c=p[0]->c+p[1]->c;
		for(ii=0;ii<2;ii++)
		{
			wg[ii]=p[0]->wg[ii]+p[1]->wg[ii];
		}
	}
	inline void blc2()
	{
		if(lz2)
		{
			long long ii;
			
			for(ii=0;ii<2;ii++)
			{
				swap(p[ii]->wg2[0],p[ii]->wg2[1]);
				swap(p[ii]->fq[0],p[ii]->fq[1]);
				p[ii]->lz2^=1;
			}
			lz2=0;
		}
	}
	inline void mrg2()
	{
		long long ii;
		
		for(ii=0;ii<2;ii++)
		{
			fq[ii]=p[0]->fq[ii]+p[1]->fq[ii];
		}
	}
	void bd(long long lh,long long rh)
	{
		long long ii;
		
		l=lh;
		r=rh;
		c=0;
		lz=0;
		lz2=0;
		for(ii=0;ii<2;ii++)
		{
			wg[ii]=0;
			wg2[ii]=ii;
			fq[ii]=0;
		}
		if(l<r)
		{
			long long md=(l+r)/2;
			
			for(ii=0;ii<2;ii++)
			{
				p[ii]=new segtree;
				p[ii]->bd(!ii?l:md+1,!ii?md:r);
			}
		}
	}
	void ud(long long x,long long w)
	{
		if(l>x||r<x);
		else if(l>=x&&r<=x)
		{
			wg[1]=w;
		}
		else
		{
			long long ii;
			
			blc();
			for(ii=0;ii<2;ii++)
			{
				p[ii]->ud(x,w);
			}
			mrg();
		}
	}
	void udr(long long lh,long long rh)
	{
		if(l>rh||r<lh);
		else if(l>=lh&&r<=rh)
		{
			c=r-l+1-c;
			swap(wg[0],wg[1]);
			lz^=1;
			z+=wg[0]-wg[1];
		}
		else
		{
			long long ii;
			
			blc();
			for(ii=0;ii<2;ii++)
			{
				p[ii]->udr(lh,rh);
			}
			mrg();
		}
	}
	void ud2(long long x,long long w)
	{
		if(l>x||r<x);
		else if(l>=x&&r<=x)
		{
			long long ii;
			
			ttl+=(wg2[0]+w>1)-fq[0];
			for(ii=0;ii<2;ii++)
			{
				wg2[ii]+=w;
				fq[ii]=wg2[ii]>1;
			}
		}
		else
		{
			long long ii;
			
			blc2();
			for(ii=0;ii<2;ii++)
			{
				p[ii]->ud2(x,w);
			}
			mrg2();
		}
	}
	void udr2(long long lh,long long rh)
	{
		if(l>rh||r<lh);
		else if(l>=lh&&r<=rh)
		{
			swap(wg2[0],wg2[1]);
			swap(fq[0],fq[1]);
			lz2^=1;
			ttl+=fq[0]-fq[1];
		}
		else
		{
			long long ii;
			
			blc2();
			for(ii=0;ii<2;ii++)
			{
				p[ii]->udr2(lh,rh);
			}
			mrg2();
		}
	}
	long long qr(long long x)
	{
		if(l>x||r<x)
		{
			return 0;
		}
		else if(l>=x&&r<=x)
		{
			return c;
		}
		else
		{
			blc();
			return p[0]->qr(x)+p[1]->qr(x);
		}
	}
}
sg[200069];

void bd(long long x)
{
	long long i,sz=al[x].size(),l,p,e;
	pair<long long,long long> mxe={-inf,-1};
	vector<pair<long long,long long>> v;
	
	vtd[x]=1;
	sbt[x]=1;
	an[x]=x;
	fh[x]=dh[x];
	for(i=0;i<sz;i++)
	{
		l=al[x][i].fr;
		p=al[x][i].sc;
		if(!vtd[l])
		{
			dh[l]=dh[x]+1;
			pr[l]=x;
			ped[l]=p;
			bd(l);
			sbt[x]+=sbt[l];
			mxe=max(mxe,{sbt[l],l});
			v.push_back({l,p});
		}
	}
	e=mxe.sc;
	if(e!=-1)
	{
		an[e]=x;
		fh[x]=fh[e];
		for(i=0;v[i].fr!=e;i++);
		swap(v[0],v[i]);
	}
	al[x]=v;
}

void anc(long long x)
{
	long long i,sz=al[x].size(),l;
	
	an[x]=an[an[x]];
	if(an[x]==x)
	{
		sg[x].bd(dh[x],fh[x]);
	}
	for(i=0;i<sz;i++)
	{
		l=al[x][i].fr;
		anc(l);
	}
}

inline void pth(long long x)
{
	long long k,u;
	
	spc[x]=1;
	sg[an[x]].ud(dh[x],ped[x]);
	for(;x;x=pr[an[x]])
	{
		sg[an[x]].udr(dh[an[x]],dh[x]);
		sg[an[x]].udr2(dh[an[x]],dh[x]-1);
		if(pr[an[x]])
		{
			k=sg[an[x]].qr(dh[an[x]]);
			u=k*2-1;
			sg[an[pr[an[x]]]].ud2(dh[pr[an[x]]],u);
		}
	}
}

void dfs(long long x)
{
	long long i,l,sz=al[x].size();
	
	dp[x]=spc[x];
	for(i=0;i<sz;i++)
	{
		l=al[x][i].fr;
		dfs(l);
		dp[x]=dp[x]^dp[l];
	}
	if(dp[x])
	{
		zs++;
		sq[zs]=ped[x];
	}
}

int main()
{
	long long i,ky,k,l;
	
	scanf("%lld",&n);
	for(i=1;i<=n-1;i++)
	{
		scanf("%lld%lld",&k,&l);
		al[k].push_back({l,i});
		al[l].push_back({k,i});
	}
	bd(1);
	anc(1);
	pth(1);
	for(;1;)
	{
		scanf("%lld",&ky);
		if(ky==1)
		{
			scanf("%lld",&k);
			pth(k);
			if(!ttl&&!sg[1].qr(0))
			{
				printf("%lld\n",z);
			}
			else
			{
				printf("0\n");
			}
			fflush(stdout);
		}
		else if(ky==2)
		{
			if(!ttl&&!sg[1].qr(0))
			{
				zs=0;
				dfs(1);
				sort(sq+1,sq+zs+1);
				printf("%lld",zs);
				for(i=1;i<=zs;i++)
				{
					printf(" %lld",sq[i]);
				}
				printf("\n");
			}
			else
			{
				printf("0\n");
			}
			fflush(stdout);
		}
		else
		{
			break;
		}
	}
}