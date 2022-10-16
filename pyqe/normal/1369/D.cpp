#include <bits/stdc++.h>

using namespace std;

long long n,ma=2e6,dp[2000069],dv=1e9+7;

int main()
{
	long long t,rr,i,ii;
	
	for(i=2;i<=ma;i++)
	{
		dp[i]=(dp[i-1]+dp[i-2]*2+4*(i%3==0))%dv;
	}
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		printf("%lld\n",dp[n]);
	}
}