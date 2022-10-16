#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,d,d2,inf=1e18;
pair<long long,pair<long long,long long>> a[500069];

struct segtree
{
	long long l,r,mx,lz;
	pair<long long,long long> mne;
	segtree *p[2];
	
	void bd(long long lh,long long rh)
	{
		l=lh;
		r=rh;
		lz=0;
		if(l==r)
		{
			mx=d2-a[l].fr;
			mne={a[l].sc.sc,l};
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
			mne=min(p[0]->mne,p[1]->mne);
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
			long long ii;
			
			blc();
			for(ii=0;ii<2;ii++)
			{
				p[ii]->ud(lh,rh,w);
			}
			mx=max(p[0]->mx,p[1]->mx);
		}
	}
	void ers(long long x)
	{
		if(l>x||r<x);
		else if(l>=x&&r<=x)
		{
			mne.fr=inf;
		}
		else
		{
			long long ii;
			
			for(ii=0;ii<2;ii++)
			{
				p[ii]->ers(x);
			}
			mne=min(p[0]->mne,p[1]->mne);
		}
	}
	long long qx(long long lh,long long rh)
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
			return max(p[0]->qx(lh,rh),p[1]->qx(lh,rh));
		}
	}
	pair<long long,long long> qne(long long lh,long long rh)
	{
		if(l>rh||r<lh)
		{
			return {inf,-1};
		}
		else if(l>=lh&&r<=rh)
		{
			return mne;
		}
		else
		{
			return min(p[0]->qne(lh,rh),p[1]->qne(lh,rh));
		}
	}
}
sg;

int main()
{
	long long t,rr,i,k,l,w,sm,z;
	pair<long long,long long> tmp;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld%lld",&n,&m,&d,&d2);
		for(i=1;i<=n;i++)
		{
			scanf("%lld%lld%lld",&k,&l,&w);
			a[i]={k,{l,w}};
		}
		sort(a+1,a+n+1);
		a[n+1]={m,{0,inf}};
		sg.bd(1,n+1);
		z=0;
		for(i=1;i<=n+1&&i;i++)
		{
			sm=max(-sg.qx(i,i),0ll);
			for(;sm;)
			{
				tmp=sg.qne(1,i-1);
				if(tmp.fr==inf)
				{
					z=-1;
					i=-1;
					break;
				}
				k=tmp.sc;
				w=min(sm,min(a[k].sc.fr,d-sg.qx(k,i)));
				z+=tmp.fr*w;
				sm-=w;
				a[k].sc.fr-=w;
				sg.ud(k,n+1,w);
				if(!w)
				{
					sg.ers(k);
				}
			}
		}
		printf("%lld\n",z);
	}
}