#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>

typedef long long LL;
typedef std::pair<LL, int> pli;
#define mp std::make_pair
const LL Inf = 0x3f3f3f3f3f3f3f3f;
const int MN = 1005;
const int MM = 10005;

int N, M, L, S, T;
int eu[MM], ev[MM]; LL ew[MM];
int h[MN], nxt[MM * 2], to[MM * 2], bel[MM * 2], tot;
inline void ins(int x, int y, int z) {
	nxt[++tot] = h[x], to[tot] = y, bel[tot] = z, h[x] = tot;
}

LL dis1[MN], dis2[MN];

int vis[MN];
std::priority_queue<pli, std::vector<pli>, std::greater<pli> > pq;
inline void Dijkstra(int S, LL *dis, int Typ) {
	for (int i = 1; i <= N; ++i) dis[i] = Inf, vis[i] = 0;
	dis[S] = 0, pq.push(mp(0, S));
	while (!pq.empty()) {
		pli p = pq.top(); pq.pop();
		if (vis[p.second]) continue;
		LL d = p.first; int u = p.second;
		vis[u] = 1;
		for (int i = h[u]; i; i = nxt[i]) {
			LL w = ew[bel[i]];
			if (!w) w = Typ ? std::max(1ll, L - d - dis1[to[i]]) : 1;
			if (dis[to[i]] > d + w) {
				dis[to[i]] = d + w;
				pq.push(mp(dis[to[i]], to[i]));
			}
			if (Typ) ew[bel[i]] = w;
		}
	}
}

int main() {
	scanf("%d%d%d%d%d", &N, &M, &L, &S, &T), ++S, ++T;
	for (int i = 1; i <= M; ++i) {
		scanf("%d%d%lld", &eu[i], &ev[i], &ew[i]);
		++eu[i], ++ev[i];
		ins(eu[i], ev[i], i);
		ins(ev[i], eu[i], i);
	}
	Dijkstra(T, dis1, 0);
	Dijkstra(S, dis2, 1);
	if (dis2[T] != L) return puts("NO"), 0;
	puts("YES");
	for (int i = 1; i <= M; ++i)
		printf("%d %d %lld\n", eu[i] - 1, ev[i] - 1, ew[i] ? ew[i] : 1);
	return 0;
}