#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n, l, r, s;
		cin >> n >> l >> r >> s;

		l -= 1, r -= 1;
		s -= r - l + 1;

		vector<bool> used(n);
		vector<int> a(n, -1);

		iota(a.begin() + l, a.begin() + r + 1, 0);
		s -= accumulate(a.begin() + l, a.begin() + r + 1, 0);

		if (s < 0) {
			cout << "-1\n";
			continue;
		}

		for (int i = r; i >= l && s > 0; i--) {
			if (s + a[i] - (n - 1 - (r - i)) >= 0) {
				s += a[i];
				a[i] = n - 1 - (r - i);
				s -= a[i];
			} else {
				a[i] += s;
				s = 0;
			}
		}

		for (int i = l; i <= r; i++) {
			used[a[i]] = true;
		}

		if (s > 0) {
			cout << "-1\n";
		} else {
			for (int i = 0, j = 0; i < n; i++) {
				if (a[i] == -1) {
					while (used[j]) {
						j += 1;
					}
					a[i] = j;
					j += 1;
				}
			}

			for (auto &x : a) cout << x + 1 << ' ';
			cout << '\n';
		}
	}
	return 0;
}