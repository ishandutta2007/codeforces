#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int A, B, k;
		cin >> A >> B >> k;

		vector<int> a(k), b(k);
		for (auto &x : a) cin >> x, --x;
		for (auto &x : b) cin >> x, --x;

		vector<int> cnt_a(A), cnt_b(B);
		for (auto &x : a) cnt_a[x] += 1;
		for (auto &x : b) cnt_b[x] += 1;

		long long ans = 0;
		for (int i = 0; i < k; i++) {
			ans += k + 1 - cnt_a[a[i]] - cnt_b[b[i]];
		}
		cout << ans / 2 << '\n';
	}
	return 0;
}