#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,d,as[600069];
pair<long long,long long> a[300069],qq[300069],qs[600069];
bitset<300069> fq;

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
}
sg;

int main()
{
	long long i,ii,jj,u,k,l,w,y,x,e,pz,z=0;
	
	scanf("%lld%lld",&n,&d);
	for(i=1;i<=n;i++)
	{
		scanf("%lld%lld",&y,&x);
		a[i]={y,x};
	}
	for(ii=0;ii<2;ii++)
	{
		for(i=1;i<=n;i++)
		{
			y=a[i].fr;
			x=a[i].sc;
			e=abs(y+x)%2^ii;
			k=x-(d-e)-y;
			l=x+d-e-y;
			qq[i]={k,l};
			as[i*2-1]=k;
			as[i*2]=l;
			qs[i*2-1]={y+x-(d-e),i};
			qs[i*2]={y+x+d-e+1,i};
		}
		sort(as+1,as+n*2+1);
		sort(qs+1,qs+n*2+1);
		for(i=1;i<=n;i++)
		{
			for(jj=0;jj<2;jj++)
			{
				qq[i].fr=lower_bound(as+1,as+n*2+1,qq[i].fr)-as;
				swap(qq[i].fr,qq[i].sc);
			}
		}
		sg.bd(1,n*2);
		for(i=1;i<=n*2;i++)
		{
			w=qs[i].fr;
			pz=qs[i].sc;
			k=qq[pz].fr;
			l=qq[pz].sc;
			u=!fq[pz]*2-1;
			fq[pz]=!fq[pz];
			sg.ud(k,l,u);
			if(i==n*2||w!=qs[i+1].fr)
			{
				z=max(z,sg.mx);
			}
		}
	}
	printf("%lld\n",z);
}