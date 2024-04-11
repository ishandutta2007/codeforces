#include <bits/stdc++.h>

const int INF = 1E9;
const int mx[8] = {1, 1, 2, 2, -1, -1, -2, -2}, my[8] = {2, -2, 1, -1, 2, -2, 1, -1};
const int mbx[4] = {1, 1, -1, -1}, mby[4] = {1, -1, 1, -1};
const int mrx[4] = {1, -1, 0, 0}, mry[4] = {0, 0, 1, -1};

int N;
int res[3][3];
void search (int bx, int by, int ex, int ey) {
	static int map[20][20][3];
	for (int st = 0; st < 3; ++st) {
		for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) for (int k = 0; k < 3; ++k) map[i][j][k] = INF;
		map[bx][by][st] = 0; std::queue <std::tuple <int, int, int>> q; q.push (std::make_tuple (bx, by, st));
		while (!q.empty ()) {
			int x, y, k; std::tie (x, y, k) = q.front (); q.pop ();
			for (int nk = 0; nk < 3; ++nk) if (map[x][y][nk] > map[x][y][k] + 1 + (1 << 10)) {
				map[x][y][nk] = map[x][y][k] + 1 + (1 << 10); q.push (std::make_tuple (x, y, nk));
			}
			if (k == 0) {
				for (int mv = 0; mv < 8; ++mv) {
					int nx = x + mx[mv], ny = y + my[mv];
					if (nx >= 0 && nx < N && ny >= 0 && ny < N && map[nx][ny][k] > map[x][y][k] + (1 << 10)) {
						map[nx][ny][k] = map[x][y][k] + (1 << 10); q.push (std::make_tuple (nx, ny, k));
					}
				}
			} else if (k == 1) {
				for (int mv = 0; mv < 4; ++mv) {
					int nx = x, ny = y;
					while (nx >= 0 && nx < N && ny >= 0 && ny < N) {
						if (map[nx][ny][k] > map[x][y][k] + (1 << 10)) {
							map[nx][ny][k] = map[x][y][k] + (1 << 10); q.push (std::make_tuple (nx, ny, k));
						}
						nx += mbx[mv]; ny += mby[mv];
					}
				}
			} else if (k == 2) {
				for (int mv = 0; mv < 4; ++mv) {
					int nx = x, ny = y;
					while (nx >= 0 && nx < N && ny >= 0 && ny < N) {
						if (map[nx][ny][k] > map[x][y][k] + (1 << 10)) {
							map[nx][ny][k] = map[x][y][k] + (1 << 10); q.push (std::make_tuple (nx, ny, k));
						}
						nx += mrx[mv]; ny += mry[mv];
					}
				}
			}
		}
		for (int i = 0; i < 3; ++i) res[st][i] = map[ex][ey][i];
	}
}

int xx[1000], yy[1000];

int main () {
	scanf ("%d", &N);
	for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) {
		int u; scanf ("%d", &u); xx[u] = i; yy[u] = j;
	}
	int bb[3] = {0, 0, 0};
	for (int i = 2; i <= N * N; ++i) {
		search (xx[i - 1], yy[i - 1], xx[i], yy[i]);
		int nn[3] = {INF, INF, INF};
		for (int i = 0; i < 3; ++i) for (int j = 0; j < 3; ++j)
			nn[i] = std::min (nn[i], bb[j] + res[j][i]);
		bb[0] = nn[0], bb[1] = nn[1], bb[2] = nn[2];
//		for (int i = 0; i < 3; ++i) for (int j = 0; j < 3; ++j) printf ("%d%c", res[i][j], " \n"[j == 2]);
//		printf ("%d %d %d\n\n", bb[0], bb[1], bb[2]);
	}
	int fi = std::min (bb[0], std::min (bb[1], bb[2]));
	printf ("%d %d\n", fi >> 10, fi & (1 << 10) - 1);
}