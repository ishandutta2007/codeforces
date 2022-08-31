#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<int> a(n);
		for (int i = 0; i < n; i++) cin >> a[i];

		map<int, vector<int>> mp;
		for (int i = 0; i < n; i++) {
			mp[a[i]].push_back(i);
		}

		int leader = -1;
		for (auto& [aa, v] : mp) {
			if (2 * v.size() <= n) {
				leader = aa;
			}
		}

		if (leader == -1) {
			cout << "NO\n";
			continue;
		}

		cout << "YES\n";
		int src = mp[leader][0];
		bool others_done = false;
		for (auto& [aa, v] : mp) {
			if (aa != leader) {
				for (int x : v) {
					cout << src + 1 << ' ' << x + 1 << '\n';
					if (!others_done) {
						for (int i : mp[leader]) {
							if (i == src) continue;
							cout << i + 1 << ' ' << x + 1 << '\n';
						}
						others_done = true;
					}
				}
			}
		}
	}
	return 0;
}