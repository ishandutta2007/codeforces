#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,as[400069],lg2[100069];
pair<pair<long long,long long>,pair<long long,long long>> a[100069];
map<long long,long long> pst;
pair<long long,long long> sp[17][100069];
pair<long long,pair<long long,long long>> qq[100069];

long long md(long long lh,long long rh)
{
	return (lh+rh)/2;
}

struct segtree
{
	long long l,r,mx,mn;
	segtree *p1,*p2;
	
	void bd(long long lh,long long rh)
	{
		l=lh;
		r=rh;
		mx=-1e18;
		mn=1e18;
		if(l==r);
		else
		{
			p1=new segtree;
			p2=new segtree;
			p1->bd(l,md(l,r));
			p2->bd(md(l,r)+1,r);
		}
	}
	void ud(long long ky,long long x,long long w)
	{
		if(l>x||r<x);
		else if(l>=x&&r<=x)
		{
			if(!ky)
			{
				mx=max(mx,w);
			}
			else
			{
				mn=min(mn,w);
			}
		}
		else
		{
			p1->ud(ky,x,w);
			p2->ud(ky,x,w);
			mx=max(p1->mx,p2->mx);
			mn=min(p1->mn,p2->mn);
		}
	}
	long long qr(long long ky,long long lh,long long rh)
	{
		if(l>rh||r<lh)
		{
			return -1e18+(2e18*ky);
		}
		else if(l>=lh&&r<=rh)
		{
			return mx*!ky+mn*ky;
		}
		else
		{
			if(!ky)
			{
				return max(p1->qr(ky,lh,rh),p2->qr(ky,lh,rh));
			}
			else
			{
				return min(p1->qr(ky,lh,rh),p2->qr(ky,lh,rh));
			}
		}
	}
}
sg;

void bd()
{
	long long i,j;
	pair<long long,long long> k,l;
	
	for(i=1;i<=n;i++)
	{
		sp[0][i]=a[i].sc;
	}
	for(i=1;1<=n+1-(1<<i);i++)
	{
		for(j=1;j<=n+1-(1<<i);j++)
		{
			k=sp[i-1][j];
			l=sp[i-1][j+(1<<i-1)];
			sp[i][j]={max(k.fr,l.fr),min(k.sc,l.sc)};
		}
	}
}

pair<long long,long long> qr(long long lh,long long rh)
{
	long long ln=rh-lh+1,e=lg2[ln];
	pair<long long,long long> k,l;
	
	k=sp[e][lh];
	l=sp[e][rh+1-(1<<e)];
	return {max(k.fr,l.fr),min(k.sc,l.sc)};
}

int main()
{
	long long i,j,k,l,w,p,kk,ll;
	pair<long long,long long> tmp;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		for(k=i;k>1;k/=2,lg2[i]++);
	}
	for(i=1;i<=n;i++)
	{
		scanf("%lld%lld%lld%lld",&a[i].fr.sc,&a[i].fr.fr,&a[i].sc.fr,&a[i].sc.sc);
		as[i*4-3]=a[i].fr.fr;
		as[i*4-2]=a[i].fr.sc;
		as[i*4-1]=a[i].sc.fr;
		as[i*4]=a[i].sc.sc;
	}
	sort(as+1,as+n*4+1);
	for(i=1;i<=n*4;i++)
	{
		pst[as[i]]=i;
	}
	for(i=1;i<=n;i++)
	{
		a[i].fr.fr=pst[a[i].fr.fr];
		a[i].fr.sc=pst[a[i].fr.sc];
		a[i].sc.fr=pst[a[i].sc.fr];
		a[i].sc.sc=pst[a[i].sc.sc];
	}
	sort(a+1,a+n+1);
	bd();
	for(i=1;i<=n;i++)
	{
		w=a[i].fr.sc;
		k=a[i].sc.fr;
		l=a[i].sc.sc;
		p=upper_bound(a+1,a+n+1,mp(mp(w,0ll),mp(0ll,0ll)))-a;
		tmp=qr(p,i);
		if(tmp.fr>l||tmp.sc<k)
		{
			printf("NO\n");
			return 0;
		}
		qq[i]={p,{k,l}};
	}
	sort(qq+1,qq+n+1);
	sg.bd(1,n*4);
	for(j=1,i=1;i<=n;i++)
	{
		p=qq[i].fr;
		k=qq[i].sc.fr;
		l=qq[i].sc.sc;
		for(;j<p;j++)
		{
			kk=a[j].sc.fr;
			ll=a[j].sc.sc;
			sg.ud(0,kk,ll);
			sg.ud(1,ll,kk);
		}
		if(sg.qr(0,1,l)>=k||sg.qr(1,k,n*4)<=l)
		{
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
}