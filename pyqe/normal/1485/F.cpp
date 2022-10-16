#include <bits/stdc++.h>

using namespace std;

long long n,dp[200069],dv=1e9+7;
map<long long,long long> ls;

int main()
{
	long long t,rr,i,k,sm;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		ls.clear();
		dp[0]=1;
		ls[0]=1;
		sm=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&k);
			dp[i]=(dp[i-1]*2+dv-dp[ls[sm]-1])%dv;
			ls[sm]=i;
			sm+=k;
		}
		printf("%lld\n",dp[n]);
	}
}