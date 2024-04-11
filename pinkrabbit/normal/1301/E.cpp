#include <cstdio>
#include <algorithm>

const int MN = 505;

int N, M, Q;
char A[MN][MN], D[4] = {'R', 'G', 'B', 'Y'};
int V[MN][MN][4], B[9][9][MN][MN];
inline int S(int i, int j, int k) {
	if (i <= 0 || j <= 0) return 0;
	return V[std::min(i, N)][std::min(j, M)][k];
}
inline int SQ(int i, int j, int k, int d) {
	return S(i, j, k) - S(i, j - d, k) - S(i - d, j, k) + S(i - d, j - d, k);
}
inline int Qur(int sx, int sy, int tx, int ty) {
	int jx = 31 - __builtin_clz(tx - sx + 1);
	int jy = 31 - __builtin_clz(ty - sy + 1);
	return std::max({B[jx][jy][sx + (1 << jx) - 1][sy + (1 << jy) - 1], B[jx][jy][sx + (1 << jx) - 1][ty], B[jx][jy][tx][sy + (1 << jy) - 1], B[jx][jy][tx][ty]});
}

int main() {
	scanf("%d%d%d", &N, &M, &Q);
	for (int i = 1; i <= N; ++i) scanf("%s", A[i] + 1);
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= M; ++j)
			for (int k = 0; k < 4; ++k)
				V[i][j][k] = V[i][j - 1][k] + V[i - 1][j][k] - V[i - 1][j - 1][k] + (A[i][j] == D[k]);
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= M; ++j) {
			int lb = 1, rb = std::min(N, M) / 2, mid, num, ans = 0;
			while (lb <= rb) {
				mid = (lb + rb) >> 1, num = mid * mid;
				if (SQ(i, j, 0, mid) == num && SQ(i, j + mid, 1, mid) == num && SQ(i + mid, j, 3, mid) == num && SQ(i + mid, j + mid, 2, mid) == num) ans = mid, lb = mid + 1;
				else rb = mid - 1;
			}
			B[0][0][i][j] = ans;
		}
	for (int x = 1; x <= N; ++x)
		for (int j = 0; 2 << j <= M; ++j)
			for (int y = 2 << j; y <= M; ++y)
				B[0][j + 1][x][y] = std::max(B[0][j][x][y - (1 << j)], B[0][j][x][y]);
	for (int i = 0; 2 << i <= N; ++i)
		for (int j = 0; 1 << j <= M; ++j)
			for (int x = 2 << i; x <= N; ++x)
				for (int y = 1 << j; y <= M; ++y)
					B[i + 1][j][x][y] = std::max(B[i][j][x - (1 << i)][y], B[i][j][x][y]);
	while (Q--) {
		int sx, sy, tx, ty;
		scanf("%d%d%d%d", &sx, &sy, &tx, &ty);
		int lb = 1, rb = std::min(tx - sx + 1, ty - sy + 1) / 2, mid, ans = 0;
		while (lb <= rb) {
			mid = (lb + rb) >> 1;
			if (Qur(sx + mid - 1, sy + mid - 1, tx - mid, ty - mid) >= mid) ans = mid, lb = mid + 1;
			else rb = mid - 1;
		}
		printf("%d\n", 4 * ans * ans);
	}
	return 0;
}