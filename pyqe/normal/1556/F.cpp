#include <bits/stdc++.h>

using namespace std;

const long long dv=1e9+7;
long long n,a[14],am[14][14],pc[1ll<<14][14],dp[1ll<<14],pwk;

long long pw(long long x,long long y)
{
	if(!y)
	{
		return 1;
	}
	pwk=pw(x,y/2);
	pwk=pwk*pwk%dv;
	if(y%2)
	{
		pwk=pwk*x%dv;
	}
	return pwk;
}

int main()
{
	long long i,j,mk,mk2,sm,z=0;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",a+i);
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			am[i][j]=a[i]*pw(a[i]+a[j],dv-2)%dv;
		}
	}
	for(mk=0;mk<1ll<<n;mk++)
	{
		for(i=0;i<n;i++)
		{
			pc[mk][i]=1;
			for(j=0;j<n;j++)
			{
				if(mk>>j&1)
				{
					pc[mk][i]=pc[mk][i]*am[j][i]%dv;
				}
			}
		}
	}
	for(mk=1;mk<1ll<<n;mk++)
	{
		dp[mk]=1;
		for(mk2=mk-1&mk;mk2;mk2=mk2-1&mk)
		{
			sm=dp[mk2];
			for(i=0;i<n;i++)
			{
				if((mk>>i&1)&&!(mk2>>i&1))
				{
					sm=sm*pc[mk2][i]%dv;
				}
			}
			dp[mk]=(dp[mk]+dv-sm)%dv;
		}
		sm=dp[mk];
		for(i=0;i<n;i++)
		{
			if(!(mk>>i&1))
			{
				sm=sm*pc[mk][i]%dv;
			}
		}
		z=(z+sm*__builtin_popcountll(mk))%dv;
	}
	printf("%lld\n",z);
}