#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;
const int N = 3e5 + 5;

int n, m, a[N];
ll pref[N], ans[N];
vector<pair<int, int>> queries[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];

	cin >> m;
	for (int i = 0, x, y; i < m; i++) {
		cin >> x >> y;
		queries[y].emplace_back(--x, i);
	}

	for (int d = 1; d < N; d++) {
		if (queries[d].empty()) continue;
		sort(queries[d].begin(), queries[d].end());
		for (auto&[l, i] : queries[d]) {
			if (pref[l]) {
				ans[i] = pref[l];
				continue;
			}
			int last = l;
			for (int j = l; j < n; j += d) {
				last = j;
				pref[j] = a[j];
			}
			for (int j = last - d; j >= l; j -= d) {
				pref[j] += pref[j + d];
			}
			ans[i] = pref[l];
		}
		for (auto&[l, i] : queries[d]) {
			if (!pref[l]) continue;
			for (int i = l; i < n; i += d) pref[i] = 0;
		}
	}
	for (int i = 0; i < m; i++) cout << ans[i] << '\n';
	return 0;
}