#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	if (n == 2) {
		int k; cin >> k;
		int x; cin >> x;
		cout << "1 " << x << "\n";
		cout << k - 1;
		for (int i = 1; i < k; ++i) {
			cin >> x;
			cout << " " << x;
		}
		return 0;
	}
	vector<vector<int>> sets;
	vector<int> mins;
	int all_min = INT_MAX;
	for (int i = 0; i < n * (n - 1) / 2; ++i) {
		int k; cin >> k;
		vector<int> v;
		int cur_min = INT_MAX;
		for (int j = 0; j < k; ++j) {
			int x; cin >> x;
			cur_min = min(cur_min, x);
			v.push_back(x);
		}
		all_min = min(all_min, cur_min);
		sets.push_back(v);
		mins.push_back(cur_min);
	}
	vector<set<int>> important;
	for (int i = 0; i < n * (n - 1) / 2; ++i) {
		if (mins[i] == all_min) {
			set<int> s(sets[i].begin(), sets[i].end());
			important.push_back(s);
		}
	}
	assert(important.size() == n - 1);
	sort(important.begin(), important.end(), [&](const set<int>& a, const set<int>& b) {return a.size() < b.size();});
	vector<bool> used(201);
	vector<vector<int>> ans(n);
	for (const int& x : important[0]) {
		bool b = 1;
		for (int i = 1; i < n - 1; ++i) {
			if (important[i].find(x) == important[i].end()) {
				b = 0;
				break;
			}
		}
		if (b) {
			used[x] = 1;
			ans[0].push_back(x);
		}
	}
	for (int i = 0; i < n - 1; ++i)
		for (const int& x : important[i])
			if (!used[x])
				ans[i + 1].push_back(x);
	for (auto& x : ans) {
		cout << x.size();
		for (int i : x) cout << " " << i;
		cout << "\n";
	}
	return 0;
}