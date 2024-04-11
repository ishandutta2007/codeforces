#include <cstdio>
#include <algorithm>

inline void chkmin(int &x, int y) {
	x = std::min(x, y);
}

const int MK = 19;
const int MN = 1 << MK | 7;

int N, K, A[MN];

int ch[MN * MK][2], cnt;
inline void Insert(int x) {
	int now = 1;
	for (int j = K - 1; j >= 0; --j) {
		int y = x >> j & 1;
		if (!ch[now][y])
			ch[now][y] = ++cnt;
		now = ch[now][y];
	}
}

int f[MK][1 << MK];
int Minimum(int u, int j, int x) {
	if (j == -1) return 0;
	int d = x >> j & 1;
	if (ch[u][d]) return Minimum(ch[u][d], j - 1, x);
	return Minimum(ch[u][d ^ 1], j - 1, x) | 1 << j;
}
int Maximum(int u, int j, int x) {
	if (j == -1) return 0;
	int d = x >> j & 1;
	if (ch[u][d ^ 1]) return Maximum(ch[u][d ^ 1], j - 1, x) | 1 << j;
	return Maximum(ch[u][d], j - 1, x);
}
void DFS(int u, int j) {
	if (ch[u][0] && ch[u][1]) {
		for (int x = 0; x < 1 << j; ++x) {
			chkmin(f[j][x], Minimum(ch[u][1], j - 1, x) + (1 << j) - Maximum(ch[u][0], j - 1, x));
			chkmin(f[j][x | 1 << j], Minimum(ch[u][0], j - 1, x) + (1 << j) - Maximum(ch[u][1], j - 1, x));
		}
	}
	if (ch[u][0]) DFS(ch[u][0], j - 1);
	if (ch[u][1]) DFS(ch[u][1], j - 1);
}

int Ans[MN];
int main() {
	cnt = 1;
	scanf("%d%d", &N, &K);
	for (int i = 1; i <= N; ++i)
		scanf("%d", &A[i]),
		Insert(A[i]);
	for (int j = 0; j < K; ++j)
		for (int i = 0; i < 2 << j; ++i)
			f[j][i] = 1 << K;
	DFS(1, K - 1);
	for (int i = 0; i < 1 << K; ++i)
		Ans[i] = 1 << K;
	for (int j = 0; j < K; ++j) {
		for (int i = 0; i < 2 << j; ++i) {
			for (int p = 0; p < 1 << (K - j - 1); ++p)
				chkmin(Ans[p << (j + 1) | i], f[j][i]);
		}
	}
	for (int i = 0; i < 1 << K; ++i)
		printf("%d%c", Ans[i], " \n"[i == (1 << K) - 1]);
	return 0;
}