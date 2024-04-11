#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;
const int N = 2e5 + 5;

int n, d[N], p[N], dist[N], mn[N];
vector<int> g[N];

void dfs(int x) {
	vector<int> mns;
	for (int i : g[x]) {
		if (i == p[x]) continue;
		p[i] = x;
		d[i] = 1 + d[x];
		dfs(i);
		mns.push_back(mn[i] + 1);
	}

	if (mns.size() == 0) {
		dist[x] = mn[x] = 0;
	} else if (mns.size() == 1) {
		dist[x] = mn[x] = mns.front();
	} else {
		sort(mns.begin(), mns.end());
		auto it = mns.end();
		if (*(--it) == *(--it)) {
			dist[x] = mns.back() + 1;
			mn[x] = mns.front();
		} else {
			if (x != 1) {
				dist[x] = mns.back() + 1;
				mn[x] = mns.front();
			} else {
				dist[x] = mns.back();
				mn[x] = mns.back();
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			g[i].clear();
		}

		for (int i = 1, u, v; i < n; i++) {
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}

		dfs(1);
		cout << *max_element(dist, dist + n + 1) << '\n';
	}
	return 0;
}