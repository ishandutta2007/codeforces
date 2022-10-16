#include <bits/stdc++.h>

using namespace std;

long long a[2069],dp[2069];
bool vtd[2069];

long long chg(long long p)
{
	if(!vtd[p])
	{
		if(a[p]==-1)
		{
			dp[p]=1;
		}
		else
		{
			dp[p]=chg(a[p])+1;
		}
		vtd[p]=true;
	}
	return dp[p];
}

int main()
{
	long long n,i,k,b=0;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		a[i]=k;
	}
	for(i=1;i<=n;i++)
	{
		if(vtd[i])
		{
			continue;
		}
		k=chg(i);
		if(k>b)
		{
			b=k;
		}
	}
	printf("%lld\n",b);
}