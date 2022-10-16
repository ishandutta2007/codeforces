#include <bits/stdc++.h>

using namespace std;

long long n;
bitset<2069> dp;

void ad(long long x)
{
	long long i;
	
	for(i=n;i>=x;i--)
	{
		dp[i]=dp[i]|dp[i-x];
	}
}

int main()
{
	long long t,rr,i,k,mx,ls;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			dp[i]=0;
		}
		dp[0]=1;
		mx=0;
		ls=0;
		for(i=1;i<=n*2;i++)
		{
			scanf("%lld",&k);
			if(k>mx)
			{
				if(ls)
				{
					ad(i-ls);
				}
				mx=k;
				ls=i;
			}
		}
		ad(n*2+1-ls);
		if(dp[n])
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}