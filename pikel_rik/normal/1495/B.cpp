#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> p(n);
	for (auto &x : p) cin >> x, --x;

	vector<int> l(n, 1), r(n, 1);
	for (int i = 1; i < n; i++) {
		if (p[i] > p[i - 1]) {
			l[i] = l[i - 1] + 1;
		}
	}
	for (int i = n - 2; i >= 0; i--) {
		if (p[i] > p[i + 1]) {
			r[i] = r[i + 1] + 1;
		}
	}

	vector<int> pref(n), suf(n);
	pref[0] = max(l[0], r[0]);
	for (int i = 1; i < n; i++) {
		pref[i] = max({l[i], r[i], pref[i - 1]});
	}

	suf[n - 1] = max(l[n - 1], r[n - 1]);
	for (int i = n - 2; i >= 0; i--) {
		suf[i] = max({l[i], r[i], suf[i + 1]});
	}

	int ans = 0;
	for (int i = 1; i < n - 1; i++) {
		if (l[i] == 1 || r[i] == 1 || l[i] != r[i] || l[i] % 2 == 0)
			continue;
		int prefix = (i - l[i] >= 0 ? pref[i - l[i]] : 1);
		int suffix = (i + r[i] < n ? suf[i + r[i]] : 1);
		if (max(prefix, suffix) < l[i]) {
			ans += 1;
		}
	}
	cout << ans << '\n';
	return 0;
}