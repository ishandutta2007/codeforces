#include <bits/stdc++.h>

using namespace std;

long long n,a[200069],dp[200069][2],z=0;
bitset<200069> spc,kd,vtd;
vector<long long> al[200069];

void dfs(long long x)
{
	long long i,ii,sz=al[x].size(),l,mn;
	
	vtd[x]=1;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			a[l]=min(a[l],a[x]);
			dfs(l);
			for(ii=0;ii<2;ii++)
			{
				dp[x][ii]+=dp[l][ii];
			}
		}
	}
	dp[x][kd[x]]+=spc[x];
	mn=min(dp[x][0],dp[x][1]);
	z+=mn*2*a[x];
	for(ii=0;ii<2;ii++)
	{
		dp[x][ii]-=mn;
	}
}

int main()
{
	long long i,k,l;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld%lld%lld",a+i,&k,&l);
		spc[i]=k^l;
		kd[i]=k;
	}
	for(i=0;i<n-1;i++)
	{
		scanf("%lld%lld",&k,&l);
		al[k].push_back(l);
		al[l].push_back(k);
	}
	dfs(1);
	if(dp[1][0]||dp[1][1])
	{
		z=-1;
	}
	printf("%lld\n",z);
}