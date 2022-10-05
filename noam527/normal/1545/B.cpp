#include <bits/stdc++.h>
typedef long long ll;
typedef long double ldb;
const int md = 998244353;
const ll inf = 3e18;
const int OO = 1;
using namespace std;

const int B = 20;

int dp[B][B];

void prep() {
	for (int i = 0; i < B; i++) {
		dp[i][0] = 1;
	}
	for (int i = 2; i < B; i++) {
		for (int j = 1; 2 * j <= i; j++) {
			dp[i][j] = dp[i - 1][j] + dp[i - 2][j - 1];
		}
	}
	for (int k = 1; k < 10; k++) {
		for (int i = 2 * k; i < B; i++) {
			cout << i << ": " << dp[i][k] << '\n';
		}
		cout << '\n';
	}
}

ll pw(ll b, ll e) {
	ll res = 1;
	while (e) {
		if (e & 1) res = res * b % md;
		e /= 2, b = b * b % md;
	}
	return res;
}
ll inv(ll x) {
	return pw(x, md - 2);
}

int n;
string s;

ll fact(ll k) {
	ll res = 1;
	for (int i = 2; i <= k; i++)
		res = res * i % md;
	return res;
}

ll choose(ll x, ll y) {
	return fact(x) * inv(fact(y)) % md * inv(fact(x - y)) % md;
}

void solve() {
	cin >> n >> s;
	vector<int> sz;
	int cur = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '1') {
			cur++;
		}
		else {
			if (cur > 0) sz.push_back(cur);
			cur = 0;
		}
	}
	if (cur > 0) sz.push_back(cur);
	int cnt = 0, total = 0;
	for (auto &i : sz) {
		if (i & 1) cnt++;
		total += (i / 2) * 2;
	}
	int kk = total / 2;
	int nn = n - cnt;
	cout << choose(nn - kk, kk) << '\n';

}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
	cin >> tst;
	while (tst--) solve();
}