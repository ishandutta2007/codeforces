#include <cstdio>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>

typedef long long LL;
const LL Infll = 0x3f3f3f3f3f3f3f3f;
const int MN = 100005, MK = 2000005;

int N, Q, dir[MN]; LL tim[MN];
struct edg { int v, w; };
std::vector<edg> G[MN];

LL dep[MN];
int par[MN], siz[MN], son[MN], top[MN];
void DFS0(int u) {
	siz[u] = 1;
	for (edg e : G[u]) {
		par[e.v] = u;
		dep[e.v] = dep[u] + e.w;
		DFS0(e.v);
		siz[u] += siz[e.v];
		if (siz[son[u]] < siz[e.v])
			son[u] = e.v;
	}
}

int _s[MN], *s[MN], cnt;
void DFS1(int u, int t) {
	++cnt, top[u] = t;
	if (u == t) s[u] = _s + cnt;
	if (son[u]) DFS1(son[u], t), tim[u] = -dep[u], s[t][++*s[t]] = u;
	for (edg e : G[u]) if (e.v != son[u])
		DFS1(e.v, e.v);
}

int K;
LL lb[MK], rb[MK], pl[MK];
std::priority_queue<LL, std::vector<LL>, std::greater<LL>> pq;
inline void Add(LL t0, LL t1) { lb[++K] = t0 + 1, rb[K] = t1, pl[K] = K; }

int main() {
	scanf("%d%d", &N, &Q);
	for (int i = 1; i < N; ++i) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		G[x].push_back({y, z});
		dir[x] = y;
	}
	DFS0(1), DFS1(1, 1);
	while (Q--) {
		int u, c, x;
		scanf("%d%d", &u, &c);
		if (u == 1) continue;
		u = par[x = u];
		while (u) {
			int t = top[u];
			while (*s[t] && dep[s[t][*s[t]]] < dep[u]) {
				int v = s[t][*s[t]];
				if (dir[v] != son[v]) Add(dep[v] + tim[v], dep[v] + c);
				dir[v] = son[v];
				--*s[t];
			}
			if (dir[u] != x) Add(dep[u] + tim[s[t][*s[t]]], dep[u] + c);
			dir[u] = x, tim[u] = c;
			if (u != s[t][*s[t]]) s[t][++*s[t]] = u;
			u = par[x = t];
		}
	}
	std::sort(pl + 1, pl + K + 1, [](int i, int j) { return lb[i] < lb[j]; });
	++K, pl[K] = K, lb[K] = Infll, rb[K] = 0;
	LL lst = 0, boom = -1;
	for (int i = 1; i <= K; ++i) {
		LL c = lb[pl[i]] - lst;
		for (int x = 0; x < c && !pq.empty(); ++x) {
			if (lst + x > pq.top()) { boom = pq.top(); break; }
			pq.pop();
		}
		if (~boom) break;
		pq.push(rb[pl[i]]);
		lst = lb[pl[i]];
	} --K;
	if (~boom) {
		int ans = 0;
		for (int i = 1; i <= K; ++i)
			if (rb[i] < boom) ++ans;
		printf("%lld %d\n", boom, ans);
	} else printf("-1 %d\n", K);
	return 0;
}