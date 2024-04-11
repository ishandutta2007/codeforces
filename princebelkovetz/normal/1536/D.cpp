#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>

using namespace std;
#define debug(x) cout << #x << " is " << x << '\n';
#define ld long double
#define int long long

const int mod = 1e9 + 7;
int gcd(int a, int b) {
	if (!b) return a;
	return gcd(b, a % b);
}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int tt; cin >> tt;
	while (tt --> 0) {
		int n; cin >> n;
		vector <int> a(n);
		for (auto& x : a) cin >> x;
		set <int> cur = { a[0] };
		bool ok = true;
		for (int i = 1; i < n; ++i) {
			if (a[i - 1] < a[i]) {
				auto it = cur.upper_bound(a[i - 1]);
				if (it != cur.end() and *it < a[i]) ok = false;
			}
			else {
				auto it = cur.upper_bound(a[i]);
				if (it != cur.end() and *it < a[i - 1]) ok = false;
			}
			cur.insert(a[i]);
		}
		cout << (ok ? "YES\n" : "NO\n");
	}
	return 0;
}