#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

const long long ma=1e9;
long long n,m,as[600069],pr[300069],sq[300069],zs=0;
vector<pair<long long,long long>> vl[300069];
bitset<300069> spc;

struct segtree
{
	long long l,r;
	pair<long long,long long> mx,lz;
	segtree *p[2];
	
	void bd(long long lh,long long rh)
	{
		l=lh;
		r=rh;
		mx={0,0};
		lz={0,0};
		p[0]=0;
	}
	void blc()
	{
		long long ii,md=(l+r)/2;
		
		if(!p[0])
		{
			for(ii=0;ii<2;ii++)
			{
				p[ii]=new segtree;
				p[ii]->bd(!ii?l:md+1,!ii?md:r);
			}
		}
		for(ii=0;ii<2;ii++)
		{
			p[ii]->mx=max(p[ii]->mx,lz);
			p[ii]->lz=max(p[ii]->lz,lz);
		}
		lz={0,0};
	}
	void ud(long long lh,long long rh,pair<long long,long long> w)
	{
		if(l>rh||r<lh);
		else if(l>=lh&&r<=rh)
		{
			mx=max(mx,w);
			lz=max(lz,w);
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
	pair<long long,long long> qr(long long lh,long long rh)
	{
		if(l>rh||r<lh)
		{
			return {0,0};
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
	long long i,j,k,l,sz,p,e;
	pair<long long,long long> mxe,z;
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=m;i++)
	{
		scanf("%lld%lld%lld",&p,&k,&l);
		l++;
		as[i*2-1]=k;
		as[i*2]=l;
		vl[p].push_back({k,l});
	}
	sort(as+1,as+m*2+1);
	sg.bd(1,m*2);
	for(i=1;i<=n;i++)
	{
		mxe={0,0};
		sz=vl[i].size();
		for(j=0;j<sz;j++)
		{
			vl[i][j].fr=lower_bound(as+1,as+m*2+1,vl[i][j].fr)-as;
			vl[i][j].sc=lower_bound(as+1,as+m*2+1,vl[i][j].sc)-as;
			k=vl[i][j].fr;
			l=vl[i][j].sc;
			mxe=max(mxe,sg.qr(k,l-1));
		}
		for(j=0;j<sz;j++)
		{
			k=vl[i][j].fr;
			l=vl[i][j].sc;
			sg.ud(k,l-1,{mxe.fr+1,i});
		}
		pr[i]=mxe.sc;
		z=max(z,{mxe.fr+1,i});
	}
	e=z.sc;
	for(;e;e=pr[e])
	{
		spc[e]=1;
	}
	for(i=1;i<=n;i++)
	{
		if(!spc[i])
		{
			zs++;
			sq[zs]=i;
		}
	}
	printf("%lld\n",zs);
	for(i=1;i<=zs;i++)
	{
		printf("%lld%c",sq[i]," \n"[i==zs]);
	}
}