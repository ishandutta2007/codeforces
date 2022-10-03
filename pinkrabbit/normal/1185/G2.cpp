#include <cstdio>
#include <algorithm>

typedef long long LL;
const int Mod = 1000000007;
const int MN = 55, MT = 2505;

inline void Ad(int &x, int y) { x -= (x += y) >= Mod ? Mod : 0; }

int N, T;
int f[MT][MN][MN], g[MT][MN], Ans;
int h[MN][MN][MN][3];

int main() {
	scanf("%d%d", &N, &T);
	f[0][0][0] = g[0][0] = 1;
	int st2 = 0, st3 = 0, s1 = 0, s2 = 0, s3 = 0;
	for (int id = 1; id <= N; ++id) {
		int x, y;
		scanf("%d%d", &x, &y);
		if (y == 3) {
			for (int t = st3; t >= 0; --t)
				for (int i = s3; i >= 0; --i)
					Ad(g[t + x][i + 1], g[t][i]);
			st3 += x;
		}
		else {
			for (int t = st2; t >= 0; --t)
				for (int i = s1; i >= 0; --i)
					for (int j = s2; j >= 0; --j)
						Ad(f[t + x][i + (y == 1)][j + (y == 2)], f[t][i][j]);
			st2 += x;
		}
		s1 += y == 1, s2 += y == 2, s3 += y == 3;
	}
	h[1][0][0][0] = h[0][1][0][1] = h[0][0][1][2] = 1;
	for (int i = 0; i <= N; ++i) {
		for (int j = 0; j <= N; ++j) {
			for (int k = 0; k <= N; ++k) {
				if (i + j + k <= 1) continue;
				if (i) h[i][j][k][0] = (LL)i * (h[i - 1][j][k][1] + h[i - 1][j][k][2]) % Mod;
				if (j) h[i][j][k][1] = (LL)j * (h[i][j - 1][k][0] + h[i][j - 1][k][2]) % Mod;
				if (k) h[i][j][k][2] = (LL)k * (h[i][j][k - 1][0] + h[i][j][k - 1][1]) % Mod;
			}
		}
	}
	for (int t = 0; t <= st2 && t <= T; ++t)
		for (int i = 0; i <= s1; ++i)
			for (int j = 0; j <= s2; ++j) {
				if (!f[t][i][j]) continue;
				for (int k = 0; k <= s3; ++k) {
					if (!g[T - t][k]) continue;
					Ad(Ans, ((LL)h[i][j][k][0] + h[i][j][k][1] + h[i][j][k][2]) * f[t][i][j] % Mod * g[T - t][k] % Mod);
				}
			}
	printf("%d\n", Ans);
	return 0;
}