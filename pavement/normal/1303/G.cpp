#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#ifdef _WIN32
#define getchar_unlocked _getchar_nolock
#endif
#define int long long
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define ppb pop_back
#define eb emplace_back
#define g0(a) get<0>(a)
#define g1(a) get<1>(a)
#define g2(a) get<2>(a)
#define g3(a) get<3>(a)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using db = double;
using ll = long long;
using ld = long double;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using iiii = tuple<int, int, int, int>;
template<class key, class value = null_type, class cmp = less<key> >
using ordered_set = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;

int N, ans, cent, tot, A[150005], sz[150005];
bool vis[150005];
vector<int> adj[150005];
vector<ii> down, up;

struct Line {
    mutable int k, m, p;
    bool operator<(const Line& o) const { return k < o.k; }
    bool operator<(int x) const { return p < x; }
};
struct LineContainer : multiset<Line, less<>> {
    // for doubles, use inf = 1/.0, div(a,b) = a / b
    static const int inf = 1e16;
    int div(int a, int b) { // floored division
        return a / b - ((a ^ b) < 0 && a % b);
    }
    bool isect(iterator x, iterator y) {
        if (y == end()) return x->p = inf, 0;
        if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
        else x->p = div(y->m - x->m, x->k - y->k);
        return x->p >= y->p;
    }
    void add(int k, int m) { // insert y = kx + m
        auto z = insert({k, m, 0}), y = z++, x = y;
        while (isect(y, z)) z = erase(z);
        if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
        while ((y = x) != begin() && (--x)->p >= y->p) isect(x, erase(y));
    }
    int query(int x) { // max query
        assert(!empty());
        auto l = *lower_bound(x);
        return l.k * x + l.m;
    }
};

int get_sz(int n, int e = -1) {
	sz[n] = 1;
	for (auto u : adj[n]) if (u != e && !vis[u])
		sz[n] += get_sz(u, n);
	return sz[n];
}

void get_cent(int n, int e = -1) {
	int m = tot - sz[n];
	for (auto u : adj[n]) if (u != e && !vis[u]) {
		m = max(m, sz[u]);
		get_cent(u, n);
	}
	if (m <= tot / 2) cent = n;
}

void get_up(int n, int e, int d, int sps, int sum) {
	sps += A[n] * d;
	sum += A[n];
	for (auto u : adj[n]) if (u != e && !vis[u])
		get_up(u, n, d + 1, sps, sum);
	up.eb(sps, sum);
}

void get_down(int n, int e = -1, int sps = 0, int prv = 0, int len = 0) {
	sps += prv + A[n];
	prv += A[n];
	len++;
	down.eb(sps, len);
	for (auto u : adj[n]) if (u != e && !vis[u])
		get_down(u, n, sps, prv, len);
}

void decomp(int n) {
	get_sz(n);
	tot = sz[n];
	get_cent(n);
	vis[cent] = 1;
	int _cent = cent;
	LineContainer up_ch, down_ch;
	up_ch.add(A[_cent], A[_cent]);
	down_ch.add(0, 0);
	for (auto u : adj[_cent])
		if (!vis[u]) {
			up.clear();
			down.clear();
			get_up(u, _cent, 2, A[_cent], A[_cent]);
			get_down(u);
			for (auto i : up) // stores [sps, sum]
				ans = max(ans, down_ch.query(i.second) + i.first);
			for (auto i : down) // stores [sps, len]
				ans = max(ans, up_ch.query(i.second) + i.first);
			for (auto i : up)
				up_ch.add(i.second, i.first);
			for (auto i : down)
				down_ch.add(i.second, i.first);
		}
	for (auto u : adj[_cent])
		if (!vis[u]) decomp(u);
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 1, u, v; i < N; i++) {
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
		ans = max(ans, A[i]);
	}
	decomp(1);
	cout << ans << '\n';
}