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

		if (a.size() == 1 && a[0] % 2 != 0) {
			cout << "-1\n";
			continue;
		}

		int odd1 = -1, odd2 = -1, even = -1;
		for (int i = 0; i < n; i++) {
			if (a[i] % 2 != 0) {
				odd2 = odd1, odd1 = i;
			} else {
				even = i;
			}
		}

		if (even != -1) {
			cout << 1 << '\n' << even + 1 << '\n';
		} else {
			cout << 2 << '\n' << odd1 + 1 << ' ' << odd2 + 1 << '\n';
		}
	}
	return 0;
}