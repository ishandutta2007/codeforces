#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <map>
#define finish(X) return cout << (X) << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 998244353;
const ll inf = 2e18;
const int OO = 1;
using namespace std;

struct knapsack {
	int k;
	vector<vector<ll>> st;
	vector<ll> dp;
	knapsack(int sz) {
		k = sz;
		dp.resize(k + 1, -inf);
		dp[0] = 0;
	}
	void upd(int sz, ll val) {
		st.push_back(dp);
		for (int i = k; i >= sz; i--)
			dp[i] = max(dp[i], dp[i - sz] + val);
	}
	void undo() {
		dp = st.back();
		st.pop_back();
	}
};

int n, k;
vector<vector<ll>> a;
ll ans = -inf;

void work(int l, int r, knapsack &dp) {
	if (l > r) return;
	if (l == r) {
		ll mx = 0;
		for (int i = 0; i < k; i++) {
			mx = max(mx, dp.dp[i]);
			if (k - i <= a[l].size())
				ans = max(ans, mx + a[l][k - i - 1]);
		}
		mx = max(mx, dp.dp[k]);
		ans = max(ans, mx);
		return;
	}
	int mid = (l + r) / 2;
	for (int i = l; i <= mid; i++)
		dp.upd(a[i].size(), a[i].back());
	work(mid + 1, r, dp);
	for (int i = l; i <= mid; i++)
		dp.undo();
	for (int i = mid + 1; i <= r; i++)
		dp.upd(a[i].size(), a[i].back());
	work(l, mid, dp);
	for (int i = mid + 1; i <= r; i++)
		dp.undo();
}

void solve() {
	cin >> n >> k;
	a.resize(n);
	for (int i = 0; i < n; i++) {
		int len, what;
		cin >> len;
		a[i].resize(min(k, len));
		for (auto &j : a[i]) cin >> j;
		for (int x = min(k, len); x < len; x++)
			cin >> what;

		for (int j = 1; j < a[i].size(); j++)
			a[i][j] += a[i][j - 1];
	}

	knapsack dp(k);
	work(0, n - 1, dp);
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
//	cin >> tst;
	while (tst--) {
		solve();
	}
}