// Author: Little09
// Problem: D. Kavi on Pairing Duty
// Contest: Codeforces Round #722 (Div. 2)
// URL: https://codeforces.com/contest/1529/problem/D
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mem(x) memset(x,0,sizeof(x))
#define printYes puts("Yes")
#define printYES puts("YES")
#define printNo puts("No")
#define printNO puts("NO")
#define endl "\n"
#define lowbit(x) (x&(-x))

const ll inf=1000000000000000000; 
const ll mod=998244353;
//const ll mod=1000000007;

const int N=1000005;
int n,m; 
ll dp[N];

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
	dp[0]=1,dp[1]=2;
	for (int i=1;i<=n;i++)
	{
		for (int j=2;i*j<=n;j++)
		{
			dp[i*j]++;
		}
	}
	for (int i=2;i<=n;i++)
	{
		dp[i]=(2*dp[i-1]+dp[i])%mod;
	}
	cout << (dp[n]-dp[n-1]+mod)%mod;
	return 0;
}