#include <bits/stdc++.h>
using namespace std;

struct RMQ {
	typedef int T;
	static constexpr T unit = 0;
	T f(T a, T b) { return a+b; }
	vector<T> s; int n;
	RMQ(int n = 0, T def = unit) : s(2*n, def), n(n) {}
	void update(int pos, T val) {
		for (s[pos += n] = val; pos /= 2;)
			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
	}
	T query(int b, int e) {
		T ra = unit, rb = unit;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = f(ra, s[b++]);
			if (e % 2) rb = f(s[--e], rb);
		}
		return f(ra, rb);
	}
} st(0);

struct UF {
	vector<int> e;
	UF(int n) : e(n, -1) {}
	bool sameSet(int a, int b) { return find(a) == find(b); }
	int size(int x) { return -e[find(x)]; }
	int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
	bool join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return false;
		if (e[a] > e[b]) swap(a, b);
		e[a] += e[b]; e[b] = a;
		return true;
	}
};

const int MAXN = 300001;

int n, q, t, in[MAXN], out[MAXN], sz[MAXN], nxt[MAXN], h[MAXN], par[MAXN], x[MAXN], vs[MAXN];
vector<int> g[MAXN];
map<pair<int, int>, int> mp;

void dfs_sz(int v, int prv = -1) {
	sz[v] = 1; vs[v] = 1;
	if (prv != -1) {
		h[v] = h[prv] + 1;
		x[v] = x[prv] ^ mp[{prv, v}];
	}
	for (auto &u: g[v]) {
		if (u == prv) continue;
		dfs_sz(u, v);
		sz[v] += sz[u];
		if (sz[u] > sz[g[v][0]]) {
			swap(u, g[v][0]);
		}
	}
}
 
void dfs_hld(int v, int prv = -1) {
	in[v] = t++;
	par[v] = prv;
	for (auto u: g[v]) {
		if (u == prv) continue;
		nxt[u] = (u == g[v][0] ? nxt[v] : u);
		dfs_hld(u, v);
	}
	out[v] = t;
}

int query(int u, int v) {
	int ans = 0;
	while (true) {
		if (nxt[u] == nxt[v]) {
			if (in[u] > in[v]) swap(u, v);
			ans += st.query(in[u], in[v] + 1);
			ans -= st.query(in[u], in[u] + 1);
			break;
		}

		if (h[nxt[u]] > h[nxt[v]]) {
			// lift u up
			ans += st.query(in[nxt[u]], in[u] + 1);
			u = par[nxt[u]];
		} else {
			// lift v up
			ans += st.query(in[nxt[v]], in[v] + 1);
			v = par[nxt[v]];
		}
	}
	return ans;
}

void update(int u, int v) {
	if (h[u] < h[v]) swap(u, v);

	while (h[u] != h[v]) {
		st.update(in[u], 1);
		u = par[u];
	}

	while (u != v) {
		st.update(in[u], 1);
		u = par[u];

		st.update(in[v], 1);
		v = par[v];
	}
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n >> q; UF d(n);
	vector<tuple<int, int, int>> ques;
	for (int i = 0; i < q; i++) {
		int u, v, w; cin >> u >> v >> w; u--, v--;
		ques.emplace_back(u, v, w);
		if (d.join(u, v)) {
			g[u].push_back(v);
			g[v].push_back(u);
			mp[{u, v}] = mp[{v, u}] = w;
		}
	}

	for (int i = 0; i < n; i++) {
		if (!vs[i]) {
			dfs_sz(i);
			dfs_hld(i);
		}
	}

	st = RMQ(n);
	
	UF d2(n);
	for (auto [u, v, w]: ques) {
		if (d2.join(u, v)) {
			cout << "YES\n";
		} else {

			if (query(u, v)) {
				cout << "NO\n";
			} else {
				if ((x[u]^x[v]^w) == 1) {
					cout << "YES\n";
					update(u, v);
				} else {
					cout << "NO\n";
				}
			}
		}
	}

	return 0;
}