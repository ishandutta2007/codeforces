#include <bits/stdc++.h>
using namespace std;

struct info {
	int cnt = 0;
	vector<int> pos;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, a, b;
	cin >> n >> a >> b;

	vector<int> p(n);
	for (auto &x : p) cin >> x;

	map<int, int> mp;
	for (int i = 0; i < n; i++) {
		mp[p[i]] = i;
	}

	queue<int> q;
	for (auto &[x, s] : mp) {
		auto it = mp.find(a - x);
		if (it == mp.end()) {
			q.push(x);
		}
	}

	vector<int> ans(n);

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		ans[mp[x]] = 1;

		auto it = mp.find(b - x);
		if (it == mp.end()) {
			return cout << "NO\n", 0;
		}

		ans[it->second] = 1;

		it = mp.find(a - it->first);
		if (it != mp.end()) {
			q.push(it->first);
		}
	}

	cout << "YES\n";
	for (int i = 0; i < n; i++) cout << ans[i] << ' '; cout << '\n';
	return 0;
}