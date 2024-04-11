#include <bits/stdc++.h>
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 3e18;
const int OO = 1;
using namespace std;

struct edge {
	int to;
	ll w;
	edge(int tt = 0, ll ww = 0) {
		to = tt;
		w = ww;
	}
	bool operator < (const edge &a) const {
		return w > a.w;
	}
};

int n;
vector<pair<ll, ll>> x;
vector<ll> a, c;
vector<vector<edge>> g;

void solve() {
	cin >> n;
	x.resize(n);
	a.resize(n), c.resize(n);
	g.resize(n);

	for (auto &i : x) cin >> i.first >> i.second;
	sort(x.begin(), x.end());
	for (int i = 0; i < n; i++) {
		a[i] = x[i].first, c[i] = x[i].second;
	}
	for (int i = 0; i < n - 1; i++) {
		g[i + 1].push_back(edge(i, 0));
		g[i].push_back(edge(i + 1, a[i + 1] - a[i]));
	}
	for (int i = 0; i < n; i++) {
		int big = upper_bound(a.begin(), a.end(), a[i] + c[i]) - a.begin();
		if (big < n)
			g[i].push_back(edge(big, a[big] - (a[i] + c[i])));
		if (big - 1 > i)
			g[i].push_back(edge(big - 1, 0));
	}

	priority_queue<edge> q;
	q.push(edge(0, 0));
	vector<ll> dist(n, inf);
	while (q.size()) {
		edge x = q.top();
		q.pop();
		if (dist[x.to] != inf) continue;
		dist[x.to] = x.w;
		for (const auto &i : g[x.to]) {
			if (dist[i.to] == inf)
				q.push(edge(i.to, x.w + i.w));
		}
	}
	ll ans = 0;
	for (int i = 0; i < n; i++) ans += c[i];
	ans += dist[n - 1];
	cout << ans << '\n';
}

int main() {
	//ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
//	cin >> tst;
	while (tst--) solve();
}