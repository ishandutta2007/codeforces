#include <bits/stdc++.h>

using namespace std;

long long n,w1,w2,dp[200069][2];
bitset<200069> a;

int main()
{
	long long t,rr,i,ii;
	string s;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld",&n,&w1,&w2);
		cin>>s;
		for(i=1;i<=n;i++)
		{
			a[i]=s[i-1]-'0';
		}
		a[n+1]=0;
		dp[0][0]=w2;
		dp[0][1]=1e18;
		for(i=1;i<=n;i++)
		{
			for(ii=0;ii<2;ii++)
			{
				if(ii||(!a[i]&&!a[i+1]))
				{
					dp[i][ii]=min(dp[i-1][ii]+w1+w2*(ii+1),dp[i-1][!ii]+w1*2+w2*(ii+1));
				}
				else
				{
					dp[i][ii]=1e18;
				}
			}
		}
		printf("%lld\n",dp[n][0]);
	}
}