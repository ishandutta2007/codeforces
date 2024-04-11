#include <bits/stdc++.h>
typedef long long ll;
typedef long double ldb;
const int md = 998244353;
const ll inf = 3e18;
const int OO = 1;
using namespace std;

const int N = 200005;

struct edge {
	int to, mul, div;
	edge() {}
	edge(int tt, int mm, int dd) {
		to = tt;
		mul = mm;
		div = dd;
	}
};

int sieve[N] = {};

int n;
vector<vector<edge>> g;
int in[N], out[N];
int tim;

vector<pair<int, int>> eve[N]; // eve[i] = events for prime i
set<int> fix;

void prep() {
	sieve[1] = 1;
	for (int i = 2; i < N; i++) {
		if (sieve[i] == 0) {
			sieve[i] = i;
			if (ll(i) * i >= N) continue;
			for (int j = i * i; j < N; j += i)
				if (sieve[j] == 0)
					sieve[j] = i;
		}
	}
}

vector<int> factor(int x) {
	vector<int> res;
	while (x > 1) {
		res.push_back(sieve[x]);
		x /= sieve[x];
	}
	return res;
}
vector<pair<int, int>> merge_factors(int x, int y) {
	auto f1 = factor(x), f2 = factor(y);
	sort(f1.begin(), f1.end());
	sort(f2.begin(), f2.end());
	vector<pair<int, int>> res;
	int p1 = 0, p2 = 0;
	while (p1 < f1.size() || p2 < f2.size()) {
		int add, mult;
		if (p1 == f1.size()) {
			add = f2[p2++];
			mult = -1;
		}
		else if (p2 == f2.size()) {
			add = f1[p1++];
			mult = 1;
		}
		else if (f1[p1] < f2[p2]) {
			add = f1[p1++];
			mult = 1;
		}
		else {
			add = f2[p2++];
			mult = -1;
		}
		if (!res.size() || res.back().first != add)
			res.emplace_back(add, mult);
		else
			res.back().second += mult;
	}
	return res;
}

void dfs(int v, int prev) {
	in[v] = tim++;
	for (const auto &i : g[v]) {
		if (i.to != prev) {
			dfs(i.to, v);
			auto factors = merge_factors(i.mul, i.div);
			for (auto &f : factors) {
				if (f.second != 0) {
					fix.insert(f.first);
					eve[f.first].emplace_back(in[i.to], f.second);
					eve[f.first].emplace_back(out[i.to], -f.second);
				}
			}
		}
	}
	out[v] = tim++;
}

ll pw(ll b, ll e) {
	ll res = 1;
	while (e) {
		if (e & 1) res = res * b % md;
		e /= 2, b = b * b % md;
	}
	return res;
}
ll inv(int x) {
	return pw(x, md - 2);
}

void dfs2(int v, int prev, ll val, ll &realans) {
	realans = (realans + val) % md;
	for (const auto &i : g[v]) {
		if (i.to != prev) {
			ll newval = val * i.mul % md * inv(i.div) % md;
			dfs2(i.to, v, newval, realans);
		}
	}
}

void solve() {
	tim = 0;
	fix.clear();

	cin >> n;
	g.resize(n);
	for (auto &i : g) i.clear();
	for (int i = 0, u, v, x, y; i < n - 1; i++) {
		cin >> u >> v >> x >> y;
		--u, --v;
		g[u].push_back(edge(v, y, x));
		g[v].push_back(edge(u, x, y));
	}
	dfs(0, 0);
	for (int i : fix)
		sort(eve[i].begin(), eve[i].end());
	ll ans = 1;
	for (int i : fix) {
		int mn = 0, cursum = 0;
		for (const auto &x : eve[i]) {
			cursum += x.second;
			mn = min(mn, cursum);
		}
		if (mn < 0)
			ans = ans * pw(i, -mn) % md;
	}
	ll realans = 0;
	dfs2(0, 0, ans, realans);
	cout << realans << '\n';

	for (int i : fix)
		eve[i].clear();
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	prep();
	int tst = 1;
	cin >> tst;
	while (tst--) solve();
}