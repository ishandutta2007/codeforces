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

		vector<int> p(n), pos(n);
		for (int i = 0; i < n; i++) {
			cin >> p[i], pos[--p[i]] = i;
		}

		int last = n;
		vector<int> ans(n);

		for (int i = n - 1; i >= 0; i--) {
			if (pos[i] < last) {
				copy(p.begin() + pos[i], p.begin() + last, ans.begin() + (n - last));
				last = pos[i];
			}
		}
		for (auto &x : ans) cout << x + 1 << ' '; cout << '\n';
	}
	return 0;
}