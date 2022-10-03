#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>

#define fi first
#define se second
typedef long long LL;
typedef std::pair<int, LL> pil;
typedef std::pair<LL, int> pli;
const LL Infll = 0x3f3f3f3f3f3f3f3f;
const int Mod = 998244353;
const int MN = 200005, MM = 200005, MK = 21;

int N, M, K, ex[MM], ey[MM];
std::vector<pil> G[MN * MK];
inline int Id(int j, int u) {
	return j * N + u;
}

LL dis[MN * MK];
int _que[MN * MK * 2], *que = _que + MN * MK;
void BFS() {
	int l = 1, r = 1;
	dis[Id(0, 1)] = 0;
	que[1] = Id(0, 1);
	while (l <= r) {
		int u = que[l++];
		for (pil e : G[u]) {
			int v = e.fi;
			int w = e.se;
			if (dis[v] != Infll) continue;
			dis[v] = dis[u] + w;
			if (w) que[++r] = v;
			else que[--l] = v;
		}
	}
}
int vis[MN * 2];
void Dijk() {
	std::priority_queue<pli, std::vector<pli>, std::greater<pli>> pq;
	dis[Id(0, 1)] = 0;
	pq.push({0ll, Id(0, 1)});
	while (!pq.empty()) {
		pli p = pq.top(); pq.pop();
		int u = p.se;
		LL d = p.fi;
		if (vis[u]) continue;
		vis[u] = 1;
		for (pil e : G[u]) {
			int v = e.fi;
			LL w = e.se;
			if (dis[v] > d + w) {
				dis[v] = d + w;
				pq.push({dis[v], v});
			}
		}
	}
}

int main() {
	K = 20;
	scanf("%d%d", &N, &M);
	for (int i = 1, x, y; i <= M; ++i) {
		scanf("%d%d", &ex[i], &ey[i]);
		x = ex[i], y = ey[i];
		for (int j = 0; j <= K; ++j) {
			if (j & 1)
				G[Id(j, y)].push_back({Id(j, x), 1});
			else
				G[Id(j, x)].push_back({Id(j, y), 1});
		}
	}
	for (int j = 1; j <= K; ++j)
		for (int i = 1; i <= N; ++i)
			G[Id(j - 1, i)].push_back({Id(j, i), 0});
	memset(dis, 0x3f, sizeof dis);
	BFS();
	LL Ans = Infll;
	for (int j = 0; j <= K; ++j)
		if (dis[Id(j, N)] != -1)
			Ans = std::min(Ans, dis[Id(j, N)] + (1ll << j) - 1);
	if (Ans != Infll) {
		printf("%lld\n", Ans);
		return 0;
	}
	for (int j = 0; j <= K; ++j)
		for (int i = 1; i <= N; ++i)
			G[Id(j - 1, i)].clear();
	for (int i = 1, x, y; i <= M; ++i) {
		x = ex[i], y = ey[i];
		G[Id(0, x)].push_back({Id(0, y), 1});
		G[Id(1, y)].push_back({Id(1, x), 1});
	}
	for (int i = 1; i <= N; ++i)
		G[Id(0, i)].push_back({Id(1, i), 1 << 20}),
		G[Id(1, i)].push_back({Id(0, i), 1 << 20});
	memset(dis, 0x3f, sizeof dis);
	Dijk();
//	for (int j = 0; j <= 1; ++j)
//		for (int i = 1; i <= N; ++i)
//			printf("dis[(%d, %d)] = %lld\n", j, i, dis[Id(j, i)]);
	Ans = std::min(dis[Id(0, N)], dis[Id(1, N)]);
	int c = Ans >> 20;
	int d = Ans ^ ((LL)c << 20);
//	printf("%d, %d\n", c, d);
	Ans = 1;
	for (int i = 1; i <= c; ++i) Ans = 2 * Ans % Mod;
	Ans = (Ans + d - 1) % Mod;
	printf("%lld\n", Ans);
	return 0;
}