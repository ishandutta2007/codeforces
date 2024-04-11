#include <cstdio>

int const N = 111;

char valid[N][N][N];

int main() {
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < n; ++i) {
		gets(valid[N - 1][N - 1]);
		for (int j = 0; j < m; ++j) {
			gets(valid[i][j]);
			for (int x = 0; x < k; ++x) {
				valid[i][j][x] -= '0';
			}
		}
	}
	int ans = 0;
	for (int x = 0; x < n; ++x) {
		for (int y = 0; y < m; ++y) {
			for (int z = 0; z < k; ++z) {
				if (valid[x][y][z]) {	
					bool need = false;
					for (int df = 0; df < 3; ++df) {
						int fx = x - !df;
						int fy = y - df % 2;
						int fz = z - df / 2;
						if (fx < 0 || fy < 0 || fz < 0 || !valid[fx][fy][fz]) {
							continue;
						}
						for (int dt = 0; dt < 3; ++dt) {
							int tx = x + !dt;
							int ty = y + dt % 2;
							int tz = z + dt / 2;
							if (tx == n || ty == m || tz == k || !valid[tx][ty][tz]) {
								continue;
							}
							if (df == dt) {
								need = true;
							}
							int x1 = fx + tx - x;
							int y1 = fy + ty - y;
							int z1 = fz + tz - z;
							if (x1 >= 0 && x1 < n && y1 >= 0 && y1 < m && z1 >= 0 && z1 < k && valid[x1][y1][z1]) {
								continue;
							}
							need = true;
						}
					}
					if (need) {
						++ans;
					}
				}
			}
		}
	}
	printf("%d\n", ans);
}