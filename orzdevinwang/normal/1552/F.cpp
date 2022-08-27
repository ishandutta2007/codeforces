#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
using namespace std;
const int N = 2e5 + 7, mod = 998244353;
int n, x[N], y[N], s[N], dp[N], pre[N], ns;
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0); 
	cin >> n;
	L(i, 1, n) {
		cin >> x[i] >> y[i] >> s[i];
		int p = lower_bound(x + 1, x + i + 1, y[i]) - x; 
		dp[i] = (x[i] - y[i]) % mod, (dp[i] += (pre[i - 1] + mod - pre[p - 1]) % mod) %= mod;
		if (s[i]) (ns += dp[i]) %= mod;
		pre[i] = (pre[i - 1] + dp[i]) % mod;
	}
	(ns += x[n] + 1) %= mod;
	cout << ns << "\n";
	return 0;
}