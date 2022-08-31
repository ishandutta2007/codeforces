#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n, k;
		cin >> n >> k;

		set<int> s, not_s;
		for (int i = 0; i <= 3 * n; i++) {
			not_s.insert(i);
		}

		for (int i = 0, x; i < n; i++) {
			cin >> x, s.insert(x), not_s.erase(x);
		}

		if (k == 0) {
			cout << n << '\n';
		} else {
			int a = *not_s.begin();
			int b = *s.rbegin();
			int c = (a + b + 1) / 2;
			if (c == a) {
				cout << n + k << '\n';
			} else {
				cout << n + (s.find(c) == s.end()) << '\n';
			}
		}
	}
	return 0;
}