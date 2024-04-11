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

		vector<int> q(n);
		for (auto &x : q) cin >> x;

		vector<int> small(n), big(n);
		small[0] = big[0] = q[0];

		set<int> s;
		for (int i = 1; i < q[0]; i++) {
			s.insert(i);
		}

		for (int i = 1; i < n; i++) {
			if (q[i] != q[i - 1]) {
				small[i] = q[i];
				for (int j = q[i - 1] + 1; j < q[i]; j++) {
					s.insert(j);
				}
			} else {
				small[i] = *s.begin();
				s.erase(s.begin());
			}
		}

		s.clear();
		for (int i = 1; i < q[0]; i++) {
			s.insert(i);
		}

		for (int i = 1; i < n; i++) {
			if (q[i] != q[i - 1]) {
				big[i] = q[i];
				for (int j = q[i - 1] + 1; j < q[i]; j++) {
					s.insert(j);
				}
			} else {
				big[i] = *s.rbegin();
				s.erase(*s.rbegin());
			}
		}

		for (auto &x : small) cout << x << ' '; cout << '\n';
		for (auto &x : big) cout << x << ' '; cout << '\n';
	}
	return 0;
}