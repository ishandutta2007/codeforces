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

	int n;
	cin >> n;

	vector<pair<int, int>> a(n);
	for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;

	sort(a.begin(), a.end());

	vector<int> w(n), ans(n), aans(n);
	for (int i = 0; i < n; i++) cin >> w[i];

	map<int, vector<int>> ids, points;
	for (int i = 0; i < n; i++) {
		ids[w[i]].push_back(i);
		points[a[i].second - a[i].first].push_back(i);
	}

	for (auto& [id, v] : ids) {
		auto it = points.find(id);
		if (it == points.end() or it->second.size() != v.size()) {
			cout << "NO\n";
			return 0;
		}

		vector<int>& v1 = it->second;
		sort(v1.begin(), v1.end(), [&] (int i, int j) {
			return a[i].first < a[j].first;
		});

		for (int i = 0; i < v.size(); i++) {
			ans[v[i]] = v1[i];
			aans[v1[i]] = v[i];
		}
		points.erase(it);
	}

	if (!points.empty()) {
		cout << "NO\n";
		return 0;
	}

	for (int i = 0; i < n; i++) {
		if (a[i].first > 0) {
			int idx = lower_bound(a.begin(), a.end(), make_pair(a[i].first - 1, a[i].second)) - a.begin();
			if (aans[idx] > aans[i]) {
				cout << "NO\n";
				return 0;
			}
		}
		if (a[i].second > 0) {
			int idx = lower_bound(a.begin(), a.end(), make_pair(a[i].first, a[i].second - 1)) - a.begin();
			if (aans[idx] > aans[i]) {
				cout << "NO\n";
				return 0;
			}
		}
	}

	cout << "YES\n";
	for (int i = 0; i < n; i++) {
		cout << a[ans[i]].first << ' ' << a[ans[i]].second << '\n';
	}
	return 0;
}