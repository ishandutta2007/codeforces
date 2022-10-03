#include <cstdio>
#include <cmath>
#include <algorithm>

const int Inf = 0x3f3f3f3f;
const int MN = 14;
const int MM = 100;

inline void chkmin(int &x, int y) { x = std::min(x, y); }
inline void chkmax(int &x, int y) { x = std::max(x, y); }

struct Point {
	int x, y;
};
int dis(Point p, Point q) {
	return std::abs(p.x - q.x) + std::abs(p.y - q.y);
}

struct Quest {
	Point p;
	int t;
};
bool operator < (Quest p, Quest q) {
	return p.t < q.t;
}

int N, M;
Point a[MN];
Quest b[MM];

int f[1 << MN][MM];
int g[1 << MN][MM];
void DP() {
	for (int S = 0; S < 1 << N; ++S)
		for (int j = 0; j < M; ++j)
			f[S][j] = Inf,
			g[S][j] = 0;
	for (int i = 0; i < N; ++i)
		f[1 << i][0] = 0;
	for (int j = 0; j < M; ++j)
		g[0][j] = 1;
	// f -> f : tower --> tower
	// f -> g : tower --> quest
	// g -> f : quest --> tower
	// g -> g : quest --> quest
	int Ans = 0;
	for (int S = 0; S < 1 << N; ++S) {
		static int dTower[MN], dQuest[MM];
		for (int i = 0; i < N; ++i) {
			dTower[i] = Inf;
			for (int p = 0; p < N; ++p) if (S >> p & 1)
				chkmin(dTower[i], dis(a[p], a[i]));
		}
		for (int j = 0; j < M; ++j) {
			dQuest[j] = Inf;
			for (int p = 0; p < N; ++p) if (S >> p & 1)
				chkmin(dQuest[j], dis(a[p], b[j].p));
		}
		for (int j = 0; j < M; ++j) if (f[S][j] != Inf) {
			int v = f[S][j];
			for (int i = 0; i < N; ++i) if (~S >> i & 1)
				chkmin(f[S | 1 << i][j], v + dTower[i]);
			for (int k = 0; k < M; ++k) if (v + dQuest[k] <= b[k].t)
				chkmax(g[S][k], j + 1);
		}
		for (int j = 0; j < M; ++j) if (g[S][j]) {
			int w = g[S][j];
			chkmax(Ans, w);
			for (int i = 0; i < N; ++i) if (~S >> i & 1)
				chkmin(f[S | 1 << i][w], b[j].t + std::min(dTower[i], dis(b[j].p, a[i])));
			for (int k = 0; k < M; ++k) if (b[j].t + std::min(dQuest[k], dis(b[j].p, b[k].p)) <= b[k].t)
				chkmax(g[S][k], w + 1);
		}
	}
	printf("%d\n", Ans);
}

int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; ++i)
		scanf("%d%d", &a[i].x, &a[i].y);
	for (int i = 0; i < M; ++i)
		scanf("%d%d%d", &b[i].p.x, &b[i].p.y, &b[i].t);
	std::sort(b, b + M);
	DP();
	return 0;
}