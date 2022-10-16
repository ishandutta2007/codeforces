#include <bits/stdc++.h>

using namespace std;

long long n,m,d,ma=2e7,dp[20000069];

long long val(long long x)
{
	long long k=d/x+m;
	
	if(k%n)
	{
		return 0;
	}
	return dp[k/n];
}

int main()
{
	long long t,rr,i,j,z;
	
	for(i=1;i<=ma;i++)
	{
		dp[i]=1;
	}
	for(i=2;i<=ma;i++)
	{
		if(dp[i]==1)
		{
			for(j=i;j<=ma;j+=i)
			{
				dp[j]*=2;
			}
		}
	}
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld",&n,&m,&d);
		z=0;
		for(i=1;i*i<=d;i++)
		{
			if(d%i==0)
			{
				z+=val(i);
				if(d/i!=i)
				{
					z+=val(d/i);
				}
			}
		}
		printf("%lld\n",z);
	}
}