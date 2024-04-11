#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,as[400069];
pair<long long,long long> a[200069];
map<long long,long long> com;

struct val
{
	long long mn,z;
	bool l,r;
};

long long av(long long x,long long y)
{
	return (x+y)/2;
}

struct segtree
{
	long long l,r,lz,ii;
	val ans;
	segtree *p[2];
	
	val mrg(val x,val y)
	{
		val tmp;
		
		tmp.mn=min(x.mn,y.mn);
		tmp.z=x.z*(x.mn==tmp.mn)+y.z*(y.mn==tmp.mn)-(x.r&&y.l&&x.mn==tmp.mn&&y.mn==tmp.mn);
		tmp.l=x.l&&x.mn==tmp.mn;
		tmp.r=y.r&&y.mn==tmp.mn;
		return tmp;
	}
	void bd(long long lh,long long rh)
	{
		l=lh;
		r=rh;
		lz=0;
		ans.mn=0;
		ans.z=1;
		ans.l=1;
		ans.r=1;
		if(l==r);
		else
		{
			p[0]=new segtree;
			p[1]=new segtree;
			p[0]->bd(l,av(l,r));
			p[1]->bd(av(l,r)+1,r);
		}
	}
	void blc()
	{
		for(ii=0;ii<2;ii++)
		{
			p[ii]->ans.mn+=lz;
			p[ii]->lz+=lz;
		}
		lz=0;
	}
	void ud(long long lh,long long rh,long long w)
	{
		if(l>rh||r<lh);
		else if(l>=lh&&r<=rh)
		{
			ans.mn+=w;
			lz+=w;
		}
		else
		{
			blc();
			p[0]->ud(lh,rh,w);
			p[1]->ud(lh,rh,w);
			ans=mrg(p[0]->ans,p[1]->ans);
		}
	}
}
sg;

int main()
{
	long long t,rr,i,k,l,mx;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%lld%lld",&a[i].fr,&a[i].sc);
			as[i*2-1]=a[i].fr;
			as[i*2]=a[i].sc;
		}
		sort(as+1,as+n*2+1);
		for(i=1;i<=n*2;i++)
		{
			com[as[i]]=i*2-1;
		}
		sg.bd(0,n*4);
		for(i=1;i<=n;i++)
		{
			a[i].fr=com[a[i].fr];
			a[i].sc=com[a[i].sc];
			k=a[i].fr;
			l=a[i].sc;
			sg.ud(k,l,1);
		}
		mx=-1e18;
		for(i=1;i<=n;i++)
		{
			k=a[i].fr;
			l=a[i].sc;
			sg.ud(k,l,-1);
			mx=max(mx,sg.ans.z-1);
			sg.ud(k,l,1);
		}
		printf("%lld\n",mx);
	}
}