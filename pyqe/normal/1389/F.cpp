#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,as[400069],inf=1e18;
pair<pair<long long,long long>,long long> a[200069];

struct segtree
{
	long long l,r,mx,lz;
	segtree *p[2];
	
	void bd(long long lh,long long rh)
	{
		l=lh;
		r=rh;
		mx=0;
		lz=0;
		if(l!=r)
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
	long long qr(long long lh,long long rh)
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
			return max(p[0]->qr(lh,rh),p[1]->qr(lh,rh));
		}
	}
}
sg[2];

long long com(long long k)
{
	return lower_bound(as+1,as+n*2+1,k)-as;
}

int main()
{
	long long i,j,ii,k,l,ky,mx[2]={0,0};
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld%lld%lld",&k,&l,&ky);
		k--;
		ky--;
		a[i]={{l,k},ky};
		as[i*2-1]=k;
		as[i*2]=l;
	}
	sort(as+1,as+n*2+1);
	for(i=1;i<=n;i++)
	{
		a[i].fr.fr=com(a[i].fr.fr);
		a[i].fr.sc=-com(a[i].fr.sc);
	}
	sort(a+1,a+n+1);
	for(ii=0;ii<2;ii++)
	{
		sg[ii].bd(1,n*2);
	}
	for(j=1,i=1;i<=n;i++)
	{
		k=-a[i].fr.sc;
		l=a[i].fr.fr;
		ky=a[i].sc;
		for(;j<l;j++)
		{
			for(ii=0;ii<2;ii++)
			{
				sg[!ii].ud(j,j,mx[ii]);
			}
		}
		sg[ky].ud(1,k,1);
		mx[ky]=max(mx[ky],sg[ky].qr(1,k));
	}
	printf("%lld\n",max(mx[0],mx[1]));
}