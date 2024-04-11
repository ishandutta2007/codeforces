#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;
const int N = 1e5 + 5;

int n, to[N], from[N], d[N];
ll cnt[N];

int _p[N], _r[N];

int find(int x) {
	return x == _p[x] ? x : _p[x] = find(_p[x]);
}

void merge(int x, int y) {
	int l1 = find(x), l2 = find(y);
	if (_r[l1] >= _r[l2]) {
		_p[l2] = l1;
		_r[l1] += _r[l2];
	} else {
		_p[l1] = l2;
		_r[l2] += _r[l1];
	}
}

int sz[N];
vector<int> comp_edges, temp[N];

void add_edge(int i) {
	temp[to[i]].push_back(i);
	temp[from[i]].push_back(i);
}

void dfs(int x, int p) {
	sz[x] = _r[x];
	for (int i : temp[x]) {
		int nxt = to[i] ^ from[i] ^ x;
		if (nxt == p) continue;
		dfs(nxt, x);
		sz[x] += sz[nxt];
		cnt[i] = x;
		comp_edges.push_back(i);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	iota(_p, _p + N, 0);
	for (int i = 0; i < N; i++) _r[i] = 1;

	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		cin >> to[i] >> from[i] >> d[i];
		--to[i];
		--from[i];
	}

	map<int, vector<int>> mp;
	for (int i = 0; i < n - 1; i++) {
		mp[d[i]].push_back(i);
	}

	for (auto it = mp.begin(); it != mp.end(); it++) {
		vector<int> v;
		for (int i : it->second) {
			to[i] = find(to[i]);
			from[i] = find(from[i]);
			v.push_back(to[i]);
			v.push_back(from[i]);
			add_edge(i);
		}

		for (int x : v) {
			if (!sz[x]) {
				comp_edges.clear();
				dfs(x, -1);
				for (int i : comp_edges) {
					int nxt = to[i] ^ from[i] ^ cnt[i];
					cnt[i] = 2ll * sz[nxt] * (sz[x] - sz[nxt]);
				}
			}
		}

		for (int i : it->second) {
			merge(to[i], from[i]);
		}

		for (int x : v) {
			temp[x].clear();
			sz[x] = 0;
		}
	}

	vector<int> ans = {0};

	for (int i = 1; i < n - 1; i++) {
		if (cnt[i] > cnt[ans.back()]) {
			ans.clear();
			ans.push_back(i);
		} else if (cnt[i] == cnt[ans.back()]) {
			ans.push_back(i);
		}
	}

	cout << cnt[ans.back()] << ' ' << ans.size() << '\n';
	for (int i : ans) cout << i + 1 << ' '; cout << '\n';
	return 0;
}