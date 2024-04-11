#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,nn,a[100069],sk[100069],fh[2][100069],sq[100069],inf=1e18;
vector<pair<long long,long long>> udl[100069];
pair<long long,long long> qq[100069];
vector<long long> ql[100069];

struct segtree
{
	long long l,r,mx,sm,sl;
	segtree *p[2];
	
	void bd(long long lh,long long rh)
	{
		l=lh;
		r=rh;
		if(l==r)
		{
			mx=a[l];
			sm=0;
			sl=1;
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
			sm=p[0]->sm+p[1]->sm;
			sl=p[0]->sl+p[1]->sl;
		}
	}
	void ud(long long xx,long long x,long long w)
	{
		if(l>x||r<x);
		else if(l>=x&&r<=x)
		{
			sm-=xx*w;
			sl+=w;
			if(!sm&&!sl)
			{
				mx=-inf;
			}
		}
		else
		{
			long long ii;
			
			for(ii=0;ii<2;ii++)
			{
				p[ii]->ud(xx,x,w);
			}
			mx=max(p[0]->mx,p[1]->mx);
			sm=p[0]->sm+p[1]->sm;
			sl=p[0]->sl+p[1]->sl;
		}
	}
	long long qr(long long xx,long long lh,long long rh)
	{
		if(1>rh||sm+sl*xx<lh)
		{
			return -inf;
		}
		else if(l==r||(1>=lh&&sm+sl*xx<=rh))
		{
			return mx;
		}
		else
		{
			long long w=p[0]->sm+p[0]->sl*xx;
			
			return max(p[0]->qr(xx,lh,rh),p[1]->qr(xx,lh-w,rh-w));
		}
	}
}
sg;

int main()
{
	long long t,rr,i,j,ii,u,k,l,w,sz,pz;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	for(ii=0;ii<2;ii++)
	{
		u=!ii*2-1;
		nn=0;
		sk[nn]=(n+1)*ii;
		for(i=1+(n-1)*ii;i&&i<=n;i+=u)
		{
			for(;nn&&a[i]-ii<a[sk[nn]];nn--);
			fh[ii][i]=abs(i-sk[nn]);
			udl[fh[ii][i]].push_back({i,-1});
			nn++;
			sk[nn]=i;
		}
	}
	for(i=1;i<=n;i++)
	{
		udl[fh[0][i]+fh[1][i]].push_back({i,1});
	}
	scanf("%lld",&t);
	for(rr=1;rr<=t;rr++)
	{
		scanf("%lld%lld%lld",&k,&l,&w);
		qq[rr]={k,l-w+1};
		ql[w].push_back(rr);
	}
	sg.bd(1,n);
	for(i=1;i<=n;i++)
	{
		sz=udl[i].size();
		for(j=0;j<sz;j++)
		{
			k=udl[i][j].fr;
			w=udl[i][j].sc;
			sg.ud(i,k,w);
		}
		sz=ql[i].size();
		for(j=0;j<sz;j++)
		{
			pz=ql[i][j];
			k=qq[pz].fr;
			l=qq[pz].sc;
			sq[pz]=sg.qr(i,k,l);
		}
	}
	for(rr=1;rr<=t;rr++)
	{
		printf("%lld\n",sq[rr]);
	}
}