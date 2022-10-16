#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int n, m; cin >> n >> m;
	vector<int> d(n+1);
	while (m--) {
		int x, y, w; cin >> x >> y >> w;
		d[x] += w;
		d[y] -= w;
	}

	priority_queue<pair<int, int>> in;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> out;
	for (int i = 1; i <= n; i++) {
		if (d[i] == 0) continue;
		else if (d[i] > 0) {
			in.push({d[i], i});
		} else {
			out.push({abs(d[i]), i});
		}
	}

	vector<tuple<int, int, int>> ans;
	while (in.size() || out.size()) {
		auto [wu, u] = in.top(); in.pop();
		auto [wv, v] = out.top(); out.pop();

		int gg = min(wu, wv);
		ans.emplace_back(u, v, gg);
		wu -= gg; wv -= gg;

		if (wu != 0) {
			in.push({wu, u});
		} 
		if (wv != 0) {
			out.push({wv, v});
		}
	}

	cout << ans.size() << '\n';
	for (auto [u, v, w]: ans) cout << u << ' ' << v << ' ' << w << '\n';
  
	return 0;
}