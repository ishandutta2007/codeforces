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

		vector<int> a(n), b(n), m(n), l(n), r(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i] >> b[i] >> m[i];
			l[i] = (a[i] >= m[i] ? a[i] - m[i] : 0);
			r[i] = (b[i] >= m[i] ? a[i] : a[i] - (m[i] - b[i]));
		}

		map<int, vector<int>> mp;
		for (int i = 0; i < n; i++) {
			mp[a[i] + b[i] - m[i]].push_back(i);
		}

		int ans = 0;
		for (auto [k, v] : mp) {
			map<int, vector<int>> add;
			for (int i : v) {
				add[l[i]].push_back(i + 1);
				add[r[i]].push_back(-i - 1);
			}
			set<int> current;
			for (auto [x, v1] : add) {
				for (int i : v1) {
					if (i > 0) {
						current.insert(i - 1);
					}
				}
				bool successful_erase = false;
				for (int i : v1) {
					successful_erase |= i < 0 && current.find(-i - 1) != current.end();
				}
				if (successful_erase) {
					for (int i : current) {
						l[i] = a[i] - x;
					}
					current.clear();
					ans += 1;
				}
			}
		}
		cout << ans << '\n';
		for (int i = 0; i < n; i++) {
			cout << l[i] << ' ' << m[i] - l[i] << '\n';
		}
	}
	return 0;
}