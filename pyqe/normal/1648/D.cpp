#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

const long long inf=1e18;
long long n,m,nn=1,a[3][500069],ps[3][500069],dp[500069][2],wg[500069],sk[500069];
vector<pair<long long,long long>> vl[500069];

struct segtree
{
	long long l,r,mx[2],lz[2];
	segtree *p[2];
	
	void bd(long long lh,long long rh)
	{
		long long ii,md=(lh+rh)/2;
		
		l=lh;
		r=rh;
		for(ii=0;ii<2;ii++)
		{
			mx[ii]=0;
			lz[ii]=0;
		}
		if(l<r)
		{
			for(ii=0;ii<2;ii++)
			{
				p[ii]=new segtree;
				p[ii]->bd(!ii?l:md+1,!ii?md:r);
			}
		}
	}
	inline void blc(long long xx)
	{
		long long ii;
		
		for(ii=0;ii<2;ii++)
		{
			p[ii]->mx[xx]+=lz[xx];
			p[ii]->lz[xx]+=lz[xx];
		}
		lz[xx]=0;
	}
	void ud(long long xx,long long lh,long long rh,long long w)
	{
		if(l>rh||r<lh);
		else if(l>=lh&&r<=rh)
		{
			mx[xx]+=w;
			lz[xx]+=w;
		}
		else
		{
			long long ii;
			
			blc(xx);
			for(ii=0;ii<2;ii++)
			{
				p[ii]->ud(xx,lh,rh,w);
			}
			mx[xx]=max(p[0]->mx[xx],p[1]->mx[xx]);
		}
	}
	long long qr(long long xx,long long lh,long long rh)
	{
		if(l>rh||r<lh)
		{
			return -inf;
		}
		else if(l>=lh&&r<=rh)
		{
			return mx[xx];
		}
		else
		{
			blc(xx);
			return max(p[0]->qr(xx,lh,rh),p[1]->qr(xx,lh,rh));
		}
	}
}
sg;

int main()
{
	long long i,j,ii,k,l,w,sz,z=-inf;
	
	scanf("%lld%lld",&n,&m);
	n+=2;
	for(i=0;i<3;i++)
	{
		for(j=1;j<=n-2;j++)
		{
			scanf("%lld",&a[i][j+i]);
		}
		for(j=1;j<=n;j++)
		{
			ps[i][j]=ps[i][j-1]+a[i][j];
		}
	}
	for(i=1;i<=m;i++)
	{
		scanf("%lld%lld%lld",&k,&l,&w);
		l++;
		vl[l].push_back({k,w});
	}
	dp[0][0]=0;
	dp[0][1]=-inf;
	sg.bd(0,n);
	sg.ud(1,0,0,-inf);
	sk[0]=-1;
	for(i=1;i<=n;i++)
	{
		dp[i][0]=-inf;
		dp[i][1]=-inf;
		wg[i]=ps[1][i]-ps[2][i];
		for(;nn&&wg[sk[nn]]<wg[i];nn--)
		{
			sg.ud(1,sk[nn-1]+1,sk[nn],-wg[sk[nn]]);
		}
		nn++;
		sk[nn]=i;
		sg.ud(1,sk[nn-1]+1,sk[nn],wg[i]);
		sz=vl[i].size();
		for(j=0;j<sz;j++)
		{
			k=vl[i][j].fr;
			w=vl[i][j].sc;
			for(ii=0;ii<2;ii++)
			{
				dp[i][ii]=max(dp[i][ii],sg.qr(ii,k+ii,i-1)+ps[1+ii][i]-w);
			}
			dp[i][1]=max(dp[i][1],ps[0][i-1]+a[1][i]-w);
			dp[i][1]=max(dp[i][1],dp[k][0]+ps[2][i]-ps[1][k]+wg[*lower_bound(sk+1,sk+nn+1,k)]-w);
			dp[i][1]=max(dp[i][1],dp[k][1]+ps[2][i]-ps[2][k]-w);
		}
		z=max(z,dp[i][1]+ps[2][n]-ps[2][i]);
		sg.ud(0,i,i,max(dp[i][0],ps[0][i])-ps[1][i]);
		sg.ud(1,i,i,max(dp[i][0],ps[0][i-1]+a[1][i])-ps[1][i]);
	}
	printf("%lld\n",z);
}