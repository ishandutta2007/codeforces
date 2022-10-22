#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <queue>
#include <iomanip>

using namespace std;

#define debug(x) cout << #x << " is " << x << '\n';
#define ld long double
#define int long long

const int mod = 1e9 + 7;

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(8);
	int tt; cin >> tt;
	while (tt --> 0) {
		int k, n, m; cin >> k >> n >> m;
		vector <int> a(n), b(m);
		for (auto& x : a) cin >> x;
		for (auto& x : b) cin >> x;
		int c1 = 0, c2 = 0;
		vector <int> ans;
		while (c1 < n or c2 < m) {
			if (c1 == n) ans.push_back(b[c2++]);
			else if (c2 == m) ans.push_back(a[c1++]);
			else if (a[c1] < b[c2]) ans.push_back(a[c1++]);
			else ans.push_back(b[c2++]);
		}
		bool c = true;
		for (auto& x : ans) {
			if (!x) k++;
			else if (x > k) c = false;
		}
		if (c) {
			for (auto& x : ans) cout << x << ' ';
		}
		else cout << "-1";
		cout << '\n';
	}
	return 0;
}