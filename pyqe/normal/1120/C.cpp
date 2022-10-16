#include <bits/stdc++.h>

using namespace std;

long long n,d,d2,a[5069],faf[5069],pr[5069],dp[5069];

int main()
{
	long long i,j,r,c,mx;
	string s;
	
	scanf("%lld%lld%lld",&n,&d,&d2);
	cin>>s;
	for(i=1;i<=n;i++)
	{
		a[i]=s[i-1]-'a';
	}
	for(i=n;i+1;i--)
	{
		faf[0]=-1;
		for(j=1;j<=n-i;j++)
		{
			for(r=faf[j-1];r+1&&a[i+j]!=a[i+r+1];r=faf[r]);
			faf[j]=r+1;
		}
		mx=0;
		c=0;
		for(j=1;j<=i;j++)
		{
			for(;c+1&&(c+1>n-i||a[j]!=a[i+c+1]);c=faf[c]);
			c++;
			mx=max(mx,c);
		}
		for(j=0;j<=mx;j++)
		{
			pr[i+j]=i;
		}
	}
	for(i=1;i<=n;i++)
	{
		dp[i]=dp[i-1]+d;
		for(j=pr[i];j<i;j++)
		{
			dp[i]=min(dp[i],dp[j]+d2);
		}
	}
	printf("%lld\n",dp[n]);
}