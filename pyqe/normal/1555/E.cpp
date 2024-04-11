#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

const long long inf=1e18;
long long n,m;
pair<long long,pair<long long,long long>> a[300069];

struct segtree
{
	long long l,r,mn,lz;
	segtree *p[2];
	
	void bd(long long lh,long long rh)
	{
		l=lh;
		r=rh;
		mn=0;
		lz=0;
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
	void blc()
	{
		long long ii;
		
		for(ii=0;ii<2;ii++)
		{
			p[ii]->mn+=lz;
			p[ii]->lz+=lz;
		}
		lz=0;
	}
	void ud(long long lh,long long rh,long long w)
	{
		if(l>rh||r<lh);
		else if(l>=lh&&r<=rh)
		{
			mn+=w;
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
			mn=min(p[0]->mn,p[1]->mn);
		}
	}
}
sg;

int main()
{
	long long i,j,k,l,w,z=inf;
	
	scanf("%lld%lld",&n,&m);
	m--;
	for(i=1;i<=n;i++)
	{
		scanf("%lld%lld%lld",&k,&l,&w);
		l--;
		a[i]={w,{k,l}};
	}
	sort(a+1,a+n+1);
	sg.bd(1,m);
	for(j=0,i=1;i<=n;i++)
	{
		for(;sg.mn==0;)
		{
			j++;
			if(j>n)
			{
				break;
			}
			k=a[j].sc.fr;
			l=a[j].sc.sc;
			sg.ud(k,l,1);
		}
		if(j>n)
		{
			break;
		}
		k=a[i].sc.fr;
		l=a[i].sc.sc;
		w=a[i].fr;
		z=min(z,a[j].fr-w);
		sg.ud(k,l,-1);
	}
	printf("%lld\n",z);
}