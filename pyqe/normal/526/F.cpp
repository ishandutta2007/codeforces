#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,nn[2],a[300069],sk[2][300069],inf=1e18;

struct segtree
{
	long long l,r,lz;
	pair<long long,long long> mn;
	segtree *p[2];
	
	pair<long long,long long> mrg(pair<long long,long long> x,pair<long long,long long> y)
	{
		pair<long long,long long> z;
		
		z.fr=min(x.fr,y.fr);
		z.sc=x.sc*(x.fr==z.fr)+y.sc*(y.fr==z.fr);
		return z;
	}
	void bd(long long lh,long long rh)
	{
		l=lh;
		r=rh;
		lz=0;
		if(l==r)
		{
			mn={0,1};
		}
		else
		{
			long long ii,md=(l+r)/2;
			
			for(ii=0;ii<2;ii++)
			{
				p[ii]=new segtree;
				p[ii]->bd(!ii?l:md+1,!ii?md:r);
			}
			mn=mrg(p[0]->mn,p[1]->mn);
		}
	}
	void blc()
	{
		long long ii;
		
		for(ii=0;ii<2;ii++)
		{
			p[ii]->mn.fr+=lz;
			p[ii]->lz+=lz;
		}
		lz=0;
	}
	void ud(long long lh,long long rh,long long w)
	{
		if(l>rh||r<lh);
		else if(l>=lh&&r<=rh)
		{
			mn.fr+=w;
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
			mn=mrg(p[0]->mn,p[1]->mn);
		}
	}
	pair<long long,long long> qr(long long lh,long long rh)
	{
		if(l>rh||r<lh)
		{
			return {inf,0};
		}
		else if(l>=lh&&r<=rh)
		{
			return mn;
		}
		else
		{
			blc();
			return mrg(p[0]->qr(lh,rh),p[1]->qr(lh,rh));
		}
	}
}
sg;

int main()
{
	long long i,ii,u,k,l,z=0;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld%lld",&k,&l);
		a[k]=l;
	}
	sg.bd(1,n);
	for(i=1;i<=n;i++)
	{
		sg.ud(1,i,-1);
		for(ii=0;ii<2;ii++)
		{
			u=!ii*2-1;
			for(;nn[ii]&&a[sk[ii][nn[ii]]]*u<=a[i]*u;nn[ii]--)
			{
				sg.ud(sk[ii][nn[ii]-1]+1,sk[ii][nn[ii]],abs(a[i]-a[sk[ii][nn[ii]]]));
			}
			nn[ii]++;
			sk[ii][nn[ii]]=i;
		}
		sg.ud(i,i,1);
		z+=sg.qr(1,i).sc;
	}
	printf("%lld\n",z);
}