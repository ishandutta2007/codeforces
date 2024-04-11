#include <bits/stdc++.h>
using namespace std;

vector<int> out[1000001];

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n, m; cin >> n >> m;
	vector<pair<int, int>> rob(n), light(m);
	for (int i = 0; i < n; i++) {
		cin >> rob[i].first >> rob[i].second;
	}
	for (int i = 0; i < m; i++) {
		cin >> light[i].first >> light[i].second;
	}
	
	multiset<int> ms;
	for (auto [x, y]: rob) {
		for (auto [X, Y]: light) {

			if (x > X || y > Y) continue;

			int mov = abs(x - X);
			out[mov].push_back(abs(y - Y) + 1);
			ms.insert(abs(y - Y) + 1);

		}
	}

	int ans = 200000000;
	for (int i = 0; i <= 1000000; i++) {
		if (ms.empty()) {
			ans = min(ans, i); continue;
		}
		ans = min(ans, i + *ms.rbegin());

		for (int j: out[i]) {
			ms.erase(ms.find(j));
		}
	}
	cout << ans << '\n';

	return 0;
}