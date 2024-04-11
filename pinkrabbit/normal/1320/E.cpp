#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

const int MN = 200005;

int N, Q;
std::vector<int> G[MN];

int dep[MN], faz[MN], siz[MN], son[MN], top[MN], dfn[MN], dfc;
void DFS0(int u, int fz) {
	dep[u] = dep[faz[u] = fz] + 1, siz[u] = 1;
	for (auto v : G[u]) if (v != fz) {
		DFS0(v, u), siz[u] += siz[v];
		if (siz[son[u]] < siz[v]) son[u] = v;
	}
}
void DFS1(int u, int t) {
	top[u] = t, dfn[u] = ++dfc;
	if (son[u]) DFS1(son[u], t);
	for (auto v : G[u]) if (v != faz[u] && v != son[u]) DFS1(v, v);
}
inline int LCA(int x, int y) {
	while (top[x] != top[y]) {
		if (dep[top[x]] < dep[top[y]]) std::swap(x, y);
		x = faz[top[x]];
	} return dep[x] < dep[y] ? x : y;
}

#define fi first
#define se second
typedef std::pair<int, int> pii;
std::vector<pii> T[MN];
inline void Add(int u, int v) {
	int d = dep[v] - dep[u];
	T[u].push_back({v, d});
	T[v].push_back({u, d});
}
int uid[MN], spd[MN], aid[MN], col[MN], usd[MN], cnt;
std::vector<int> seq;
int stk[MN], tp;
struct dat { int u, t, c, d; };
inline bool operator < (dat x, dat y) { return x.t == y.t ? x.c > y.c : x.t > y.t; }
std::priority_queue<dat> pq;

int main() {
	scanf("%d", &N);
	for (int i = 1, x, y; i < N; ++i)
		scanf("%d%d", &x, &y),
		G[x].push_back(y),
		G[y].push_back(x);
	DFS0(1, 0), DFS1(1, 1);
	scanf("%d", &Q);
	for (int K, M; Q--; ) {
		scanf("%d%d", &K, &M);
		seq.clear();
		for (int i = 1; i <= K; ++i) scanf("%d%d", &uid[i], &spd[i]), seq.push_back(uid[i]);
		for (int i = 1; i <= M; ++i) scanf("%d", &aid[i]), seq.push_back(aid[i]);
		std::sort(seq.begin(), seq.end(), [](int i, int j) { return dfn[i] < dfn[j]; });
		seq.erase(std::unique(seq.begin(), seq.end()), seq.end()), cnt = 0;
		for (auto u : seq) {
			usd[++cnt] = u;
			if (!tp) { stk[++tp] = u; continue; }
			int lca = LCA(u, stk[tp]);
			while (tp && dep[stk[tp - 1]] >= dep[lca]) Add(stk[tp - 1], stk[tp]), --tp;
			if (stk[tp] != lca) Add(lca, stk[tp]), stk[tp] = lca, usd[++cnt] = lca;
			stk[++tp] = u;
		}
		while (--tp) Add(stk[tp], stk[tp + 1]);
		for (int i = 1; i <= K; ++i) pq.push({uid[i], 0, i, 0});
		while (!pq.empty()) {
			dat p = pq.top(); pq.pop();
			if (col[p.u]) continue;
			col[p.u] = p.c;
			for (auto e : T[p.u]) if (!col[e.fi])
				pq.push({e.fi, (p.d + e.se - 1) / spd[p.c] + 1, p.c, p.d + e.se});
		}
		for (int i = 1; i <= M; ++i) printf("%d%c", col[aid[i]], " \n"[i == M]);
		for (int i = 1; i <= cnt; ++i) col[usd[i]] = 0, T[usd[i]].clear();
	}
	return 0;
}