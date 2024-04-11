#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,pst[150069],sbt[150069],ev[150069],an[150069],pr[150069],lz[150069],pwk,dv=998244353;
vector<long long> al[150069];
bitset<150069> vtd;

long long pw(long long x,long long y)
{
	if(!y)
	{
		return 1;
	}
	pwk=pw(x,y/2);
	pwk=pwk*pwk%dv;
	if(y%2)
	{
		pwk=pwk*x%dv;
	}
	return pwk;
}

long long md(long long lh,long long rh)
{
	return (lh+rh)/2;
}

struct segtree
{
	long long l,r,sm,lz;
	segtree *p1,*p2;
	
	void bd(long long lh,long long rh)
	{
		l=lh;
		r=rh;
		sm=0;
		lz=0;
		if(lh==rh);
		else
		{
			p1=new segtree;
			p2=new segtree;
			p1->bd(l,md(l,r));
			p2->bd(md(l,r)+1,r);
		}
	}
	void blc()
	{
		p1->sm=(p1->sm+lz*(p1->r-p1->l+1))%dv;
		p2->sm=(p2->sm+lz*(p2->r-p2->l+1))%dv;
		p1->lz=(p1->lz+lz)%dv;
		p2->lz=(p2->lz+lz)%dv;
		lz=0;
	}
	void ud(long long lh,long long rh,long long w)
	{
		if(lh>rh||l>rh||r<lh);
		else if(l>=lh&&r<=rh)
		{
			sm=(sm+w*(r-l+1))%dv;
			lz=(lz+w)%dv;
		}
		else
		{
			blc();
			p1->ud(lh,rh,w);
			p2->ud(lh,rh,w);
			sm=(p1->sm+p2->sm)%dv;
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
			return sm;
		}
		else
		{
			blc();
			return (p1->qr(x)+p2->qr(x))%dv;
		}
	}
}
sg;

void dfs(long long x)
{
	long long i,sz=al[x].size(),l;
	pair<long long,long long> mxe={-1e18,-1};
	
	n++;
	vtd[x]=1;
	pst[x]=n;
	sbt[x]=1;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			dfs(l);
			pr[l]=x;
			sbt[x]+=sbt[l];
			mxe=max(mxe,{sbt[l],l});
		}
	}
	ev[x]=mxe.sc;
	if(ev[x]!=-1)
	{
		an[ev[x]]=x;
	}
}

void anc(long long x)
{
	long long i,sz=al[x].size(),l;
	
	vtd[x]=1;
	an[x]=an[an[x]];
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			anc(l);
		}
	}
}

int main()
{
	long long t,rr,i,ky,k,l,dn,z,p;
	
	scanf("%lld%lld",&n,&t);
	for(i=0;i<n-1;i++)
	{
		scanf("%lld%lld",&k,&l);
		al[k].push_back(l);
		al[l].push_back(k);
	}
	for(i=1;i<=n;i++)
	{
		an[i]=i;
	}
	n=0;
	dfs(1);
	vtd.reset();
	anc(1);
	sg.bd(1,n);
	dn=pw(n,dv-2);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&ky,&k);
		if(ky==1)
		{
			scanf("%lld",&l);
			sg.ud(1,pst[k]-1,l*sbt[k]%dv);
			sg.ud(pst[k]+sbt[k],n,l*sbt[k]%dv);
			sg.ud(pst[k],pst[k],l*n%dv);
			if(ev[k]!=-1)
			{
				sg.ud(pst[ev[k]],pst[ev[k]]+sbt[ev[k]]-1,l*(n-sbt[ev[k]])%dv);
			}
			lz[k]=(lz[k]+l)%dv;
		}
		else
		{
			z=sg.qr(pst[k]);
			for(p=an[k];p!=1;)
			{
				z=(z+lz[pr[p]]*(n-sbt[p]))%dv;
				p=an[pr[p]];
			}
			printf("%lld\n",z*dn%dv);
		}
	}
}