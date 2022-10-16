#include <bits/stdc++.h>

using namespace std;

long long n,nn,cr,dp[200069],pr[200069],vl[200069];
vector<long long> al[200069];
bitset<200069> vtd;

void dfs(long long x)
{
	long long i,sz=al[x].size(),l;
	bool lf=1;
	
	vtd[x]=1;
	dp[x]=0;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			pr[l]=x;
			dfs(l);
			dp[x]=max(dp[x],dp[l]-1);
			lf=0;
		}
	}
	if(lf)
	{
		dp[x]=cr-1;
	}
	if(!dp[x])
	{
		nn++;
		vl[nn]=x;
	}
}

int main()
{
	long long t,rr,i,k,l,lh,rh,md,zz,c;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			al[i].clear();
		}
		for(i=0;i<n-1;i++)
		{
			scanf("%lld%lld",&k,&l);
			al[k].push_back(l);
			al[l].push_back(k);
		}
		for(lh=1,rh=n-1;lh<=rh;)
		{
			md=(lh+rh)/2;
			for(i=1;i<=n;i++)
			{
				vtd[i]=0;
			}
			nn=0;
			cr=md;
			dfs(1);
			c=0;
			for(i=1;i<=nn;i++)
			{
				c+=(long long)(vl[i]!=1)+(pr[vl[i]]>1);
			}
			if(c<=1)
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
}