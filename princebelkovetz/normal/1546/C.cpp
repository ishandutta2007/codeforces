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

const int mod = 1e9 + 7, N = 50;

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(8);
	int tt; cin >> tt;
	while (tt--) {
		int n; cin >> n;
		vector <int> a(n), kok[2];
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			kok[i & 1].push_back(a[i]);
		}
		sort(a.begin(), a.end());
		sort(kok[0].begin(), kok[0].end());
		sort(kok[1].begin(), kok[1].end());
		vector <int> b;
		for (int i = 0; i < n / 2; ++i) {
			b.push_back(kok[0][i]);
			b.push_back(kok[1][i]);
		}
		if (n & 1) b.push_back(kok[0].back());
		cout << (a == b ? "YES" : "NO") << '\n';

	}
	return 0;
}