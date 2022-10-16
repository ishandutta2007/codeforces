#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

const long long inf=1e18;
long long n,a[100069],fw[100069],fi;
pair<long long,long long> as[100069];

struct segtree
{
	long long l,r;
	pair<long long,long long> mne;
	segtree *p[2];
	
	void bd(long long lh,long long rh)
	{
		l=lh;
		r=rh;
		if(l==r)
		{
			mne={as[l].sc,l};
		}
		else
		{
			long long ii,md=(l+r)/2;
			
			for(ii=0;ii<2;ii++)
			{
				p[ii]=new segtree;
				p[ii]->bd(!ii?l:md+1,!ii?md:r);
			}
			mne=min(p[0]->mne,p[1]->mne);
		}
	}
	void ud(long long x,long long w)
	{
		if(l>x||r<x);
		else if(l>=x&&r<=x)
		{
			mne.fr=w;
		}
		else
		{
			long long ii;
			
			for(ii=0;ii<2;ii++)
			{
				p[ii]->ud(x,w);
			}
			mne=min(p[0]->mne,p[1]->mne);
		}
	}
	pair<long long,long long> qr(long long lh,long long rh)
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
			return min(p[0]->qr(lh,rh),p[1]->qr(lh,rh));
		}
	}
}
sg;

inline void ud(long long x,long long w)
{
	for(fi=x;fi<=n;fi+=fi&-fi)
	{
		fw[fi]+=w;
	}
}

inline long long qr(long long x)
{
	long long z=0;
	
	for(fi=x;fi;fi-=fi&-fi)
	{
		z+=fw[fi];
	}
	return z;
}

int main()
{
	long long t,rr,i,k,l,sm,z;
	pair<long long,long long> tmp;
	char ch;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf(" %c",&ch);
			as[i]={ch-'a',i};
			fw[i]=0;
		}
		sort(as+1,as+n+1);
		for(i=1;i<=n;i++)
		{
			scanf(" %c",&ch);
			a[i]=ch-'a';
		}
		sg.bd(1,n);
		sm=0;
		z=inf;
		for(i=1;i<=n;i++)
		{
			k=upper_bound(as+1,as+n+1,mp(a[i]-1,inf))-as-1;
			l=upper_bound(as+1,as+n+1,mp(a[i],inf))-as-1;
			tmp=sg.qr(1,k);
			if(tmp.fr!=inf)
			{
				z=min(z,sm+tmp.fr-1-qr(tmp.fr));
			}
			tmp=sg.qr(k+1,l);
			if(tmp.fr==inf)
			{
				break;
			}
			sm+=tmp.fr-1-qr(tmp.fr);
			sg.ud(tmp.sc,inf);
			ud(tmp.fr,1);
		}
		if(z==inf)
		{
			z=-1;
		}
		printf("%lld\n",z);
	}
}