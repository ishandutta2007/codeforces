#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 2e18;
const int OO = 1;
const int OOO = 1;
using namespace std;

int r, n;
vector<int> t, x, y;
vector<int> dp, mx;

void solve() {
	cin >> r >> n;
	n++;
	t.resize(n);
	x.resize(n);
	y.resize(n);
	dp.resize(n);
	mx.resize(n);
	t[0] = 0, x[0] = 1, y[0] = 1;
	for (int i = 1; i < n; i++) {
		cin >> t[i] >> x[i] >> y[i];
	}
	dp[0] = 1;
	mx[0] = 1;
	for (int i = 1; i < n; i++) {
		if (i - 2 * r >= 0)
			dp[i] = 1 + mx[i - 2 * r];
		else
			dp[i] = -md;
		for (int j = max(0, i - 2 * r + 1); j < i; j++) {
			if (abs(x[i] - x[j]) + abs(y[i] - y[j]) <= t[i] - t[j])
				dp[i] = max(dp[i], 1 + dp[j]);
		}
		mx[i] = max(dp[i], mx[i - 1]);
	}
	cout << *max_element(dp.begin(), dp.end()) - 1 << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
	//cin >> tst;
	while (tst--) {
		solve();
	}
}