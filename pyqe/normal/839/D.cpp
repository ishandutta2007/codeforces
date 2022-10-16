#include <bits/stdc++.h>

using namespace std;

long long n,ma=1e6,fq[1000069],dp[1000069],pwk,dv=1e9+7;

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
	long long i,j,k,z=0;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		fq[k]++;
	}
	for(i=ma;i-1;i--)
	{
		k=0;
		for(j=i;j<=ma;j+=i)
		{
			k+=fq[j];
			dp[i]=(dp[i]+dv-dp[j])%dv;
		}
		dp[i]=(dp[i]+pw(2,k-1)*k)%dv;
		z=(z+dp[i]*i)%dv;
	}
	printf("%lld\n",z);
}