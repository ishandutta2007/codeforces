#include<bits/stdc++.h>
using namespace std;
const int mod=1000000007;
long long ksm(int i,int j)
{
	long long k=1,l=i;
	while(j)
	{
		if(j&1)
			k=k*l%mod;
		l=l*l%mod;
		j=j>>1;
	}
	return k;
}
long long dp[110];
long long ks[110];
int main()
{
	long long n,ans=1;
	int k;
	cin>>n>>k;
	for(int i=1;i<=100;i++)
		ks[i]=ksm(i,mod-2);
	for(long long z=2;z*z<=n;z++)
	{
		if(n%z==0)
		{
			int t=0;
			while(n%z==0)
			{
				n/=z;
				t++;
			}
			for(int i=0;i<t;i++)
				dp[i]=0;
			dp[t]=1;
			for(int i=1;i<=k;i++)
			{
				for(int j=0;j<=t;j++)
				{
					for(int o=0;o<j;o++)
						dp[o]=(dp[o]+dp[j]*ks[j+1])%mod;
					dp[j]=dp[j]*ks[j+1]%mod;
				}
			}
			long long nn=1,an=0;
			for(int i=0;i<=t;i++)
			{
				an=(an+nn*dp[i])%mod;
				nn=nn*z%mod;
			}
			ans=(ans*an)%mod;
		}
	}
	if(n>1)
	{
		long long z=n;
		int t=1;
		for(int i=0;i<t;i++)
				dp[i]=0;
		dp[t]=1;
		for(int i=1;i<=k;i++)
		{
			for(int j=0;j<=t;j++)
			{
				for(int o=0;o<j;o++)
					dp[o]=(dp[o]+dp[j]*ks[j+1])%mod;
				dp[j]=dp[j]*ks[j+1]%mod;
			}
		}
		long long nn=1,an=0;
		for(int i=0;i<=t;i++)
		{
			an=(an+nn*dp[i])%mod;
			nn=nn*z%mod;
		}
		ans=(ans*an)%mod;
	}
	cout<<ans;
}