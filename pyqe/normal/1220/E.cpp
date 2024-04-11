#include <bits/stdc++.h>

using namespace std;

long long n,m,st,a[200069],dg[200069],dp[200069];
vector<long long> al[200069];
queue<long long> q;
bitset<200069> vtd;

int main()
{
	long long i,k,l,sz,z=0,mx=0;
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		z+=a[i];
	}
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld",&k,&l);
		al[k].push_back(l);
		al[l].push_back(k);
		dg[k]++;
		dg[l]++;
	}
	scanf("%lld",&st);
	for(i=1;i<=n;i++)
	{
		if(i!=st&&dg[i]==1)
		{
			q.push(i);
		}
	}
	for(;!q.empty();)
	{
		k=q.front();
		q.pop();
		vtd[k]=1;
		z-=a[k];
		sz=al[k].size();
		for(i=0;i<sz;i++)
		{
			l=al[k][i];
			if(!vtd[l])
			{
				dp[l]=max(dp[l],dp[k]+a[k]);
				mx=max(mx,dp[l]);
				dg[l]--;
				if(l!=st&&dg[l]==1)
				{
					q.push(l);
				}
			}
		}
	}
	printf("%lld\n",z+mx);
}