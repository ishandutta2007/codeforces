#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back

using namespace std;

int read() {
    const int M = 1e6;
    static streambuf* in = cin.rdbuf();
    #define gc (p1 == p2 && (p2 = (p1 = buf) + in -> sgetn(buf, M), p1 == p2) ? -1 : *p1++)
    static char buf[M], *p1, *p2;
    int c, r = 0;
    while((c = gc) < 48);
    while(c > 47) r = r * 10 + (c & 15), c = gc;
    return r;
}
void wrt(int x) {
    static streambuf* out = cout.rdbuf();
    #define pc out -> sputc
    static char c[11]; int sz = 0;
    do c[++sz] = x % 10, x /= 10; while(x);
    while(sz) pc(c[sz--] + 48);
    pc(32);
}

const int N = 4.4e5 + 100;

int n, m, k, idx, S, dfn[N], scc[N], s[N], tp, ans[N / 20];
struct { int v, n; } e[N * 3];
int eid, he[N];

inline void add(int u, int v) { e[++eid] = {v, he[u]}, he[u] = eid; }

int dfs(int u) {
	int low = dfn[u] = ++idx;
	s[++tp] = u;
	for(int i = he[u]; i; i = e[i].n) {
		int v = e[i].v;
		if(!dfn[v]) low = min(low, dfs(v));
		else if(!scc[v]) low = min(low, dfn[v]);
	}
	if(low == dfn[u]) {
		int v; S++;
		do scc[v = s[tp--]] = S; while(v != u);
	}
	return low;
}
inline int id(int x, int vx) {
	return x * (k + 1) + vx + 1;
}
inline void ban(int x, int vx, int a, int y, int vy, int b) {
	int u = id(x, vx) << 1, v = id(y, vy) << 1;
	add(u + a, v + !b), add(v + b, u + !a);
}
void solve() {
	n = read(), m = read(), k = read();
	idx = S = eid = 0;
	rep(i, 2, id(n, k) << 1 | 1) he[i] = dfn[i] = scc[i] = 0;
	rep(i, 1, n) rep(j, 0, k) {
		if(i > 1) ban(i - 1, j, 0, i, j, 1);
		if(j) ban(i, j, 0, i, j - 1, 1);
	}
	ban(1, 0, 1, 1, 0, 1), ban(n, k, 0, n, k, 0);
	int t, u, v, x;
	while(m--) {
		t = read(), u = read(), v = read();
		if(t == 1) ban(u, v, 1, u, v - 1, 0);
		if(t == 2) {
			x = read();
			rep(i, max(0, x - 1 - k), min(x - 1, k)) ban(u, i, 0, v, x - 1 - i, 0);
		}
		if(t == 3) {
			x = read();
			rep(i, max(1, x - 1 - k), min(x - 2, k)) ban(u, i, 1, v, x - 1 - i, 1);
		}
	}
	rep(i, 2, id(n, k) << 1 | 1) if(!dfn[i]) dfs(i);
	rep(i, 1, n) rep(j, 0, k) {
		int u = id(i, j) << 1;
		if(scc[u] == scc[u + 1]) return cout << "-1\n", void();
		if(scc[u] < scc[u + 1]) ans[i] = j + 1;
	}
	rep(i, 1, n) wrt(ans[i]);
	cout << '\n';
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int T;
	cin >> T;
	while(T--) solve();
}