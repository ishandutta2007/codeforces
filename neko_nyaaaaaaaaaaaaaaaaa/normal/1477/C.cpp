#include <bits/stdc++.h>
using namespace std;

#define int long long

int dist(pair<int, int> a, pair<int, int> b) {
	int ans = 0;
	ans += (a.first - b.first)*(a.first - b.first);
	ans += (a.second - b.second)*(a.second - b.second);
	return ans;
}

void solve() {
	int n; cin >> n;
	vector<pair<int, int>> p(n);
	for (int i = 0; i < n; i++) {
		cin >> p[i].first >> p[i].second;
	}

	vector<int> ans;
	for (int i = 0; i < n; i++) {
		ans.push_back(i);
	}

	for (int ite = 0; ite < n; ite++) {
		for (int i = 1; i+1 < n; i++) {
			int distlong = dist(p[ans[i-1]], p[ans[i+1]]);
			int dist1 = dist(p[ans[i]], p[ans[i-1]]);
			int dist2 = dist(p[ans[i]], p[ans[i+1]]);

			// bad angle when longest side is dist long
			// and is >= dist1 + dist2 

			if (distlong > dist1 && distlong > dist2 && distlong >= dist1 + dist2) {
				swap(ans[i], ans[i+1]);
			}
		}
	}
	for (int i: ans) cout << i+1 << ' ';
		cout << '\n';
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t = 1;
	while (t--) {
		solve();
	}

	return 0;
}