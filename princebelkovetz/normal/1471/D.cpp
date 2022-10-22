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
#define int long long
#define debug(x) cout << #x << " is " << x << '\n';
const int N = 1e6 + 2, mod = 1e9 + 7, mod2 = 998244353;
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(6);
	int testcases; cin >> testcases;
	vector <int> resh(N);
	for (int i = 2; i < N; ++i) {
		if (resh[i]) continue;
		resh[i] = i;
		for (int j = i * i; j < N; j += i) {
			if (!resh[j]) resh[j] = i;
		}
	}
	while (testcases --> 0) {
		int n; cin >> n;
		vector <int> a(n);
		map <int, vector <int>> d;
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			int got = 1;
			while (resh[a[i]]) {
				if (got % resh[a[i]])
					got *= resh[a[i]];
				else
					got /= resh[a[i]];
				a[i] /= resh[a[i]];
			}
			d[got].push_back(i);
		}
		int v1 = 0;
		for (auto x : d) v1 = max(v1, (int) x.second.size());
		for (auto x : d) {
			if (x.first == 1) continue;
			if (x.second.size() % 2 == 0) {
				for (auto y : x.second)
					d[1].push_back(y);
			}
		}
		if (d.find(1) == d.end())
			d[1] = {};
		int v2 = max(v1, (int)d[1].size());
		int q; cin >> q;
		while (q-- > 0) {
			int w; cin >> w;
			cout << (w == 0 ? v1 : v2) << '\n';
		}
	}
	return 0;
}