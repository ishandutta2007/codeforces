#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

#define fi first
#define se second
typedef long long LL;
typedef std::pair<int, int> pii;
typedef std::pair<LL, int> pli;
const LL Infll = 0x3f3f3f3f3f3f3f3f;
const int MN = 2005;

int N, M, S, T, a[MN];
std::vector<pii> G[MN];
int SDis[MN], TDis[MN], X, Y;

void Dijkstra(int S, int *ddis, int &V) {
	static bool vis[MN]; static LL dis[MN];
	std::priority_queue<pli, std::vector<pli>, std::greater<pli>> pq;
	for (int i = 1; i <= N; ++i) vis[i] = 0, dis[i] = Infll;
	dis[S] = 0, pq.push({dis[S], S});
	while (!pq.empty()) {
		pli p = pq.top(); pq.pop();
		LL d = p.fi; int u = p.se;
		if (vis[u]) continue;
		for (auto e : G[u]) {
			int v = e.fi, w = e.se;
			if (dis[v] > d + w) {
				dis[v] = d + w;
				pq.push({dis[v], v});
			}
		}
	}
	static LL Dr[MN]; int Cr = 0;
	for (int i = 1; i <= N; ++i) Dr[++Cr] = dis[i];
	std::sort(Dr + 1, Dr + Cr + 1), V = Cr = std::unique(Dr + 1, Dr + Cr + 1) - Dr - 1;
	for (int i = 1; i <= N; ++i) ddis[i] = std::lower_bound(Dr + 1, Dr + Cr + 1, dis[i]) - Dr;
}

LL Sum[MN][MN];
int dot[MN][MN];
int nxtX[MN][MN], nxtY[MN][MN];
LL dpX[MN][MN], dpY[MN][MN];

int main() {
	scanf("%d%d%d%d", &N, &M, &S, &T);
	for (int i = 1; i <= N; ++i) scanf("%d", &a[i]);
	for (int i = 1, x, y, z; i <= M; ++i)
		scanf("%d%d%d", &x, &y, &z),
		G[x].push_back({y, z}),
		G[y].push_back({x, z});
	Dijkstra(S, SDis, X);
	Dijkstra(T, TDis, Y);
	for (int i = 1; i <= N; ++i)
		Sum[SDis[i]][TDis[i]] += a[i],
		dot[SDis[i]][TDis[i]] = 1;
	for (int i = X; i >= 1; --i)
		for (int j = Y; j >= 1; --j) {
			Sum[i][j] += Sum[i + 1][j] + Sum[i][j + 1] - Sum[i + 1][j + 1];
			nxtX[i][j] = std::min(i < X ? nxtX[i + 1][j] : X, j < Y ? nxtX[i][j + 1] : X);
			nxtY[i][j] = std::min(i < X ? nxtY[i + 1][j] : Y, j < Y ? nxtY[i][j + 1] : Y);
			if (dot[i][j]) nxtX[i][j] = i, nxtY[i][j] = j;
		}
	for (int i = X; i >= 1; --i)
		for (int j = Y; j >= 1; --j) {
			dpX[i][j] = Sum[i][j] - dpY[nxtX[i][j] + 1][j];
			dpY[i][j] = Sum[i][j] - dpX[i][nxtY[i][j] + 1];
			if (i == 1 && j == 1) continue;
			dpX[i][j] = std::min(dpX[i][j], dpX[i][j + 1]);
			dpY[i][j] = std::min(dpY[i][j], dpY[i + 1][j]);
		}
	LL Tavas = dpX[1][1], Nafas = Sum[1][1] - Tavas;
	puts(Tavas == Nafas ? "Flowers" : Tavas < Nafas ? "Cry" : "Break a heart");
	return 0;
}