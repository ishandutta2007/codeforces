#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, q;
	cin >> n >> q;

	vector<int> a(n);
	for (auto &x : a) cin >> x;

	while (q--) {
		int l, r;
		cin >> l >> r, --l, --r;

		vector<int> left(n), right(n), st;
		for (int i = l + 1; i <= r; i++) {
			while (!st.empty() && abs(a[i] - a[i - 1]) >= abs(a[st.back()] - a[st.back() - 1])) {
				st.pop_back();
			}
			left[i] = st.empty() ? l : st.back();
			st.push_back(i);
		}

		st.clear();
		for (int i = r; i > l; i--) {
			while (!st.empty() && abs(a[i] - a[i - 1]) > abs(a[st.back()] - a[st.back() - 1])) {
				st.pop_back();
			}
			right[i] = st.empty() ? r + 1 : st.back();
			st.push_back(i);
		}

		long long ans = 0;
		for (int i = l + 1; i <= r; i++) {
			ans += (long long)abs(a[i] - a[i - 1]) * (i - left[i]) * (right[i] - i);
		}
		cout << ans << '\n';
	}
	return 0;
}