#include <bits/stdc++.h>

using namespace std;

long long n,dp[200069];
bitset<200069> a;

int main()
{
	long long t,rr,i,ii,k,mx,d;
	string s;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		cin>>s;
		for(i=1;i<n;i++)
		{
			a[i]=s[i-1]=='<';
		}
		for(ii=0;ii<2;ii++)
		{
			dp[n]=0;
			for(i=n-1;i;i--)
			{
				dp[i]=dp[i+1]+1;
				if(a[i]==ii)
				{
					dp[i]=0;
				}
			}
			mx=0;
			d=1;
			for(i=1;i<=n;i++)
			{
				k=d+dp[i];
				mx=max(mx,k);
				if(!dp[i])
				{
					d=mx+1;
				}
				if(!ii)
				{
					k=n+1-k;
				}
				printf("%lld%c",k," \n"[i==n]);
			}
		}
	}
}