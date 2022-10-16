#include <bits/stdc++.h>

using namespace std;

const long long ma=1e5,inf=1e18;
long long n,a[2][100069],dp[100069],dsu[100069],cc[100069];
vector<long long> al[100069],vl[100069];
bitset<100069> vtd;

long long f(long long x,long long w)
{
	return a[1][x]*w+dp[x];
}

struct lichao
{
	long long l,r,mn;
	lichao *p[2];
	
	void bd(long long lh,long long rh)
	{
		l=lh;
		r=rh;
		mn=0;
		p[0]=0;
	}
	void blc()
	{
		if(!p[0])
		{
			long long ii,md=(l+r+ma*2)/2-ma;
			
			for(ii=0;ii<2;ii++)
			{
				p[ii]=new lichao;
				p[ii]->bd(!ii?l:md+1,!ii?md:r);
			}
		}
	}
	void ins(long long x)
	{
		long long ii,md=(l+r+ma*2)/2-ma;
		
		if(f(x,md)<f(mn,md))
		{
			swap(mn,x);
		}
		blc();
		for(ii=0;ii<2;ii++)
		{
			if(f(x,l)<f(mn,l))
			{
				p[ii]->ins(x);
			}
			swap(l,r);
		}
	}
	long long qr(long long x)
	{
		if(l>x||r<x)
		{
			return inf;
		}
		else
		{
			long long ii,z=f(mn,x);
			
			if(l<r)
			{
				blc();
				for(ii=0;ii<2;ii++)
				{
					z=min(z,p[ii]->qr(x));
				}
			}
			return z;
		}
	}
}
lch[100069];

long long fd(long long x)
{
	if(dsu[x]!=x)
	{
		dsu[x]=fd(dsu[x]);
	}
	return dsu[x];
}

void jo(long long x,long long y)
{
	long long i,k,sz;
	
	x=fd(x);
	y=fd(y);
	if(cc[x]<cc[y])
	{
		swap(x,y);
	}
	sz=vl[y].size();
	for(i=0;i<sz;i++)
	{
		k=vl[y][i];
		lch[x].ins(k);
		vl[x].push_back(k);
	}
	dsu[y]=x;
	cc[x]+=cc[y];
}

void dfs(long long x)
{
	long long i,sz=al[x].size(),l;
	bool lf=1;
	
	vtd[x]=1;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			dfs(l);
			jo(x,l);
			lf=0;
		}
	}
	if(!lf)
	{
		dp[x]=lch[fd(x)].qr(a[0][x]);
	}
	lch[fd(x)].ins(x);
	vl[fd(x)].push_back(x);
	cc[fd(x)]++;
}

int main()
{
	long long n,i,ii,k,l;
	
	scanf("%lld",&n);
	for(ii=0;ii<2;ii++)
	{
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&a[ii][i]);
		}
	}
	for(i=0;i<n-1;i++)
	{
		scanf("%lld%lld",&k,&l);
		al[k].push_back(l);
		al[l].push_back(k);
	}
	dp[0]=inf;
	for(i=1;i<=n;i++)
	{
		lch[i].bd(-ma,ma);
		dsu[i]=i;
	}
	dfs(1);
	for(i=1;i<=n;i++)
	{
		printf("%lld%c",dp[i]," \n"[i==n]);
	}
}