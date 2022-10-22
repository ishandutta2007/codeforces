#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <iomanip>
#include <cassert>
using namespace std;
#define debug(x) cout << #x << " is " << x << '\n';
#define ld long double
#define int long long
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(6);
	int tt; cin >> tt;
	while (tt --> 0) {
		int n; cin >> n;
		vector <int> a(2 * n);
		for (auto &x: a) cin >> x;
		sort(a.begin(), a.end());
		bool c = false;
		for (int i = 0; i < 2 * n - 1; ++i) {
			multiset <int> cur = { a.begin(), a.end() };
			int x = a.back() + a[i];
			vector <vector <int>> res;
			while (!cur.empty()) {
				int r = *cur.rbegin();
				int l = x - r;
				cur.erase(cur.find(r));
				if (cur.find(l) == cur.end()) break;
				int newx = max(l, r);
				res.push_back({ l, r });
				cur.erase(cur.find(l));
				x = newx;
			}
			if (res.size() == n) {
				cout << "YES\n";
				cout << a.back() + a[i] << '\n';
				for (auto x : res) cout << x[0] << ' ' << x[1] << '\n';
				c = true;
				break;
			}
		}
		if (!c) {
			cout << "NO\n";
		}

	}
	return 0;
}