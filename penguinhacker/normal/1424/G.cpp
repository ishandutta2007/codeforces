#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<pair<int, int>> e;
	for (int i = 0; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		e.emplace_back(a, -1);
		e.emplace_back(b - 1, 1);
	}
	sort(e.begin(), e.end());
	pair<int, int> ans = {0, -1};
	int cur = 0;
	for (pair<int, int> p : e) {
		cur += -p.second;
		if (cur > ans.first) {
			ans = {cur, p.first};
		}
	}
	cout << ans.second << " " << ans.first;
	return 0;
}