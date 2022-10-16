#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,d,ub=1e9,nr[100069],pr[100069],dh[100069],inf=1e18;
vector<pair<long long,long long>> al[100069];
bitset<100069> vtd;
pair<long long,long long> mxe;

void dfs(long long x)
{
	long long i,sz=al[x].size(),l,w;
	
	vtd[x]=1;
	for(i=0;i<sz;i++)
	{
		l=al[x][i].fr;
		w=al[x][i].sc;
		if(!vtd[l])
		{
			nr[l]=nr[x]+w;
			pr[l]=x;
			dh[l]=dh[x]+1;
			dfs(l);
		}
	}
	mxe=max(mxe,{nr[x],x});
}

void dfs2(long long x)
{
	long long i,sz=al[x].size(),l,w;
	
	vtd[x]=1;
	for(i=0;i<sz;i++)
	{
		l=al[x][i].fr;
		w=al[x][i].sc;
		if(!vtd[l]&&l!=pr[x])
		{
			nr[l]=nr[x]+w;
			dfs2(l);
		}
	}
}

int main()
{
	long long i,ii,k,l,w,lh,rh,md,zz,e,p;
	
	scanf("%lld%lld",&n,&d);
	for(i=0;i<n-1;i++)
	{
		scanf("%lld%lld%lld",&k,&l,&w);
		al[k].push_back({l,w});
		al[l].push_back({k,w});
	}
	for(lh=0,rh=ub;lh<=rh;)
	{
		md=(lh+rh)/2;
		p=1;
		for(ii=0;ii<2;ii++)
		{
			vtd.reset();
			nr[p]=0;
			pr[p]=0;
			dh[p]=0;
			mxe={-inf,-1};
			dfs(p);
			e=mxe.sc;
			for(p=e;p&&nr[e]-nr[pr[p]]<=md;p=pr[p]);
			if(!p)
			{
				ii=-1;
				break;
			}
		}
		if(ii!=-1&&dh[p]<d)
		{
			vtd.reset();
			for(;p;p=pr[p])
			{
				nr[p]=0;
				dfs2(p);
			}
			for(i=1;i<=n;i++)
			{
				if(nr[i]>md)
				{
					i=-1;
					break;
				}
			}
			if(i!=-1)
			{
				ii=-1;
			}
		}
		if(ii==-1)
		{
			zz=md;
			rh=md-1;
		}
		else
		{
			lh=md+1;
		}
	}
	printf("%lld\n",zz);
}