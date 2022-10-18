#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int MOD = 998244353;

void solve() {
	int n, m, k, q;
	cin >> n >> m >> k >> q;

	vector<int> x(q), y(q);
	for (int i = 0; i < q; i++) {
		cin >> x[i] >> y[i];
	}

	i64 res = 1;
	set<int> xs, ys;
	for (int i = q-1; i >= 0; i--) {
		bool ok = true;
		if (xs.count(x[i]) && ys.count(y[i])) ok = false;
		if (ssize(xs) == n) ok = false;
		if (ssize(ys) == m) ok = false;
		if (ok) res = res * k % MOD;
		xs.insert(x[i]), ys.insert(y[i]);
	}
	cout << res << '\n';
}

int main() {
	int tc; cin >> tc;
	while (tc--) solve();
}