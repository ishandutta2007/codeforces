// Author: Little09
// Problem: E. Phoenix and Computers
// Contest: Codeforces Global Round 14
// URL: https://codeforces.com/contest/1515/problem/E
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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
#define endl "\n"
#define lowbit(x) (x&(-x))

const ll inf=1000000000000000000; 
//const ll inf=1000000000;
//const ll mod=998244353;
//const ll mod=1000000007;

const int N=505;
int n,m; 
ll p[N],dp[N][N];
ll mod;


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
ll jc[N+5],inv[N+5];
inline ll C(ll x,ll y)
{
	if (y>x) return 0;
	return jc[x]*inv[y]%mod*inv[x-y]%mod;
}
void init()
{
	jc[0]=1;
	for (int i=1;i<=N;i++) jc[i]=jc[i-1]*i%mod;
	inv[N]=ksm(jc[N],mod-2);
	for (int i=N-1;i>=0;i--) inv[i]=inv[i+1]*(i+1)%mod;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> mod;
	init();
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=i;j++)
		{
			p[i]=(p[i]+C(i-1,j-1))%mod;
		}
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=i;j++)
		{
			for (int k=1;k<=j;k++)
			{
				if (i-k-1<0) dp[i][j]=(dp[i][j]+p[k])%mod;
				else dp[i][j]=(dp[i][j]+dp[i-k-1][j-k]*p[k]%mod*C(j,k)%mod)%mod;
			}
		}
	}
	ll ans=0;
	for (int i=1;i<=n;i++) ans=(ans+dp[n][i])%mod;
	cout << ans << endl;
	return 0;
}