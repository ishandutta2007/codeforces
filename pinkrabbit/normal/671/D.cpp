#include <cstdio>
#include <algorithm>
#include <vector>

typedef long long LL;
const int MN = 300005, MM = 300005;

int N, M, fail;
std::vector<int> G[MN];
std::vector<std::pair<int, LL>> Q[MN];
LL f[MN], Ans;

int rt[MN], lc[MM], rc[MM], len[MM], cnt;
LL val[MM], tag[MM]; int id[MM];
inline int newNode(LL v, int i) { return val[++cnt] = v, id[cnt] = i, len[cnt] = 1, cnt; }
inline void P(int rt, LL x) { if (!rt) return ; val[rt] += x, tag[rt] += x; }
inline void PushDown(int rt) { if (tag[rt]) P(lc[rt], tag[rt]), P(rc[rt], tag[rt]), tag[rt] = 0; }
int Merge(int rt1, int rt2) {
	if (!rt1 || !rt2) return rt1 + rt2;
	if (val[rt1] > val[rt2]) std::swap(rt1, rt2);
	PushDown(rt1);
	rc[rt1] = Merge(rc[rt1], rt2);
	if (len[lc[rt1]] < len[rc[rt1]]) std::swap(lc[rt1], rc[rt1]);
	len[rt1] = len[rc[rt1]] + 1;
	return rt1;
}
inline int Del(int rt) { PushDown(rt); return Merge(lc[rt], rc[rt]); }

int dep[MN];
void DFS(int u, int fz) {
	LL S = 0;
	dep[u] = dep[fz] + 1;
	for (auto x : Q[u]) {
		int i = dep[x.first], c = x.second;
		rt[u] = Merge(rt[u], newNode(c, i));
	}
	for (auto v : G[u]) if (v != fz) {
		DFS(v, u);
		P(rt[v], -f[v]);
		rt[u] = Merge(rt[u], rt[v]);
		S += f[v];
	}
	P(rt[u], S);
	while (rt[u] && id[rt[u]] >= dep[u]) rt[u] = Del(rt[u]);
	if (!rt[u]) fail = 1;
	f[u] = val[rt[u]];
}

int main() {
	int x, y; LL z;
	scanf("%d%d", &N, &M);
	for (int i = 1; i < N; ++i) {
		scanf("%d%d", &x, &y);
		G[x].push_back(y), G[y].push_back(x);
	}
	for (int i = 1; i <= M; ++i) {
		scanf("%d%d%lld", &x, &y, &z);
		Q[x].push_back({y, z});
	}
	dep[1] = 1;
	for (auto u : G[1]) DFS(u, 1);
	if (fail) return puts("-1"), 0;
	for (auto u : G[1]) Ans += f[u];
	printf("%lld\n", Ans);
	return 0;
}