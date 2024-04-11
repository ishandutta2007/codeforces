#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n, k;
		cin >> n >> k;

		vector<pair<int, int>> a(n);
		for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;

		bool ok = false;
		for (int i = 0; i < n; i++) {
			bool f = true;
			for (int j = 0; j < n; j++) {
				f &= abs(a[i].first - a[j].first) + abs(a[i].second - a[j].second) <= k;
			}
			ok |= f;
		}

		cout << (ok ? 1 : -1) << '\n';
	}
	return 0;
}