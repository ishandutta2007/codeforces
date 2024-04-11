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

	int tt; cin >> tt;
	while (tt--) {
		int n, m; cin >> n >> m;
		set <int> centr;
		for (int i = 1; i <= n; ++i)
			centr.insert(i);
		for (int i = 0, a, b, c; i < m; ++i) {
			cin >> a >> b >> c;
			centr.erase(b);
		}
		int cent = *centr.begin();
		for (int i = 1; i <= n; ++i) {
			if (i == cent) continue;
			cout << i << ' ' << cent << '\n';
		}
	}

	return 0;
}