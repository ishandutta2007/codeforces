#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;
const int N = 1e5 + 5;

struct Line {
	mutable ll k, m, p;
	bool operator<(const Line& o) const { return k < o.k; }
	bool operator<(ll x) const { return p < x; }
};

struct CHT : multiset<Line, less<>> {
	// (for doubles, use inf = 1/.0, div(a,b) = a/b)
	static const ll inf = LLONG_MAX;
	ll div(ll a, ll b) { // floored division
		return a / b - ((a ^ b) < 0 && a % b); }
	bool isect(iterator x, iterator y) {
		if (y == end()) return x->p = inf, 0;
		if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}
	void add(ll k, ll m) {
		auto z = insert({k, m, 0}), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p)
			isect(x, erase(y));
	}
	ll query(ll x) {
		assert(!empty());
		auto l = *lower_bound(x);
		return l.k * x + l.m;
	}
};

int n, a[N], b[N];
ll dp[N];
vector<int> g[N];
CHT cht[N];

void merge(int i, int j) {
	if (cht[i].size() < cht[j].size()) {
		cht[i].swap(cht[j]);
	}
	for (auto& [k, m, p] : cht[j]) {
		cht[i].add(k, m);
	}
}

void dfs(int x, int p) {
	for (int i : g[x]) {
		if (i == p) continue;
		dfs(i, x);
		merge(x, i);
	}
	if (!cht[x].empty()) {
		dp[x] = -cht[x].query(a[x]);
	} else {
		dp[x] = 0;
	}
	cht[x].add(-b[x], -dp[x]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];

	for (int i = 1, u, v; i < n; i++) {
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	dfs(1, 0);
	for (int i = 1; i <= n; i++) {
		cout << dp[i] << ' ';
	}
	cout << '\n';
	return 0;
}