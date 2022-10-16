#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

bool dfs2(int a, int L, vector<vi>& g, vi& btoa, vi& A, vi& B) {
	if (A[a] != L) return 0;
	A[a] = -1;
	for (int b : g[a]) if (B[b] == L + 1) {
		B[b] = 0;
		if (btoa[b] == -1 || dfs2(btoa[b], L + 1, g, btoa, A, B))
			return btoa[b] = a, 1;
	}
	return 0;
}

int hopcroftKarp(vector<vi>& g, vi& btoa) {
	int res = 0;
	vi A(g.size()), B(btoa.size()), cur, next;
	for (;;) {
		fill(all(A), 0);
		fill(all(B), 0);
		/// Find the starting nodes for BFS (i.e. layer 0).
		cur.clear();
		for (int a : btoa) if(a != -1) A[a] = -1;
		rep(a,0,sz(g)) if(A[a] == 0) cur.push_back(a);
		/// Find all layers using bfs.
		for (int lay = 1;; lay++) {
			bool islast = 0;
			next.clear();
			for (int a : cur) for (int b : g[a]) {
				if (btoa[b] == -1) {
					B[b] = lay;
					islast = 1;
				}
				else if (btoa[b] != a && !B[b]) {
					B[b] = lay;
					next.push_back(btoa[b]);
				}
			}
			if (islast) break;
			if (next.empty()) return res;
			for (int a : next) A[a] = lay;
			cur.swap(next);
		}
		/// Use DFS to scan for augmenting paths.
		rep(a,0,sz(g))
			res += dfs2(a, 0, g, btoa, A, B);
	}
}

vi num, st;
vector<vector<pii>> ed;
int Time;

set<pii> actual;

template<class F>
int dfs(int at, int par, F& f) {
	int me = num[at] = ++Time, e, y, top = me;
	for (auto pa : ed[at]) if (pa.second != par) {
		tie(y, e) = pa;
		if (num[y]) {
			top = min(top, num[y]);
			if (num[y] < me)
				st.push_back(e);
		} else {
			int si = sz(st);
			int up = dfs(y, e, f);
			top = min(top, up);
			if (up == me) {
				st.push_back(e);
				f(vi(st.begin() + si, st.end()));
				st.resize(si);
			}
			else if (up < me) st.push_back(e);
			else {
				// this is a bridge
				actual.insert({y, at});
			}
		}
	}
	return top;
}

template<class F>
void bicomps(F f) {
	num.assign(sz(ed), 0);
	rep(i,0,sz(ed)) if (!num[i]) dfs(i, -1, f);
}

int n, m;

void solve1() {
	// identify cactus and delete them
	actual.clear();
	int eid = 0; ed.resize(n);
	for (int i = 0; i < n; i++) {
		ed[i].clear();
	}
	st.clear(); Time = 0;
	while (m--) {
		int s, p; cin >> s >> p; p--;
		while (--s) {
			int x; cin >> x; x--;
			ed[p].emplace_back(x, eid);
			ed[x].emplace_back(p, eid++);
			p = x;
		}
	}

	bicomps([&](const vi& edgelist) {});
}

vector<int> adj[100001];
int vis[100001], unmatch[100001];
vector<pii> ans;

void dfs1(int now) {
	vis[now] = 1;
	if (adj[now].size() % 2) {
		unmatch[now] = now;
	}

	for (int u: adj[now]) {
		if (vis[u]) continue;
		dfs1(u);

		if (unmatch[u] != -1) {
			if (unmatch[now] != -1) {
				ans.emplace_back(unmatch[u], unmatch[now]);
				unmatch[now] = -1;
			} else {
				unmatch[now] = unmatch[u];
			}
		}
	}
}

vector<int> adjj[100001];
int col[100001];

void dfsc(int now, int c) {
	col[now] = c;
	for (int u: adjj[now]) {
		if (col[u] == -1) {
			dfsc(u, 1-c);
		}
	}
}

void solve2() {
	for (int i = 0; i < n; i++) {
		adj[i].clear(); vis[i] = 0;
		unmatch[i] = -1;

		adjj[i].clear();
		col[i] = -1;
	}

	vector<int> deg(n);
	for (auto [u, v]: actual) {
		deg[u]++; deg[v]++;

		adjj[u].push_back(v);
		adjj[v].push_back(u);
	}

	for (int i = 0; i < n; i++) {
		if (col[i] == -1) dfsc(i, 0);
	}

	vector<vi> g(n);
	for (auto [u, v]: actual) {
		if ((deg[u] % 2) && (deg[v] % 2)) {
			if (col[u]) swap(u, v);
			g[u].push_back(v);
		}
	}
	vi btoa(n, -1); 
	hopcroftKarp(g, btoa);

	for (auto [u, v]: actual) {
		if (btoa[u] != v && btoa[v] != u) {
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
	}
	
	ans.clear();
	for (int i = 0; i < n; i++) {
		if (!vis[i]) dfs1(i);
	}

	cout << ans.size() << '\n';
	for (auto [u, v]: ans) {
		cout << u+1 << ' ' << v+1 << '\n';
	}
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	while (cin >> n >> m) {
		if (n == 0 && m == 0) break;
		solve1();
		solve2();
	}

	return 0;
}