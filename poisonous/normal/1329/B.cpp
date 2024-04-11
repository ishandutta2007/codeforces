#include<bits/stdc++.h>
using namespace std;
long long dp[100];
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		memset(dp,0,sizeof(dp));
		dp[0]=1;
		int n,mod;
		cin>>n>>mod;
		int x=n,p=0;
		while(x)
		{
			p++;
			x/=2;
		}
		p--;
		for(int i=1;i<=p;i++)
		{
			for(int j=0;j<i;j++)
			{
				if(i==p)
					dp[i]=(dp[i]+dp[j]*(n-(1<<i)+1))%mod;
				else
					dp[i]=(dp[i]+dp[j]*(1<<(i)))%mod;
			}
			if(i==p)
				dp[i]=(dp[i]+(n-(1<<i)+1))%mod;
			else
				dp[i]=(dp[i]+(1<<(i)))%mod;
		}
		long long ans=0;
		for(int i=0;i<=p;i++)
			ans=(ans+dp[i])%mod;
		cout<<ans<<endl;
	}
		
}