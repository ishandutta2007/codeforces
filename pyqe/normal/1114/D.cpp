#include <bits/stdc++.h>

using namespace std;

long long ln,n=0,a[5069],dp[5069];

int main()
{
	long long i,j,k,l=-1;
	
	scanf("%lld",&ln);
	for(i=0;i<ln;i++)
	{
		scanf("%lld",&k);
		if(k!=l)
		{
			n++;
			a[n]=k;
		}
		l=k;
	}
	for(i=1;i<=n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			if(a[i]==a[j])
			{
				dp[j]=dp[j+1]+1;
			}
		}
		for(j=n-1;j;j--)
		{
			dp[j]=max(dp[j],dp[j+1]);
		}
	}
	printf("%lld\n",n-1-dp[1]);
}