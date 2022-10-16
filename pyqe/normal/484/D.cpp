#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,nn[2];
pair<long long,long long> sk[2][1000069];

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
			mx=0;
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
			mx=-1e18;
			for(ii=0;ii<2;ii++)
			{
				p[ii]->ud(lh,rh,w);
				mx=max(mx,p[ii]->mx);
			}
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
			return max(p[0]->qr(lh,rh),p[1]->qr(lh,rh));
		}
	}
}
sg;

int main()
{
	long long i,ii,u,k,l,w,p,z;
	
	scanf("%lld",&n);
	sg.bd(1,n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		for(ii=0;ii<2;ii++)
		{
			u=!ii*2-1;
			for(;nn[ii]&&sk[ii][nn[ii]].fr*u<=k*u;nn[ii]--)
			{
				w=sk[ii][nn[ii]].fr;
				p=sk[ii][nn[ii]].sc;
				l=sk[ii][nn[ii]-1].sc;
				sg.ud(l+1,p,abs(k-w));
			}
			nn[ii]++;
			sk[ii][nn[ii]]={k,i};
		}
		z=sg.qr(1,i);
		sg.ud(i+1,i+1,z);
	}
	printf("%lld\n",z);
}