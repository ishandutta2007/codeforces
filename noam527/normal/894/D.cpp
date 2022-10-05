#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
typedef long long ll;
using namespace std;

int n, q, par[2];
vector<int> l, r, p;
vector<vector<int>> m;
vector<vector<ll>> ps;

void build(int v = 1) {
	m[v].push_back(0);
	int p1 = 0, p2 = 0;
	if (l[v]) {
		build(2 * v);
		if (r[v]) {
			build(2 * v + 1);
			while (p1 < m[2 * v].size() && p2 < m[2 * v + 1].size())
				if (m[2 * v][p1] + l[v] < m[2 * v + 1][p2] + r[v])
					m[v].push_back(m[2 * v][p1++] + l[v]);
				else
					m[v].push_back(m[2 * v + 1][p2++] + r[v]);
			while (p1 < m[2 * v].size())
				m[v].push_back(m[2 * v][p1++] + l[v]);
			while (p2 < m[2 * v + 1].size())
				m[v].push_back(m[2 * v + 1][p2++] + r[v]);
		}
		else {
			for (auto &i : m[2 * v]) m[v].push_back(i + l[v]);
		}
	}
	else {
		if (r[v]) {
			for (auto &i : m[2 * v + 1]) m[v].push_back(i + r[v]);
		}
	}
	ps[v] = vector<ll>(m[v].size());
	ps[v][0] = m[v][0];
	for (int i = 1; i < m[v].size(); i++)
		ps[v][i] = ps[v][i - 1] + m[v][i];
}

ll single(int v, int h) {
	if (h < 0 || v > n || v < 1) return 0;
	int lo = 0, hi = m[v].size() - 1, mid;
	while (lo < hi) {
		mid = (lo + hi + 1) / 2;
		if (m[v][mid] < h) lo = mid;
		else hi = mid - 1;
	}
	return (ll)(lo + 1) * h - ps[v][lo];
}

ll query(int v, int h) {
	ll rtn = single(v, h);
	while (v != 1) {
		h -= p[v];
		if (h > 0) rtn += h;
		if (v & 1) rtn += single(v - 1, h - l[v / 2]);
		else rtn += single(v + 1, h - r[v / 2]);
		v /= 2;
	}
	return rtn;
}

int main() {
	fast;
	cin >> n >> q;
	l.resize(n + 1, 0), r.resize(n + 1, 0), p.resize(n + 1, 0), m.resize(n + 1), ps.resize(n + 1); // fuck ton of time?
	for (int i = 1, x; i < n; i++) {
		cin >> x;
		p[i + 1] = x;
		if (i & 1) l[i / 2 + 1] = x;
		else r[i / 2] = x;
	}
	build();
	while (q--) {
		cin >> par[0] >> par[1];
		cout << query(par[0], par[1]) << endl;
	}
}