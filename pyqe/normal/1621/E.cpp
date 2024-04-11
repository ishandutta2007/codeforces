#include <bits/stdc++.h>

using namespace std;

long long n,m,as[100069],wg[100069],pst[100069];
vector<long long> a[100069];

struct segtree
{
	long long l,r,mn,lz;
	segtree *p[2];
	
	void bd(long long lh,long long rh)
	{
		l=lh;
		r=rh;
		mn=n+1-r;
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
	inline void blc()
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
	long long t,rr,i,j,k,sz,p;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&m);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",as+i);
		}
		sort(as+1,as+n+1);
		sg.bd(1,n+1);
		for(i=1;i<=m;i++)
		{
			scanf("%lld",&sz);
			a[i].clear();
			wg[i]=0;
			for(j=0;j<sz;j++)
			{
				scanf("%lld",&k);
				a[i].push_back(k);
				wg[i]+=k;
			}
			pst[i]=lower_bound(as+1,as+n+1,(wg[i]-1)/sz+1)-as;
			sg.ud(1,pst[i],-1);
		}
		for(i=1;i<=m;i++)
		{
			sz=a[i].size();
			sg.ud(1,pst[i],1);
			for(j=0;j<sz;j++)
			{
				k=a[i][j];
				p=lower_bound(as+1,as+n+1,(wg[i]-k-1)/(sz-1)+1)-as;
				sg.ud(1,p,-1);
				printf("%lld",(long long)(sg.mn>=0));
				sg.ud(1,p,1);
			}
			sg.ud(1,pst[i],-1);
		}
		printf("\n");
	}
}