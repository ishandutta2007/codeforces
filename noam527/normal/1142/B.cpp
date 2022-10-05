#include <bits/stdc++.h>
#define CHECK cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 1e18;
const int OO = 0;
const int OOO = 1;
using namespace std;

int n, m, q;
vector<int> p, mp;
vector<int> a, to;
vector<int> pos[200005];

vector<vector<int>> g;
vector<int> vis;

vector<pair<int, int>> s;

void dfs(int v, vector<int> &st) {
	if (OO) {
		cout << "dfs " << v << '\n';
		for (const auto &i : st) cout << i << " "; cout << '\n';
	}
	if (st.size() >= n - 1) s.emplace_back(v, st[(int)st.size() - n + 1]);
	vis[v] = 1;
	st.push_back(v);
	for (const auto &i : g[v])
		dfs(i, st);
	st.pop_back();
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m >> q;
	if (n == 1) {
		while (q--) cout << 1;
		return 0;
	}
	p.resize(n);
	mp.resize(n);
	a.resize(m);
	to.resize(m, -1);
	g.resize(m);
	vis.resize(m, 0);
	for (int i = 0; i < n; i++) {
		cin >> p[i];
		--p[i];
		mp[p[i]] = i;
	}
	p.push_back(p[0]);
	for (int i = 0; i < m; i++) {
		cin >> a[i];
		--a[i];
		pos[a[i]].push_back(i);
	}
	for (int i = 0; i < m; i++) {
		int val = a[i];
		val = mp[a[i]];
		val = p[val + 1];
		int ind = lower_bound(pos[val].begin(), pos[val].end(), i) - pos[val].begin();
		if (ind < pos[val].size()) to[i] = pos[val][ind];
		if (OO) cout << "to " << i << " = " << to[i] << '\n';
		if (to[i] != -1) g[to[i]].push_back(i);
	}
	vector<int> st;
	for (int i = m - 1; i >= 0; i--)
		if (!vis[i]) dfs(i, st);

	if (OO) {
		for (const auto &i : s) cout << i.first << " " << i.second << '\n';
	}

	vector<pair<int, int>> ss;
	sort(s.begin(), s.end());
	for (auto &i : s) {
		while (ss.size() && i.second <= ss.back().second) ss.pop_back();
		ss.push_back(i);
	}

	if (OO) {
		cout << "ss\n";
		for (const auto &i : s) cout << i.first << " " << i.second << '\n';
	}

	while (q--) {
		int l, r;
		cin >> l >> r;
		--l, --r;
		pair<int, int> sea = { l, -1 };
		int ind = lower_bound(ss.begin(), ss.end(), sea) - ss.begin();
		if (ind < ss.size() && ss[ind].second <= r) cout << 1;
		else cout << 0;
	}
}