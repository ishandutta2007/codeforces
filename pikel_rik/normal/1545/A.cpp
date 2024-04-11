#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<int> a(n);
		for (auto &x : a) cin >> x;

		vector<int> even, odd;
		for (int i = 0; i < n; i++) {
			if (i % 2 == 0) {
				even.push_back(a[i]);
			} else {
				odd.push_back(a[i]);
			}
		}
		sort(even.begin(), even.end());
		sort(odd.begin(), odd.end());

		vector<int> b(n);
		for (int i = 0; i < n; i++) {
			if (i % 2 == 0) {
				b[i] = even[i / 2];
			} else {
				b[i] = odd[i / 2];
			}
		}

		cout << (is_sorted(b.begin(), b.end()) ? "YES" : "NO") << '\n';
	}
	return 0;
}