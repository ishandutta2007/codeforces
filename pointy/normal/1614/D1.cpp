// By: Little09
// Problem: D1. Divan and Kostomuksha (easy version)
// Contest: Codeforces - Codeforces Round #757 (Div. 2)
// URL: https://codeforces.com/contest/1614/problem/D1
// Memory Limit: 1024 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N=1e5+5,M=5e6;

ll a[M+5],b[M+5],dp[M+5];
const ll inf=1e18;
int n;

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
	n=read();
	for (int i=1;i<=n;i++) a[read()]++;
	for (int i=1;i<=M;i++)
	{
		for (int j=1;i*j<=M;j++)
		{
			b[i]+=a[i*j];
		}
	}
	ll ans=0;
	for (ll i=2;i<=M;i++) dp[i]=-inf;
	for (ll i=1;i<=M;i++)
	{
		dp[i]=dp[i]+b[i]*i;
		for (int j=1;i*j<=M;j++)
		{
			dp[i*j]=max(dp[i*j],dp[i]-b[i*j]*i);
		}
		ans=max(ans,dp[i]);
	}
	cout << ans;
	return 0;
}

//dp[i]=dp[j]+b[i]*(i-j)
//when j|i