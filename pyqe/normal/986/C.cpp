#include <bits/stdc++.h>

using namespace std;

long long n,d,a[(1ll<<22)+1],dp[2][1ll<<22],dsu[(1ll<<22)+1];

long long fd(long long x)
{
	if(dsu[x]!=x)
	{
		dsu[x]=fd(dsu[x]);
	}
	return dsu[x];
}

int main()
{
	long long i,mk,mk2,z=0;
	
	scanf("%lld%lld",&d,&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		dsu[i]=i;
	}
	for(i=1;i<=n;i++)
	{
		dp[0][(1ll<<d)-1^a[i]]=i;
		dp[1][a[i]]=i;
	}
	for(i=0;i<d;i++)
	{
		for(mk=0;mk<1ll<<d;mk++)
		{
			if(!(mk>>i&1))
			{
				dp[0][mk]=max(dp[0][mk],dp[0][mk|1ll<<i]);
			}
		}
	}
	for(i=0;i<d;i++)
	{
		for(mk=(1ll<<d)-1;mk+1;mk--)
		{
			if(mk>>i&1)
			{
				mk2=mk^1ll<<i;
				if(dp[0][mk])
				{
					if(dp[1][mk])
					{
						dsu[fd(dp[1][mk])]=fd(dp[0][mk]);
					}
					if(dp[1][mk2])
					{
						dsu[fd(dp[1][mk2])]=fd(dp[0][mk]);
					}
				}
				dp[1][mk]=max(dp[1][mk],dp[1][mk2]);
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		z+=fd(i)==i;
	}
	printf("%lld\n",z);
}