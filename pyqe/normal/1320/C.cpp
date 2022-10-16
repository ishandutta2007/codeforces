#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,d;
pair<long long,long long> at[200069],de[200069];
pair<long long,pair<long long,long long>> mo[200069];

struct segtree
{
	long long l,r,mx,lz=0;
	segtree *p[2];
	
	void bd(long long lh,long long rh)
	{
		l=lh;
		r=rh;
		if(l==r)
		{
			mx=-de[l].sc;
		}
		else
		{
			long long ii,md=(l+r)/2;
			
			mx=-1e18;
			for(ii=0;ii<2;ii++)
			{
				p[ii]=new segtree;
				p[ii]->bd(!ii?l:md+1,!ii?md:r);
				mx=max(mx,p[ii]->mx);
			}
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
		if(lh>rh||l>rh||r<lh);
		else if(l>=lh&&r<=rh)
		{
			mx+=w;
			lz+=w;
		}
		else
		{
			long long ii;
			
			blc();
			mx=-1e18;
			for(ii=0;ii<2;ii++)
			{
				p[ii]->ud(lh,rh,w);
				mx=max(mx,p[ii]->mx);
			}
		}
	}
}
sg;

int main()
{
	long long i,j,k,l,w,cr,p,z=-1e18;
	
	scanf("%lld%lld%lld",&n,&m,&d);
	for(i=1;i<=n;i++)
	{
		scanf("%lld%lld",&k,&l);
		at[i]={k,l};
	}
	sort(at+1,at+n+1);
	for(i=1;i<=m;i++)
	{
		scanf("%lld%lld",&k,&l);
		de[i]={k,l};
	}
	sort(de+1,de+m+1);
	sg.bd(1,m);
	for(i=1;i<=d;i++)
	{
		scanf("%lld%lld%lld",&w,&k,&l);
		mo[i]={w,{k,l}};
	}
	sort(mo+1,mo+d+1);
	for(j=1,i=1;i<=n;i++)
	{
		cr=at[i].fr;
		w=at[i].sc;
		for(;j<=d&&mo[j].fr<cr;j++)
		{
			k=mo[j].sc.fr;
			l=mo[j].sc.sc;
			p=upper_bound(de+1,de+m+1,mp(k,1000000000000000000ll))-de;
			sg.ud(p,m,l);
		}
		z=max(z,sg.mx-w);
	}
	printf("%lld\n",z);
}