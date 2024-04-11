#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

const long long inf=1e18;
long long n,sbt[100069],dh[100069],pr[100069],an[100069],fh[100069],pst[100069],sr[100069];
vector<long long> al[100069];

struct segtree
{
	long long l,r,mx,lz;
	bool clr;
	segtree *p[2];
	
	void bd(long long lh,long long rh)
	{
		l=lh;
		r=rh;
		clr=0;
		lz=0;
		if(l==r)
		{
			mx=dh[sr[r]];
		}
		else
		{
			long long ii,md=(l+r)/2;
			
			for(ii=0;ii<2;ii++)
			{
				p[ii]=new segtree;
				p[ii]->bd(!ii?l:md+1,!ii?md:r);
			}
			mx=max(p[0]->mx,p[1]->mx);
		}
	}
	void blc()
	{
		long long ii;
		
		for(ii=0;ii<2;ii++)
		{
			if(clr)
			{
				p[ii]->mx=dh[sr[p[ii]->r]];
				p[ii]->clr=1;
				p[ii]->lz=0;
			}
			p[ii]->mx+=lz;
			p[ii]->lz+=lz;
		}
		clr=0;
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
			long long ii;
			
			blc();
			for(ii=0;ii<2;ii++)
			{
				p[ii]->ud(lh,rh,w);
			}
			mx=max(p[0]->mx,p[1]->mx);
		}
	}
	void ers(long long lh,long long rh)
	{
		if(l>rh||r<lh);
		else if(l>=lh&&r<=rh)
		{
			mx=dh[sr[r]];
			clr=1;
			lz=0;
		}
		else
		{
			long long ii;
			
			blc();
			for(ii=0;ii<2;ii++)
			{
				p[ii]->ers(lh,rh);
			}
			mx=max(p[0]->mx,p[1]->mx);
		}
	}
	long long qr(long long lh,long long rh)
	{
		if(l>rh||r<lh)
		{
			return -inf;
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
sg;

void bd(long long x)
{
	long long i,sz=al[x].size(),l,e;
	pair<long long,long long> mxe={0,-1};
	
	sbt[x]=1;
	an[x]=x;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		bd(l);
		sbt[x]+=sbt[l];
		mxe=max(mxe,{sbt[l],i});
	}
	e=mxe.sc;
	if(e+1)
	{
		swap(al[x][e],al[x][0]);
	}
}

void bd2(long long x)
{
	long long i,sz=al[x].size(),l;
	
	fh[x]=dh[x];
	n++;
	pst[x]=n;
	sr[n]=x;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		dh[l]=dh[x]+1;
		pr[l]=x;
		if(!i)
		{
			an[l]=an[x];
		}
		bd2(l);
		if(!i)
		{
			fh[x]=fh[l];
		}
	}
}

long long pth(long long x)
{
	long long k,l,w,ww,p,sm=0,mx=0;
	
	for(p=x;p;p=pr[an[p]])
	{
		k=pst[an[p]];
		l=pst[p];
		w=sg.qr(k,l);
		ww=0;
		if(dh[p]<fh[an[p]])
		{
			ww=sg.qr(l+1,l+1)-(dh[p]+1);
		}
		mx=max(mx,w-ww+sm);
		sm+=sg.qr(k,k)-dh[an[p]]-ww;
	}
	return max(mx-dh[x],0ll);
}

int main()
{
	long long t,rr,i,ky,k,w;
	
	scanf("%lld%lld",&n,&t);
	for(i=2;i<=n;i++)
	{
		scanf("%lld",&k);
		al[k].push_back(i);
	}
	bd(1);
	n=0;
	bd2(1);
	sg.bd(1,n);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&ky,&k);
		if(ky==1)
		{
			sg.ud(pst[an[k]],pst[k],1);
		}
		else if(ky==2)
		{
			w=pth(k);
			if(dh[k]<fh[an[k]])
			{
				w+=sg.qr(pst[k]+1,pst[k]+1)-(dh[k]+1);
			}
			sg.ud(pst[an[k]],pst[k],-w);
			sg.ers(pst[k]+1,pst[k]+sbt[k]-1);
		}
		else
		{
			if(pth(k))
			{
				printf("black\n");
			}
			else
			{
				printf("white\n");
			}
		}
	}
}