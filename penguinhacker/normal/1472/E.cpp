#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		vector<int> ans(n, -1);
		map<int, vector<pair<int, int>>> mp;
		for (int i = 0; i < n; ++i) {
			int w, h; cin >> w >> h;
			if (w > h) swap(w, h);
			mp[w].emplace_back(h, i);
		}
		pair<int, int> small = {INT_MAX, -1};
		for (auto& x : mp) {
			vector<pair<int, int>>& v = x.second;
			for (pair<int, int> p : v) if (small.first < p.first) ans[p.second] = small.second + 1;
			for (pair<int, int> p : v) if (small.second == -1 || p < small) small = p;
		}
		for (int i = 0; i < n; ++i) cout << ans[i] << " ";
		cout << "\n";
	}
	return 0;
}