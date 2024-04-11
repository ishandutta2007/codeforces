#include <bits/stdc++.h>

using namespace std;

long long n[2],dp[400069],dv=1e9+7;

int main()
{
	long long i,j,w,z=0;
	
	scanf("%lld%lld",n,n+1);
	dp[0]=1;
	for(i=1;i*(i+1)/2<=n[0]+n[1];i++)
	{
		w=i*(i+1)/2;
		for(j=min(n[0],w);j>=i;j--)
		{
			dp[j]=(dp[j]+dp[j-i])%dv;
		}
		for(j=max(w-n[1]-i,0ll);j<w-n[1];j++)
		{
			dp[j]=0;
		}
	}
	for(i=0;i<=n[0]+n[1];i++)
	{
		z=(z+dp[i])%dv;
	}
	printf("%lld\n",z);
}