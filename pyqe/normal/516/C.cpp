#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,ds[200069],a[200069],ps[200069],inf=1e18;
array<array<pair<long long,long long>,2>,2> z0;

struct segtree
{
	long long l,r;
	array<array<pair<long long,long long>,2>,2> z;
	segtree *p[2];
	
	array<array<pair<long long,long long>,2>,2> mrg(array<array<pair<long long,long long>,2>,2> x,array<array<pair<long long,long long>,2>,2> y)
	{
		long long ii;
		array<array<pair<long long,long long>,2>,2> tmp;
		
		for(ii=0;ii<2;ii++)
		{
			tmp[ii][0]=max(x[ii][0],y[ii][0]);
			tmp[ii][1]=max(min(x[ii][0],y[ii][0]),max(x[ii][1],y[ii][1]));
		}
		return tmp;
	}
	void bd(long long lh,long long rh)
	{
		long long ii,u,md;
		
		l=lh;
		r=rh;
		if(l==r)
		{
			for(ii=0;ii<2;ii++)
			{
				u=!ii*2-1;
				z[ii][0]={a[l]*2+ps[l]*u,l};
				z[ii][1]={-inf,-1ll};
			}
		}
		else
		{
			md=(l+r)/2;
			for(ii=0;ii<2;ii++)
			{
				p[ii]=new segtree;
				p[ii]->bd(!ii?l:md+1,!ii?md:r);
			}
			z=mrg(p[0]->z,p[1]->z);
		}
	}
	array<array<pair<long long,long long>,2>,2> qr(long long lh,long long rh)
	{
		if(l>rh||r<lh)
		{
			return z0;
		}
		else if(l>=lh&&r<=rh)
		{
			return z;
		}
		else
		{
			return mrg(p[0]->qr(lh,rh),p[1]->qr(lh,rh));
		}
	}
}
sg;

int main()
{
	long long t,rr,i,ii,iii,k,l,z;
	array<array<pair<long long,long long>,2>,2> tmp;
	
	for(ii=0;ii<2;ii++)
	{
		for(iii=0;iii<2;iii++)
		{
			z0[ii][iii]={-inf,-1};
		}
	}
	scanf("%lld%lld",&n,&t);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",ds+i);
	}
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	for(i=n+1;i<=n*2;i++)
	{
		ds[i]=ds[i-n];
		a[i]=a[i-n];
	}
	for(i=1;i<=n*2;i++)
	{
		ps[i]=ps[i-1]+ds[i-1];
	}
	sg.bd(1,n*2);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&k,&l);
		if(k<=l)
		{
			k+=n;
		}
		tmp=sg.qr(l+1,k-1);
		z=-inf;
		for(ii=0;ii<2;ii++)
		{
			for(iii=0;iii<2;iii++)
			{
				if(tmp[0][ii].sc!=tmp[1][iii].sc)
				{
					z=max(z,tmp[0][ii].fr+tmp[1][iii].fr);
				}
			}
		}
		printf("%lld\n",z);
	}
}