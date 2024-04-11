#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n, s;
		cin >> n >> s;

		vector<int> a(n);
		for (auto &x : a) cin >> x;

		reverse(a.begin(), a.end());

		vector<long long> pref(n + 1);
		for (int i = 1; i <= n; i++) {
			pref[i] = a[i - 1] + pref[i - 1];
		}

		vector<int> st = {0};

		int l = -1, r = -1;
		for (int i = 1; i <= n; i++) {
			int lo = 0, hi = (int) st.size() - 1;
			while (lo < hi) {
				int mid = lo + (hi - lo) / 2;
				if (s + pref[i] - pref[st[mid]] >= 0) {
					hi = mid;
				} else {
					lo = mid + 1;
				}
			}
			if (s + pref[i] - pref[st[lo]] >= 0) {
				int cur_l = (lo == 0 ? 0 : st[lo - 1] + 1);
				if (l == -1) {
					l = cur_l, r = i;
				} else if (i - cur_l > r - l) {
					l = cur_l, r = i;
				}
			}
			while (!st.empty() && pref[i] >= pref[st.back()]) {
				st.pop_back();
			}
			st.push_back(i);
		}

		if (l == -1) {
			cout << "-1\n";
		} else {
			cout << n - r + 1 << ' ' << n - l << '\n';
		}
	}
	return 0;
}