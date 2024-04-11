#include <cstdio>
#include <algorithm>

typedef long long LL;
const int MN = 20, MM = 200;

int N, M, N1, N2, mp[MN * 2][MN * 2], deg[MN * 2];
int u1[MM], v1[MM], c1;
int u2[MM], v2[MM], c2;
int st[MN], U;
LL Ans;

int vis[MN * 2], col[MN * 2], ok, cnt;
void DFS(int u, int c) {
	vis[u] = 1;
	col[u] = c;
	for (int v = 0; v < N; ++v) {
		if (!mp[u][v]) continue;
		if (!vis[v]) DFS(v, 3 - c);
		else if (col[v] == c) ok = 0;
	}
}

int W[1 << MN];
inline void FWT(int *A) {
	for (int j = 0; j < N2; ++j)
		for (int i = 0; i < 1 << N2; ++i)
			if (i >> j & 1)
				A[i] += A[i ^ 1 << j];
}

int main() {
	scanf("%d%d", &N, &M);
	N1 = N / 2, N2 = N - N1, U = (1 << N2) - 1;
	for (int i = 0; i < M; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		--x, --y;
		++deg[x], ++deg[y];
		mp[x][y] = mp[y][x] = 1;
		if (x > y) std::swap(x, y);
		if (y < N1) u1[c1] = x, v1[c1++] = y;
		else if (x >= N1) u2[c2] = x - N1, v2[c2++] = y - N1;
		else st[x] |= 1 << (y - N1);
	}
	Ans = 2;
	for (int i = 0; i < N; ++i) if (!deg[i]) Ans <<= 1;
	if (M) Ans += 1ll << N;
	ok = 1;
	for (int i = 0; i < N; ++i) if (!vis[i]) ++cnt, DFS(i, 1);
	if (!ok) Ans -= 1ll << cnt;
	for (int S = 0; S < 1 << N2; ++S) {
		int ok = 1;
		for (int i = 0; i < c2; ++i)
			if ((S >> u2[i] & 1) && (S >> v2[i] & 1)) {
				ok = 0;
				break;
			}
		W[S] = ok;
	}
	FWT(W);
	for (int S = 0; S < 1 << N1; ++S) {
		int ok = 1;
		for (int i = 0; i < c1; ++i)
			if ((S >> u1[i] & 1) && (S >> v1[i] & 1)) {
				ok = 0;
				break;
			}
		if (!ok) continue;
		int T = 0;
		for (int i = 0; i < N1; ++i)
			if (S >> i & 1) T |= st[i];
		Ans -= W[T ^ U] * 2;
	}
	printf("%lld\n", Ans);
	return 0;
}