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

		vector<int> b(n);
		for (auto &x : b) cin >> x;

		bool possible = true;

		set<int> s;
		s.insert(b[0]);

		for (int i = 1; i < n; i++) {
			if (b[i] < b[i - 1]) {
				auto it = s.upper_bound(b[i]);
				possible &= it == s.end() || *it >= b[i - 1];
			} else if (b[i - 1] < b[i]) {
				auto it = s.upper_bound(b[i - 1]);
				possible &= it == s.end() || *it >= b[i];
			}
			s.insert(b[i]);
		}
		cout << (possible ? "YES" : "NO") << '\n';
	}
	return 0;
}