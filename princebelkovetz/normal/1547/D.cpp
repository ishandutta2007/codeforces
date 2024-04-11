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
		int n; cin >> n;
		vector <int> a(n);
		for (auto& x : a) cin >> x;
		vector <int> ans = { 0 };
		int cur = a[0];
		for (int i = 1; i < n; ++i) {
			int ok = 0;
			for (int j = 0; j < 31; ++j) {
				if (((cur >> j) & 1) and ((a[i] >> j) & 1 ^ 1)) {
					ok += (1 << j);
				}
			}
			ans.push_back(ok);
			cur = ok ^ a[i];
		}
		for (auto x : ans) cout << x << ' ';
		cout << '\n';
	}
	return 0;
}