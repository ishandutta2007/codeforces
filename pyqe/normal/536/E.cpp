#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

const long long inf=1e18;
long long n,a[100069],dh[100069],pr[100069],sbt[100069],an[100069],fh[100069],sq[100069];
pair<long long,pair<long long,long long>> ed[100069];
vector<pair<long long,long long>> al[100069];
bitset<100069> vtd;
pair<long long,long long> qq[100069],as[100069];
pair<pair<long long,bool>,pair<long long,long long>> v0={{0,1},{0,0}};

pair<pair<long long,bool>,pair<long long,long long>> mrg(pair<pair<long long,bool>,pair<long long,long long>> x,pair<pair<long long,bool>,pair<long long,long long>> y)
{
	pair<pair<long long,bool>,pair<long long,long long>> z;
	
	z.fr.fr=x.fr.fr+y.fr.fr+a[x.sc.sc+y.sc.fr]*(!x.fr.sc&&!y.fr.sc);
	z.fr.sc=x.fr.sc&&y.fr.sc;
	z.sc.fr=x.sc.fr+y.sc.fr*x.fr.sc;
	z.sc.sc=y.sc.sc+x.sc.sc*y.fr.sc;
	return z;
}

struct segtree
{
	long long l,r;
	pair<pair<long long,bool>,pair<long long,long long>> sm;
	segtree *p[2];
	
	void bd(long long lh,long long rh)
	{
		l=lh;
		r=rh;
		sm={{0,0},{0,0}};
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
	void ud(long long x)
	{
		if(l>x||r<x);
		else if(l>=x&&r<=x)
		{
			sm={{0,1},{1,1}};
		}
		else
		{
			long long ii;
			
			for(ii=0;ii<2;ii++)
			{
				p[ii]->ud(x);
			}
			sm=mrg(p[0]->sm,p[1]->sm);
		}
	}
	pair<pair<long long,bool>,pair<long long,long long>> qr(long long lh,long long rh)
	{
		if(l>rh||r<lh)
		{
			return v0;
		}
		else if(l>=lh&&r<=rh)
		{
			return sm;
		}
		else
		{
			return mrg(p[0]->qr(lh,rh),p[1]->qr(lh,rh));
		}
	}
}
sg[100069];

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
		l=al[x][i].fr;
		if(!vtd[l])
		{
			dh[l]=dh[x]+1;
			pr[l]=x;
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

void bd2(long long x)
{
	long long i,sz=al[x].size(),l;
	
	vtd[x]=1;
	an[x]=an[an[x]];
	if(an[x]==x)
	{
		sg[x].bd(dh[x],fh[x]);
	}
	for(i=0;i<sz;i++)
	{
		l=al[x][i].fr;
		if(!vtd[l])
		{
			bd2(l);
		}
	}
}

long long pth(long long x,long long y)
{
	long long p[2]={x,y},e;
	pair<pair<long long,bool>,pair<long long,long long>> sm[2]={v0,v0};
	
	for(;an[p[0]]!=an[p[1]];p[e]=pr[an[p[e]]])
	{
		e=dh[an[p[1]]]>dh[an[p[0]]];
		sm[e]=mrg(sg[an[p[e]]].qr(dh[an[p[e]]],dh[p[e]]),sm[e]);
	}
	e=dh[p[1]]>dh[p[0]];
	sm[e]=mrg(sg[an[p[e]]].qr(dh[p[!e]]+1,dh[p[e]]),sm[e]);
	swap(sm[0].sc.fr,sm[0].sc.sc);
	sm[0]=mrg(sm[0],sm[1]);
	return sm[0].fr.fr+a[sm[0].sc.fr]+a[sm[0].sc.sc]*!sm[0].fr.sc;
}

int main()
{
	long long t,rr,i,k,l,w,kk,ll,pz;
	
	scanf("%lld%lld",&n,&t);
	for(i=1;i<=n-1;i++)
	{
		scanf("%lld",a+i);
	}
	for(i=1;i<=n-1;i++)
	{
		scanf("%lld%lld%lld",&k,&l,&w);
		ed[i]={w,{k,l}};
		al[k].push_back({l,w});
		al[l].push_back({k,w});
	}
	sort(ed+1,ed+n,greater<pair<long long,pair<long long,long long>>>());
	bd(1);
	vtd.reset();
	bd2(1);
	for(rr=1;rr<=t;rr++)
	{
		scanf("%lld%lld%lld",&k,&l,&w);
		qq[rr]={k,l};
		as[rr]={w,rr};
	}
	sort(as+1,as+t+1,greater<pair<long long,long long>>());
	for(i=1,rr=1;rr<=t;rr++)
	{
		w=as[rr].fr;
		pz=as[rr].sc;
		k=qq[pz].fr;
		l=qq[pz].sc;
		for(;i<=n-1&&ed[i].fr>=w;i++)
		{
			kk=ed[i].sc.fr;
			ll=ed[i].sc.sc;
			if(dh[kk]<dh[ll])
			{
				swap(kk,ll);
			}
			sg[an[kk]].ud(dh[kk]);
		}
		sq[pz]=pth(k,l);
	}
	for(rr=1;rr<=t;rr++)
	{
		printf("%lld\n",sq[rr]);
	}
}