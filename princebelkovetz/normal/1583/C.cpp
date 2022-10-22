#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <queue>
#include <string>
#include <unordered_map>

using namespace std;
#define debug(x) cout << #x << " is " << x << '\n';
#define ld long double
#define int long long

const int mod = 1e9 + 7, N = 5e5 + 3;

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m; cin >> n >> m;
	vector <string> a(n);
	for (auto& x : a) cin >> x;
	vector <int> pref(m + 1);
	for (int i = 1; i < n; ++i) {
		for (int j = 1; j < m; ++j) {
			if (a[i - 1][j] == 'X' and a[i][j - 1] == 'X')
				pref[j + 1]++;
		}
	}
	for (int i = 0; i < m; ++i)
		pref[i + 1] += pref[i];

	int q; cin >> q;
	while (q--) {
		int l, r; cin >> l >> r;
		if (l == r) cout << "YES\n";
		else cout << (pref[r] - pref[l] > 0 ? "NO" : "YES") << '\n';
	}

	return 0;
}