#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
const int MOD = 1e9 + 7;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin >> s;
	int n = s.size();
	vector<ll> pp(n, 1);
	for (int i = 1; i < n; ++i) {
		pp[i] = 10 * pp[i - 1] % MOD;
	}
	vector<ll> pre(n);
	for (int i = 1; i < n; ++i) {
		pre[i] = (i * pp[i - 1] + pre[i - 1]) % MOD;
	}
	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		ll dig = s[i] - '0';
		int p = n - i - 1;
		ans += dig * ((ll)i * (i + 1) / 2 % MOD) % MOD * pp[p] % MOD;
		ans += pre[p] * dig % MOD;
		ans %= MOD;
	}
	cout << ans;
	return 0;
}