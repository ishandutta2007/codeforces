#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <iomanip>
#include <cassert>
#include <queue>
using namespace std;
#define debug(x) cout << #x << " is " << x << '\n';
#define int long long

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(6);
	int tt; cin >> tt;
	while (tt--) {
		int n; cin >> n;
		if (n == 2) {
			cout << "-1\n";
			continue;
		}
		vector <vector <int>> ans(n, vector <int> (n));
		int cur = 1;
		for (int i = 0; i < n; ++i) {
			for (int j = i & 1; j < n; j += 2)
				ans[i][j] = cur++;
		}
		for (int i = 0; i < n; ++i) {
			for (int j = i & 1 ^ 1; j < n; j += 2)
				ans[i][j] = cur++;
		}
		for (auto x : ans) {
			for (auto y : x) cout << y << ' ';
			cout << '\n';
		}
	}
	return 0;
}