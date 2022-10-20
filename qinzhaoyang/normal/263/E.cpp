#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 10;
using ll = long long;

int n, m, k, a[N][N];
ll s1[N][N], s2[N][N], s3[N][N], s4[N][N], sl[N][N], sr[N][N], su[N][N], sd[N][N], as[N][N], mx = -1;

inline int S1(int x, int y, int len) {
	assert(x - len >= 0 && y - len >= 0);
	return s1[x][y] - s1[x - len][y - len];
}
inline int S2(int x, int y, int len) {
	assert(x + len <= n + 1 && y - len >= 0);
	return s2[x][y] - s2[x + len][y - len];
}
inline int S3(int x, int y, int len) {
	assert(x + len <= n && x - len - 1 >= 0);
	return s3[x + len][y] - s3[x - len - 1][y];
}
inline int S4(int x, int y, int len) {
	assert(y + len <= n && y - len - 1 >= 0);
	return s4[x][y + len] - s4[x][y - len - 1];
}

int main() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%d", &a[i][j]);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			s1[i][j] = s1[i - 1][j - 1] + a[i][j];
	for (int j = 1; j <= m; j++)
		for (int i = n; i >= 1; i--)
			s2[i][j] = s2[i + 1][j - 1] + a[i][j];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			s3[i][j] = s3[i - 1][j] + a[i][j];
			s4[i][j] = s4[i][j - 1] + a[i][j];
		}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			int d = abs(k - i) + abs(k - j);
			if (d >= k) continue;
			as[k][k] += 1ll * (k - d) * a[i][j];
			if (j <= k) sl[k][k] += a[i][j];
			if (j >= k) sr[k][k] += a[i][j];
			if (i <= k) su[k][k] += a[i][j];
			if (i >= k) sd[k][k] += a[i][j];
		}
	for (int i = k + 1; i <= n - k + 1; i++) {
		sl[i][k] = sl[i - 1][k] - S2(i - k, k, k) + S1(i + k - 1, k, k);
		sr[i][k] = sr[i - 1][k] - S1(i - 1, k + k - 1, k) + S2(i, k + k - 1, k);
	}
	for (int i = k; i <= n - k + 1; i++)
		for (int j = k + 1; j <= m - k + 1; j++) {
			sl[i][j] = sl[i][j - 1], sr[i][j] = sr[i][j - 1];
			sl[i][j] -= S2(i - (k - 1), j - 1, k - 1) + S1(i + k - 1, j - 1, k);
			sl[i][j] += S3(i, j, k - 1);
			sr[i][j] -= S3(i, j - 1, k - 1);
			sr[i][j] += S1(i, j + k - 1, k) + S2(i, j + k - 1, k) - a[i][j + k - 1];
		}
	
	for (int i = k + 1; i <= n - k + 1; i++) {
		su[i][k] = su[i - 1][k], sd[i][k] = sd[i - 1][k];
		su[i][k] -= S2(i - k, k, k) + S1(i - 1, k + (k - 1), k - 1);
		su[i][k] += S4(i, k, k - 1);
		sd[i][k] -= S4(i - 1, k, k - 1);
		sd[i][k] += S1(i + k - 1, k, k) + S2(i, k + k - 1, k - 1);
	}
	for (int i = k + 1; i <= n - k + 1; i++)
		as[i][k] = as[i - 1][k] - su[i - 1][k] + sd[i][k];
	for (int i = k; i <= n - k + 1; i++)
		for (int j = k + 1; j <= m - k + 1; j++)
			as[i][j] = as[i][j - 1] - sl[i][j - 1] + sr[i][j];
	int tx = -1, ty = -1;
	for (int i = k; i <= n - k + 1; i++)
		for (int j = k; j <= m - k + 1; j++)
			if (as[i][j] > mx)
				mx = as[i][j], tx = i, ty = j;
	printf("%d %d\n", tx, ty);
	return 0;
}