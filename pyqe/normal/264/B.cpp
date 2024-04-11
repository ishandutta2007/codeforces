#include <bits/stdc++.h>

using namespace std;

long long n,dp[100069];
vector<long long> fz[100069];

int main()
{
	long long i,j,k,sz,mx,z=0;
	
	for(i=2;i<=100000;i++)
	{
		if(fz[i].empty())
		{
			for(j=i;j<=100000;j+=i)
			{
				fz[j].push_back(i);
			}
		}
	}
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		sz=fz[k].size();
		mx=0;
		for(j=0;j<sz;j++)
		{
			mx=max(mx,dp[fz[k][j]]);
		}
		for(j=0;j<sz;j++)
		{
			dp[fz[k][j]]=mx+1;
		}
		z=max(z,mx+1);
	}
	printf("%lld\n",z);
}