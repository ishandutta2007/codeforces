#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back
#define eb emplace_back

using namespace std;
const int N = 4e5 + 5;
int n, a[N], b[N], c[N], d[N], ord[N], id[N];
vector <pair <int, int>> G[N];
vector <pair <int, int>> as;
int idx, dfn[N], sz[N];
void add(int u, int v, int i) {
	G[u].eb(v, i), G[v].eb(u, i);
}
void dfs(int u, int f) {
	dfn[u] = ++idx;
	int lst = 0;
	auto ins = [&](int x) {
		if(lst) as.eb(lst, x), lst = 0;
		else lst = x;
	};
	for(auto vw : G[u]) {
		int v = vw.first, w = vw.second;
		if(!dfn[v]) {
			dfs(v, w), sz[u] += sz[v] + 1;
			if(~sz[v] & 1) ins(w);
		} else if(w ^ f) {
			if(dfn[v] < dfn[u]) sz[v]++;
			else ins(w);
		}
	}
	if(lst && f) as.eb(lst, f);
}
int main() {
	#ifdef local
		freopen(".in", "r", stdin);
	#endif
	cin >> n;
	rep(i, 1, n) {
		scanf("%d%d%d%d", &a[i * 2], &b[i * 2], &c[i * 2], &d[i * 2]);
		a[i * 2 + 1] = a[i * 2] + b[i * 2];
		b[i * 2 + 1] = b[i * 2];
		c[i * 2 + 1] = c[i * 2];
		d[i * 2 + 1] = d[i * 2];
		c[i * 2] += d[i * 2];
	}
	n = n * 2 + 1;
	rep(i, 2, n) ord[i] = i;
	auto cmp = [](int x, int y) {
		return (__int128)a[x] * d[x] * b[y] * c[y] < (__int128)a[y] * d[y] * b[x] * c[x];
	};
	sort(ord + 2, ord + n + 1, cmp);
	rep(i, 2, n) id[i] = lower_bound(ord + 2, ord + n + 1, i, cmp) - ord;
	rep(i, 1, n / 2) add(id[i * 2 + 1], id[i * 2], i);
	rep(i, 2, n) dfs(i, 0);
	cout << as.size() << endl;
	for(auto uv : as) {
		int u = uv.first, v = uv.second;
		printf("%d %d\n", u, v);
	}
	return 0;
}