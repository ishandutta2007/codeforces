#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 5e5 + 7;
int n, m;
vi e[N];
int fa[N], dep[N], dfn[N], en[N], up[20][N], mn[20][N], mp[N], lg[N], idt;
void dfs (int x) {
	++idt, dfn[x] = idt, mn[0][idt] = x, mp[idt] = x;
	for (const int &v : e[x]) if(v != fa[x]) 
		fa[v] = x, dep[v] = dep[x] + 1, dfs (v), ++idt, mn[0][idt] = x, mp[idt] = x;
	en[x] = idt;
}
void ST () {
	L(i, 2, idt) lg[i] = lg[i >> 1] + 1;
	L(i, 1, 19) L(j, 1, idt - (1 << i) + 1) 
		mn[i][j] = dep[mn[i - 1][j]] < dep[mn[i - 1][j + (1 << (i - 1))]] ? mn[i - 1][j] : mn[i - 1][j + (1 << (i - 1))];
}
inline int lca (int x, int y) {
	x = dfn[x], y = dfn[y];
	if(x > y) swap(x, y);
	int p = lg[y - x + 1];
	return dep[mn[p][x]] < dep[mn[p][y - (1 << p) + 1]] ? mn[p][x] : mn[p][y - (1 << p) + 1];
}
inline int dis (int x, int y) {
	return dep[x] + dep[y] - 2 * dep[lca(x, y)];
}
int UP (int x, int k) {
	R(i, 19, 0) if(k >> i & 1) x = up[i][x];
	return max (x, 1);
}

template < int N > struct fenwt {
	using F = int ;
	F a[N + 1];
	void add (int x, F w) {
		for (; x <= N; x += x & -x) a[x] += w;
	}
	F query (int x) {
		F ret = 0;
		for (; x; x -= x & -x) ret += a[x];
		return ret;
	}
	F get (int l, int r) {
		if(l > r) return 0;
		return query (r) - query (l - 1);
	}
} ;
fenwt < N > F;

namespace DIV {
	int cur[N * 20], *pool = cur;
	struct fe {
		int n, *arr;
		void init (int x) {
			n = x, arr = pool, pool += n + 1;
		}
		inline void add (int x, int w) {
			x += 1;
			for (; x <= n; x += x & -x) 
				arr[x] += w;
		}
		inline int query (int x) {
			if(x < 0) return 0;
			x += 1;
			x = min(x, n);
			int ret = 0;
			for (; x; x -= x & -x) 
				ret += arr[x];
			return ret;
		}
	} s[N], g[N];
	int fn, rt, rtv, siz[N], vis[N], Fa[N];
	void si (int x, int fa) {
		siz[x] = 1;
		for(const int &v : e[x]) if(v != fa && !vis[v]) si (v, x), siz[x] += siz[v];
	}
	void frt (int x, int fa) {
		int mx = fn - siz[x];
		for(const int &v : e[x]) if(v != fa && !vis[v]) frt (v, x), mx = max(mx, siz[v]);
		if(mx < rtv) rt = x, rtv = mx;
	}
	int divide (int x) {
		rtv = 1e9, rt = -1, si (x, -1), fn = siz[x], frt (x, -1), vis[rt] = 1, s[rt].init(siz[x]), g[rt].init(siz[x]);
		int cur = rt;
		for (const int &v : e[rt]) if(!vis[v]) Fa[divide (v)] = cur;
		return cur;
	}
	void init () {
		divide (1);
	}
	void add (int x, int w) {
		int cnt = 0;
		for(int u = x; u; u = Fa[u]) g[u].add(dis(u, x), w), cnt += 1;
		if(cnt > 20) assert (false);
		for(int u = x; Fa[u]; u = Fa[u]) s[u].add(dis(Fa[u], x) - 1, w);
	}
	int query(int x, int k) {
		int sum = g[x].query (k);
		for(int u = x, len; Fa[u]; u = Fa[u]) len = dis(x, Fa[u]), sum -= s[u].query (k - len - 1), sum += g[Fa[u]].query (k - len);
		return sum;
	}
};

priority_queue < pair < int, int > > q, dq;

int main () {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0); 
	cin >> n >> m;
//	n = m = 2e5;
	L(i, 1, n - 1) {
		int u = i, v = i + 1;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs (1);
	ST ();
	L(i, 1, n) up[0][i] = fa[i];
	L(i, 1, 19) L(j, 1, n) up[i][j] = up[i - 1][up[i - 1][j]];
	DIV :: init ();
	int all = 0;
	while (m--) {
		int op, u, v, d, w = 1;
		cin >> op;
		if(op == 3) {
			while (sz(dq) && dq.top() == q.top()) dq.pop(), q.pop();
			cin >> d;
			u = max(UP(q.top().second, d), 1);
			int ur = max(UP(u, d), 1);
			int ok = F.get (dfn[ur], en[ur]) + DIV :: query (u, d);
			if(ok == all) cout << "Yes\n";
			else cout << "No\n";
		} else {
			cin >> u >> v;
			int lc = lca(u, v);
			if(op == 2) w = -1, dq.push ({dep[lc], lc});
			else q.push ({dep[lc], lc});
			all += w;
			F.add(dfn[u], w), F.add(dfn[v], w);
			F.add(dfn[lc], -w), F.add(dfn[lc], -w);
			DIV :: add (lc, w);
		}
	}
	return 0;
}