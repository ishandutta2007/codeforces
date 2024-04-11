#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n;
bitset<200069> a[2];
pair<long long,long long> qq[200069];

struct segtree
{
	long long l,r,sm,lz;
	segtree *p[2];
	
	void bd(long long lh,long long rh)
	{
		l=lh;
		r=rh;
		lz=-1;
		if(l==r)
		{
			sm=a[1][l];
		}
		else
		{
			long long ii,md=(l+r)/2;
			
			for(ii=0;ii<2;ii++)
			{
				p[ii]=new segtree;
				p[ii]->bd(!ii?l:md+1,!ii?md:r);
			}
			sm=p[0]->sm+p[1]->sm;
		}
	}
	void blc()
	{
		if(lz+1)
		{
			long long ii;
			
			for(ii=0;ii<2;ii++)
			{
				p[ii]->sm=(p[ii]->r-p[ii]->l+1)*lz;
				p[ii]->lz=lz;
			}
			lz=-1;
		}
	}
	void ud(long long lh,long long rh,long long w)
	{
		if(l>rh||r<lh);
		else if(l>=lh&&r<=rh)
		{
			sm=(r-l+1)*w;
			lz=w;
		}
		else
		{
			long long ii;
			
			blc();
			for(ii=0;ii<2;ii++)
			{
				p[ii]->ud(lh,rh,w);
			}
			sm=p[0]->sm+p[1]->sm;
		}
	}
	long long qr(long long lh,long long rh)
	{
		if(l>rh||r<lh)
		{
			return 0;
		}
		else if(l>=lh&&r<=rh)
		{
			return sm;
		}
		else
		{
			blc();
			return p[0]->qr(lh,rh)+p[1]->qr(lh,rh);
		}
	}
}
sg;

int main()
{
	long long tt,rrr,t,rr,i,ii,k,l,w;
	char ch;
	
	scanf("%lld",&tt);
	for(rrr=0;rrr<tt;rrr++)
	{
		scanf("%lld%lld",&n,&t);
		for(ii=0;ii<2;ii++)
		{
			for(i=1;i<=n;i++)
			{
				scanf(" %c",&ch);
				a[ii][i]=ch-'0';
			}
		}
		for(rr=1;rr<=t;rr++)
		{
			scanf("%lld%lld",&k,&l);
			qq[rr]={k,l};
		}
		sg.bd(1,n);
		for(rr=t;rr;rr--)
		{
			k=qq[rr].fr;
			l=qq[rr].sc;
			w=sg.qr(k,l);
			if(w*2==l-k+1)
			{
				break;
			}
			sg.ud(k,l,w*2>l-k+1);
		}
		for(i=1;i<=n;i++)
		{
			if(sg.qr(i,i)!=a[0][i])
			{
				break;
			}
		}
		if(!rr&&i>n)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}