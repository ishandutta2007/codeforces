#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,nn=0,ky[1000069];
pair<pair<long long,long long>,long long> a[500069];
map<long long,bool> vtd;
map<long long,long long> pst;

long long md(long long l,long long r)
{
	return (l+r)/2;
}

struct segtree
{
	long long l,r,lz;
	pair<long long,long long> mx;
	segtree *p1,*p2;
	
	void bd(long long lh,long long rh)
	{
		l=lh;
		r=rh;
		lz=0;
		if(lh==rh)
		{
			mx={ky[lh],lh};
		}
		else
		{
			p1=new segtree;
			p2=new segtree;
			p1->bd(lh,md(lh,rh));
			p2->bd(md(lh,rh)+1,rh);
			mx=max(p1->mx,p2->mx);
		}
	}
	void blc()
	{
		p1->mx.fr+=lz;
		p2->mx.fr+=lz;
		p1->lz+=lz;
		p2->lz+=lz;
		lz=0;
	}
	void ud(long long lh,long long rh,long long w)
	{
		if(l>rh||r<lh);
		else if(l>=lh&&r<=rh)
		{
			mx.fr+=w;
			lz+=w;
		}
		else
		{
			blc();
			p1->ud(lh,rh,w);
			p2->ud(lh,rh,w);
			mx=max(p1->mx,p2->mx);
		}
	}
	pair<long long,long long> qr(long long lh,long long rh)
	{
		if(l>rh||r<lh)
		{
			return {-1e18,-1};
		}
		else if(l>=lh&&r<=rh)
		{
			return mx;
		}
		else
		{
			blc();
			return max(p1->qr(lh,rh),p2->qr(lh,rh));
		}
	}
}
sg;

int main()
{
	long long i,j,k,l,w,mx=-1e18,e1=-1,e2=-1;
	pair<long long,long long> tmp;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld%lld%lld",&k,&l,&w);
		if(k>l)
		{
			swap(k,l);
		}
		a[i]={{l,k},w};
		if(!vtd[k])
		{
			nn++;
			ky[nn]=k;
			vtd[k]=1;
		}
		if(!vtd[l])
		{
			nn++;
			ky[nn]=l;
			vtd[l]=1;
		}
	}
	sort(ky+1,ky+nn+1);
	sg.bd(1,nn);
	for(i=1;i<=nn;i++)
	{
		pst[ky[i]]=i;
	}
	for(i=0;i<n;i++)
	{
		a[i].fr.fr=pst[a[i].fr.fr];
		a[i].fr.sc=pst[a[i].fr.sc];
	}
	sort(a,a+n);
	for(j=0,i=1;i<=nn;i++)
	{
		for(;j<n&&a[j].fr.fr<=i;j++)
		{
			sg.ud(1,a[j].fr.sc,a[j].sc);
		}
		tmp=sg.qr(1,i);
		tmp.fr-=ky[i];
		if(tmp.fr>mx)
		{
			mx=tmp.fr;
			e1=ky[tmp.sc];
			e2=ky[i];
		}
	}
	if(mx>=0)
	{
		printf("%lld\n%lld %lld %lld %lld\n",mx,e1,e1,e2,e2);
	}
	else
	{
		printf("0\n2000000000 2000000000 2000000000 2000000000\n");
	}
}