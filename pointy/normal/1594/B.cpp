// Author: Little09
// Problem: B. Special Numbers
// Contest: Codeforces Round #747 (Div. 2)
// URL: https://codeforces.com/contest/1594/problem/B
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
ll n,m; 
ll a[N];


void work()
{
	cin >> n >> m;
	int cnt=0;
	while (m)
	{
		a[++cnt]=m%2;
		m/=2;
	}
	ll bas=1,res=0;
	for (int i=1;i<=cnt;i++) res=(res+bas*a[i])%mod,bas=bas*n%mod;
	cout << res << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin >> T;
	while (T--) work();
	return 0;
}