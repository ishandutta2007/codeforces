#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,a[100069];

long long md(long long l,long long r)
{
	return (l+r)/2;
}

struct segtree
{
	long long l,r;
	pair<long long,pair<long long,long long>> ans;
	segtree *p1,*p2;
	
	pair<long long,pair<long long,long long>> mrg(pair<long long,pair<long long,long long>> x,pair<long long,pair<long long,long long>> y)
	{
		pair<long long,pair<long long,long long>> tmp={__gcd(x.fr,y.fr),{min(x.sc.fr,y.sc.fr),0}};
		
		if(x.sc.fr==tmp.sc.fr)
		{
			tmp.sc.sc+=x.sc.sc;
		}
		if(y.sc.fr==tmp.sc.fr)
		{
			tmp.sc.sc+=y.sc.sc;
		}
		return tmp;
	}
	void bd(long long lh,long long rh)
	{
		l=lh;
		r=rh;
		if(lh==rh)
		{
			ans={a[lh],{a[lh],1}};
		}
		else
		{
			p1=new segtree;
			p2=new segtree;
			p1->bd(lh,md(lh,rh));
			p2->bd(md(lh,rh)+1,rh);
			ans=mrg(p1->ans,p2->ans);
		}
	}
	pair<long long,pair<long long,long long>> qr(long long lh,long long rh)
	{
		if(l>rh||r<lh)
		{
			return {0,{1e18,0}};
		}
		else if(l>=lh&&r<=rh)
		{
			return ans;
		}
		else
		{
			return mrg(p1->qr(lh,rh),p2->qr(lh,rh));
		}
	}
}
sg;

int main()
{
	long long t,rr,i,k,l,z;
	pair<long long,pair<long long,long long>> tmp;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	sg.bd(1,n);
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&k,&l);
		tmp=sg.qr(k,l);
		if(tmp.fr==tmp.sc.fr)
		{
			z=tmp.sc.sc;
		}
		else
		{
			z=0;
		}
		printf("%lld\n",l-k+1-z);
	}
}