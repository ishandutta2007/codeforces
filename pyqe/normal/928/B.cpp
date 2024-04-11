#include <bits/stdc++.h>

using namespace std;

long long n,d,dp[100069];

int main()
{
	long long i,k,l;
	
	scanf("%lld%lld",&n,&d);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		if(!k)
		{
			l=0;
		}
		else
		{
			l=min(k+d,n);
		}
		dp[i]=dp[k]+min(i+d,n)-max(i-d-1,l);
		printf("%lld%c",dp[i]," \n"[i==n]);
	}
}