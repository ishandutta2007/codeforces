#include <bits/stdc++.h>
using namespace std;

#define int long long
const int INF = 1e18;

void solve() {
	int n, m; cin >> n >> m;
	vector<int> p(n);
	for (int i = 0; i < n; i++) {
		cin >> p[i];
	}

	// scale it to 200 lol
	vector<int> x(m);
	for (int i = 0; i < m; i++) {
		cin >> x[i]; x[i] *= 2;
	}
	sort(x.begin(), x.end());

	// events????????
	map<int, int> evs;
	for (int i = 0; i < n; i++) {
		// find the closest number
		// wtf am I even doing
		int dist = INF;

		auto it = lower_bound(x.begin(), x.end(), 200*i);
		if (it != x.end()) dist = min(dist, abs((*it) - 200*i));
		if (it != x.begin()) dist = min(dist, abs((*(it-1)) - 200*i));

		dist--;
		evs[200*i - dist] += p[i];
		evs[200*i + dist + 1] -= p[i];
	}

	int ans = 0, sum = 0;
	for (auto [u, v]: evs) {
		sum += v;
		ans = max(ans, sum);
	}
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}