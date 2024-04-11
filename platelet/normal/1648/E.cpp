#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define eb emplace_back
#define all(x) x.begin(), x.end()
#pragma GCC target("lzcnt")

using namespace std;
using ll = long long;

const int N = 2e5 + 5;

int read() {
    const int M = 1e6;
    static streambuf* in = cin.rdbuf();
    #define gc (p1 == p2 && (p2 = (p1 = buf) + in -> sgetn(buf, M), p1 == p2) ? -1 : *p1++)
    static char buf[M], *p1, *p2;
    int c = gc, r = 0;
    while(c < 48) c = gc;
    while(c > 47) r = r * 10 + (c & 15), c = gc;
    return r;
}
void wrt(int x, int ch) {
    static streambuf* out = cout.rdbuf();
    #define pc out -> sputc
    static char c[11]; int sz = 0;
    do c[++sz] = x % 10, x /= 10; while(x);
    while(sz) pc(c[sz--] + 48);
    pc(ch);
}
int n, m, a[N], b[N], fa[N], rk[N];
vector<pair<int, int>> G[N];
int find(int x) {
	if(fa[x] < 0) return x;
	int f = find(fa[x]);
	return rk[x] += rk[fa[x]], fa[x] = f;
}
struct MST {
	vector<tuple<int, int, int>> e;
	int a[N], b[N], pre[N], mx[18][N];
	void Kru() {
		sort(all(e));
		rep(i, 1, n) fa[i] = -1, rk[i] = 0;
		for(auto [w, u, v] : e) {
			u = find(u), v = find(v);
			if(u == v) continue;
			if(fa[u] > fa[v]) swap(u, v);
			rk[v] = -fa[u], pre[v] = w;
			fa[u] += fa[v], fa[v] = u;
		}
		rep(i, 1, n) find(i), a[b[i] = rk[i] + 1] = i, mx[0][b[i]] = pre[i];
		rep(i, 1, 17) rep(j, 1 << i, n)
			mx[i][j] = max(mx[i - 1][j], mx[i - 1][j - (1 << i - 1)]);
	}
	int qry(int l, int r) {
		if(l > r) swap(l, r);
		int t = __lg(r - l);
		return max(mx[t][r], mx[t][l + (1 << t)]);
	}
} A, B;
void solve() {
    n = read(), m = read();
	rep(i, 1, n) G[i].clear();
	int u, v, w;
	A.e.clear(), B.e.clear();
	rep(i, 1, m) {
		a[i] = read(), b[i] = read(), w = read();
		G[a[i]].eb(b[i], w), G[b[i]].eb(a[i], w);
		A.e.eb(w, a[i], b[i]);
	}
	rep(i, 1, n) sort(all(G[i]));
	A.Kru();
	rep(i, 1, n) {
		u = A.a[i];
		auto add = [&](int j) {
			if(j < 1 || j > n || G[v = A.a[j]].size() > G[u].size()) return;
			auto it = lower_bound(all(G[u]), pair(v, 0));
			if(it == G[u].end() || it->first != v) B.e.eb(A.qry(i, j), u, v);
		};
		rep(j, 1, G[u].size() << 1 | 1) add(i - j), add(i + j);
	}
	B.Kru();
	rep(i, 1, m) wrt(B.qry(B.b[a[i]], B.b[b[i]]), "\n "[i < m]);
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int T;
	for(cin >> T; T--; solve());
}