#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n;
map<pair<int, int>, vector<pair<int, int>>> mp;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		int a[3]; cin >> a[0] >> a[1] >> a[2];
		sort(a, a + 3);
		mp[{a[0], a[1]}].emplace_back(a[2], i);
		mp[{a[0], a[2]}].emplace_back(a[1], i);
		mp[{a[1], a[2]}].emplace_back(a[0], i);
	}
	pair<int, vector<int>> ans;
	ans.first = 0;
	for (auto& x : mp) {
		int cur = min(x.first.first, x.first.second);
		vector<pair<int, int>>& v = x.second;
		sort(v.begin(), v.end());
		v.resize(unique(v.begin(), v.end()) - v.begin());
		if (v.size() == 1) {
			cur = min(cur, v[0].first);
			if (cur > ans.first) {
				ans = {cur, {v[0].second}};
			}
		}
		else {
			pair<int, int> p1 = v.back();
			pair<int, int> p2 = v[v.size() - 2];
			cur = min(cur, p1.first + p2.first);
			if (cur > ans.first) {
				ans = {cur, {p1.second, p2.second}};
			}
		}
	}
	cout << ans.second.size() << "\n";
	for (int i : ans.second) cout << i << " ";
	return 0;
}