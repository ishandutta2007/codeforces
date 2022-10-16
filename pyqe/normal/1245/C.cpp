#include <bits/stdc++.h>

using namespace std;

long long n,a[100069],dp[100069],dv=1e9+7;

int main()
{
	long long i;
	string s;
	
	cin>>s;
	n=s.length();
	for(i=1;i<=n;i++)
	{
		a[i]=s[i-1]-'a';
	}
	dp[0]=1;
	for(i=1;i<=n;i++)
	{
		dp[i]=dp[i-1];
		if((a[i]==13&&a[i-1]==13)||(a[i]==20&&a[i-1]==20))
		{
			dp[i]=(dp[i]+dp[i-2])%dv;
		}
		if(a[i]==12||a[i]==22)
		{
			printf("0\n");
			return 0;
		}
	}
	printf("%lld\n",dp[n]);
}