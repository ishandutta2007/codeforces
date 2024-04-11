#include <cstdio>
#include <queue>

typedef double db;
const int MN = 1005;

int N, p[MN][MN];
db dis[MN], val[MN];

void Dijk() {
	static int can[MN], vis[MN];
	for (int i = 1; i <= N; ++i) dis[i] = val[i] = 1, can[i] = vis[i] = 0;
	dis[N] = val[N] = 0, can[N] = 1;
	for (int k = 1; k <= N; ++k) {
		int u = 0;
		for (int i = 1; i <= N; ++i)
			if (can[i] && !vis[i] && (!u || dis[i] / (1 - val[i]) < dis[u] / (1 - val[u])))
				u = i;
		vis[u] = 1;
		db d = dis[u] / (1 - val[u]);
		for (int v = 1; v <= N; ++v) {
			if (vis[v]) continue;
			if (p[v][u] == 100) continue;
			db pr = p[v][u] / 100.;
			if (!can[v]) dis[v] = 1 + (1 - pr) * d, val[v] = pr, can[v] = 1;
			else dis[v] += val[v] * (1 - pr) * d, val[v] *= pr;
		}
	}
}

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			scanf("%d", &p[i][j]);
			p[i][j] = 100 - p[i][j];
		}
	}
	Dijk();
	printf("%.15lf\n", dis[1] / (1 - val[1]));
	return 0;
}