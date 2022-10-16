#include <bits/stdc++.h>

using namespace std;

long long n,a[100069],dp[100069][2];
vector<long long> v[100069][2];

int main()
{
	long long i,j,ii,iii,sz,mn=1e18;
	string s;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	for(i=1;i<=n;i++)
	{
		cin>>s;
		sz=s.length();
		for(j=0;j<sz;j++)
		{
			v[i][0].push_back(s[j]-'a');
		}
		for(j=sz-1;j+1;j--)
		{
			v[i][1].push_back(v[i][0][j]);
		}
		for(ii=0;ii<2;ii++)
		{
			dp[i][ii]=1e18;
			for(iii=0;iii<2;iii++)
			{
				if(v[i][ii]>=v[i-1][iii])
				{
					dp[i][ii]=min(dp[i][ii],dp[i-1][iii]+a[i]*ii);
				}
			}
			if(i==n)
			{
				mn=min(mn,dp[i][ii]);
			}
		}
	}
	if(mn==1000000000000000000)
	{
		mn=-1;
	}
	printf("%lld\n",mn);
}