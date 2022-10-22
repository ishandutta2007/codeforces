#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <queue>

using namespace std;
#define debug(x) cout << #x << " is " << x << '\n';
#define ld long double
#define int long long

const int mod = 1e9 + 7;

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int tt; cin >> tt;
	while (tt--) {
		int n; cin >> n;
		vector <int> a(2 * n);
		int c[2];
		c[0] = c[1] = 0;
		for (int i = 0; i < 2 * n; ++i) {
			cin >> a[i];
			c[a[i] & 1]++;
		}
		cout << (c[0] == c[1] ? "Yes" : "No") << '\n';
	}
	return 0;
}