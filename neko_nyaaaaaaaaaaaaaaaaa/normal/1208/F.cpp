#include <bits/stdc++.h>
using namespace std;

struct node {
	int mx, mx2;

	node(int x) {
		mx = x;
		mx2 = -1;
	}

	node() {mx = mx2 = -1;}
};

node merge(node a, node b) {
	node ans;
	ans.mx = max(a.mx, b.mx);
	if (ans.mx == a.mx) {
		ans.mx2 = max(b.mx, a.mx2);
	} else {
		ans.mx2 = max(a.mx, b.mx2);
	}
	return ans;
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	vector<node> dp(1 << 21);
	for (int i = n-1; i >= 0; i--) {
		dp[a[i]] = merge(dp[a[i]], node(i));
	}

	for (int i = 0; i < 21; i++) {
		for (int j = 0; j < (1 << 21); j++) {
			if (!(j & (1 << i)))
				dp[j] = merge(dp[j], dp[j ^ (1 << i)]);
		}
	}

	int ans = 0;
	for (int i = 0; i < n-2; i++) {
		int cur = 0;
		for (int j = 20; j >= 0; j--) {
			if (!(a[i] & (1 << j))) {
				int nxt = cur ^ (1 << j);
				if (dp[nxt].mx2 > i) {
					cur = nxt;
				}
			}
		}
		ans = max(ans, a[i] | cur);
	}
	cout << ans << '\n';

	return 0;
}