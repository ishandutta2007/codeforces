// By: Little09
// Problem: CF1558B Up the Strip
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1558B
// Memory Limit: 125 MB
// Time Limit: 6000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll mod;
const int N=4e6+5;
int n;
ll dp[N],sum,s[N];

inline int read()
{
    int F=1,ANS=0;
	char C=getchar();
    while (C<'0'||C>'9')
	{
		if (C=='-') F=-1;
		C=getchar();
	}
    while (C>='0'&&C<='9')
	{
		ANS=ANS*10+C-'0';
		C=getchar();
	}
    return F*ANS;
}
int main()
{
	n=read(),mod=read();
	dp[1]=1,sum=0;
	for (int i=1;i<=n;i++)
	{
		dp[i]=(dp[i]+sum)%mod;
		s[i]=(s[i-1]+s[i])%mod;
		dp[i]=(dp[i]+s[i])%mod;
		sum=(sum+dp[i])%mod;
		for (int j=1;j<=n/i;j++)
		{
			s[i*j]=(s[i*j]+dp[i])%mod;
			if (i*j+j<=n) s[i*j+j]=(s[i*j+j]-dp[i]+mod)%mod;
		}
	}
	cout << dp[n];
	return 0;
}