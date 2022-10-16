#include <bits/stdc++.h>

using namespace std;

long long n,dp[300069],z;
vector<long long> al[300069];
bitset<300069> vtd;

void dfs(long long x)
{
	long long i,sz=al[x].size(),l,cd=0,mx=0,mx2=0,k;
	
	vtd[x]=1;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			dfs(l);
			if(dp[l]>=mx)
			{
				mx2=mx;
				mx=dp[l];
			}
			else if(dp[l]>mx2)
			{
				mx2=dp[l];
			}
			cd++;
		}
	}
	dp[x]=mx+max(cd-1,0ll)+1;
	k=mx+mx2+max(cd-2,0ll)+1;
	if(x>1)
	{
		k++;
	}
	z=max(z,k);
}

int main()
{
	long long t,rr,i,k,l;
	
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
		vtd.reset();
		z=0;
		dfs(1);
		printf("%lld\n",z);
	}
}