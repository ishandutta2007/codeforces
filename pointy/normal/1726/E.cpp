// Author: Little09
// Problem: E. Almost Perfect
// Contest: Codeforces Round #819 (Div. 1 + Div. 2) and Grimoire of Code Annual Contest 2022
// URL: https://codeforces.com/contest/1726/problem/E
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
#define lowbit(x) (x&(-x))

const ll inf=1000000000000000000; 
//const ll inf=1000000000;
const ll mod=998244353;
//const ll mod=1000000007;

const int N=500005;
int n,m; 
ll dp[N],p[N];

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

void work()
{
	cin >> n;
	if (n==1) cout << 1 << endl;
	else if (n==2) cout << 2 << endl;
	else 
	{
		ll ans=0;
		for (int k=0;k<=n/4;k++)
		{
			ans=(ans+dp[n-k*4]*C(n-k*2,k*2)%mod*p[k]%mod*ksm(2,k)%mod)%mod;
		}
		cout << ans << endl;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	init();
	dp[0]=1,dp[1]=1,dp[2]=2;
	p[0]=1,p[1]=1;
	for (int i=2;i<N;i++) p[i]=p[i-1]*(i*2-1)%mod;
	for (int i=3;i<N;i++) 
	{
		dp[i]=(dp[i-1]+dp[i-2]*(i-1)%mod)%mod;
	}
	int T;
	cin >> T;
	while (T--) work();
	return 0;
}