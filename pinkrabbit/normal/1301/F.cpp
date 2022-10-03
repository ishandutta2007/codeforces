#include <cstdio>
#include <vector>

const int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
const int MN = 1005, MK = 45;

int Abs(int a) { return a < 0 ? -a : a; }

int N, M, K, Q, A[MN][MN], C[MK];
std::vector<int> x[MK], y[MK];
int vis[MK], dis[MK][MN][MN];
int qx[MN * MN], qy[MN * MN], l, r;

int main() {
	scanf("%d%d%d", &N, &M, &K);
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= M; ++j)
			scanf("%d", &A[i][j]), ++C[A[i][j]],
			x[A[i][j]].push_back(i),
			y[A[i][j]].push_back(j);
	for (int c = 1; c <= K; ++c) {
		l = 1, r = 0;
		for (int i = 1; i <= K; ++i) vis[i] = 0;
		vis[c] = 1;
		for (int i = 0; i < C[c]; ++i)
			qx[++r] = x[c][i], qy[r] = y[c][i],
			dis[c][qx[r]][qy[r]] = 1;
		while (l <= r) {
			int i = qx[l], j = qy[l++], dist = dis[c][i][j];
			for (int d = 0; d < 4; ++d) {
				int nx = i + dx[d], ny = j + dy[d];
				if (nx < 1 || nx > N || ny < 1 || ny > M) continue;
				if (!dis[c][nx][ny])
					qx[++r] = nx, qy[r] = ny,
					dis[c][qx[r]][qy[r]] = dist + 1;
			}
			if (!vis[A[i][j]]) {
				int col = A[i][j];
				vis[col] = 1;
				for (int k = 0; k < C[col]; ++k)
					if (!dis[c][x[col][k]][y[col][k]])
						qx[++r] = x[col][k], qy[r] = y[col][k],
						dis[c][qx[r]][qy[r]] = dist + 1;
			}
		}
	}
	scanf("%d", &Q);
	while (Q--) {
		int sx, sy, tx, ty, ans;
		scanf("%d%d%d%d", &sx, &sy, &tx, &ty);
		ans = Abs(tx - sx) + Abs(ty - sy);
		for (int i = 1; i <= K; ++i)
			ans = std::min(ans, dis[i][sx][sy] + dis[i][tx][ty] - 1);
		printf("%d\n", ans);
	}
	return 0;
}