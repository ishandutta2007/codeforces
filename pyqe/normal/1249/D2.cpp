#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long md(long long l,long long r)
{
	return (l+r)/2;
}

struct segtree
{
	long long l,r,mx,lz;
	segtree *p1,*p2;
	
	void bd(long long lh,long long rh)
	{
		l=lh;
		r=rh;
		lz=0;
		if(lh==rh)
		{
			mx=0;
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
		p1->mx+=lz;
		p2->mx+=lz;
		p1->lz+=lz;
		p2->lz+=lz;
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
			blc();
			p1->ud(lh,rh,w);
			p2->ud(lh,rh,w);
			mx=max(p1->mx,p2->mx);
		}
	}
	long long qr(long long lh,long long rh)
	{
		if(l>rh||r<lh)
		{
			return -1e18;
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

long long n,d,z=0,c=0;
pair<pair<long long,long long>,long long> a[200069];
vector<long long> sq;

int main()
{
	long long i,j,k,l,pz;
	
	scanf("%lld%lld",&n,&d);
	for(i=1;i<=n;i++)
	{
		scanf("%lld%lld",&a[i].fr.sc,&a[i].fr.fr);
		a[i].sc=i;
	}
	sort(a+1,a+n+1);
	sg.bd(1,200000);
	for(i=1;i<=n;i++)
	{
		k=a[i].fr.sc;
		l=a[i].fr.fr;
		pz=a[i].sc;
		if(sg.qr(k,l)<d)
		{
			sg.ud(k,l,1);
		}
		else
		{
			sq.push_back(pz);
			z++;
		}
	}
	sort(sq.begin(),sq.end());
	printf("%lld\n",z);
	for(i=0;i<z;i++)
	{
		printf("%lld%c",sq[i]," \n"[i==z-1]);
	}
}