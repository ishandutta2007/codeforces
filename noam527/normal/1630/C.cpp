#include <bits/stdc++.h>
typedef long long ll;
typedef long double ldb;
const int md = 998244353;
const ll inf = 3e18;
const int OO = 1;
using namespace std;

struct segtree {
	int n;
	vector<int> mn;
	segtree() {}
	segtree(int size) {
		n = max(2, size);
		while (n != (n & -n)) n += (n & -n);
		mn.resize(2 * n, md);
	}
	void fix(int x) {
		mn[x] = min(mn[x + x + 1], mn[x + x + 2]);
	}
	void upd(int i, int x) {
		i += n - 1;
		mn[i] = x;
		while (i) {
			i = (i - 1) / 2;
			fix(i);
		}
	}
	int query(int l, int r) {
		int ans = md;
		for (l += n - 1, r += n - 1; l < r; l = (l - 1) / 2, r = (r - 1) / 2) {
			if (!(l & 1)) ans = min(ans, mn[l++]);
			if (r & 1) ans = min(ans, mn[r--]);
		}
		if (l == r) ans = min(ans, mn[l]);
		return ans;
	}
};

int n;
vector<int> a;

void solve() {
	cin >> n;
	a.resize(n);
	for (auto &i : a) cin >> i;
	vector<int> dp(n, md), fi(n + 1, -1);
	segtree T(n);
	for (int i = 0; i < n; i++) {
		if (fi[a[i]] == -1) {
			fi[a[i]] = i;
			if (i > 0)
				dp[i] = 1 + dp[i - 1];
			else dp[i] = 1;
			T.upd(i, dp[i]);
			continue;
		}
		int l = fi[a[i]];
		if (l == 0) dp[i] = 2;
		else dp[i] = 2 + dp[l - 1];

		dp[i] = min(dp[i], 1 + dp[i - 1]);

		dp[i] = min(dp[i], 1 + T.query(l + 1, i - 1));
		T.upd(i, dp[i]);
	}
	cout << n - dp[n - 1] << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
	//cin >> tst;
	while (tst--) solve();
}