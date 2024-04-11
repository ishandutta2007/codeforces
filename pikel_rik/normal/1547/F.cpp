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

		auto nxt = [&](int i) -> int {
			return i + 1 == n ? 0 : i + 1;
		};

		auto prv = [&](int i) -> int {
			return i > 0 ? i - 1 : n - 1;
		};

		set<int> changed;
		for (int i = 0; i < n; i++) {
			changed.insert(i);
		}

		int moves = -1;
		vector<int> new_a(n, -1);

		for (; !changed.empty(); moves++) {
			for (int i : changed) {
				int j = nxt(i);
				new_a[i] = __gcd(a[i], a[j]);
			}
			set<int> new_changed;
			for (int i : changed) {
				if (new_a[i] != a[i]) {
					new_changed.insert(prv(i));
					new_changed.insert(i);
					a[i] = new_a[i];
				}
			}
			changed.swap(new_changed);
		}
		cout << moves << '\n';
	}
	return 0;
}