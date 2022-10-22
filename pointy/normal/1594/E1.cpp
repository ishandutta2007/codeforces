// Author: Little09
// Problem: E1. Rubik's Cube Coloring (easy version)
// Contest: Codeforces Round #747 (Div. 2)
// URL: https://codeforces.com/contest/1594/problem/E1
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mem(x) memset(x,0,sizeof(x))
#define printYes cout << "Yes" << endl
#define printYES cout << "YES" << endl
#define printNo cout << "No" << endl
#define printNO cout << "NO" << endl
#define lowbit(x) (x&(-x))

const ll inf=1000000000000000000; 
//const ll inf=1000000000;
//const ll mod=998244353;
const ll mod=1000000007;

const int N=500005;
int n,m; 
ll dp[N];
ll ksm(ll x,ll y)
{
	ll res=1;
	while (y)
	{
		if (y&1) res=res*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return res;
}

void work()
{
	cin >> n;
	dp[1]=6;
	ll tmp=ksm(9,mod-2);
	for (int i=2;i<=n;i++)
	{
		dp[i]=24*dp[i-1]%mod*dp[i-1]%mod*tmp%mod;
	}
	cout << dp[n] << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int T=1;
	while (T--) work();
	return 0;
}