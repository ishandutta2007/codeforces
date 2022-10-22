#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <queue>
#include <string>

using namespace std;
#define debug(x) cout << #x << " is " << x << '\n';
#define ld long double
#define int long long

const int mod = 1e9 + 7, N = 1e5 + 2;

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int tt; cin >> tt;
	while (tt--) {
		int n, q; cin >> n >> q;
		string s; cin >> s;
		vector <int> pref(n + 1);
		for (int i = 0; i < n; ++i) {
			int x = (s[i] == '+');
			pref[i + 1] = pref[i] + (x ^ (i & 1));
		}
		while (q--) {
			int l, r; cin >> l >> r;
			int res = pref[r] - pref[l - 1];
			if (res == (r - l + 1) / 2 and (r - l) % 2) cout << 0;
			else if ((r - l + 1) & 1) cout << 1;
			else cout << 2;
			cout << '\n';
		}
	}
	
	return 0;
}