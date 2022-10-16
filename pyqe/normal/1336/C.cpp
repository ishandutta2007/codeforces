#include <bits/stdc++.h>

using namespace std;

long long n,m,a[3069],ky[3069],dp[3069][3069],dv=998244353;

int main()
{
	long long i,j,z=0;
	string s;
	
	cin>>s;
	n=s.length();
	for(i=1;i<=n;i++)
	{
		a[i]=s[i-1]-'a';
	}
	cin>>s;
	m=s.length();
	for(i=1;i<=m;i++)
	{
		ky[i]=s[i-1]-'a';
	}
	for(i=0;i<=n;i++)
	{
		dp[0][i]=1;
	}
	for(i=1;i<=n;i++)
	{
		for(j=i;j<=n;j++)
		{
			dp[i][j]=(dp[i-1][j-1]*(j>m||a[i]==ky[j])+dp[i-1][j]*(j-i+1>m||a[i]==ky[j-i+1]))%dv;
		}
	}
	for(i=m;i<=n;i++)
	{
		z=(z+dp[i][i])%dv;
	}
	printf("%lld\n",z);
}