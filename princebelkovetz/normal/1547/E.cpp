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
		int n, k; cin >> n >> k;
		vector <int> a(k), t(k), b(n, -1);
		for (auto& x : a) cin >> x, --x;
		for (auto& x : t) cin >> x;
		for (int i = 0; i < k; ++i)
			b[a[i]] = t[i];
		vector <int> ans(n, mod * mod);
		multiset <int> cur;
		int add = 0;
		for (int i = 0; i < n; ++i) {
			if (b[i] != -1) 
				cur.insert(b[i] - add);
			if (cur.empty()) continue;
			ans[i] = min(ans[i], *cur.begin() + add);
			add++;
		}
		cur = {};
		add = 0;
		for (int i = n - 1; i >= 0; --i) {
			if (b[i] != -1) 
				cur.insert(b[i] - add);
			if (cur.empty()) continue;
			ans[i] = min(ans[i], *cur.begin() + add);
			add++;
		}
		for (auto& x : ans) cout << x << ' ';
		cout << '\n';
	}
	return 0;
}