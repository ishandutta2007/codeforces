#include <cstdio>
#include <vector>

typedef long long LL;
const int Mod = 1000000007;
const int MN = 2005, MM = 4005;

int N, M, uv[MM];
std::vector<int> G[MN];
int vis[MN];
int len[MN], k;

void DFS(int u, int p, int d) {
	vis[u] = 1;
	for (int e : G[u]) if (e != p) {
		int v = uv[e] ^ u;
		if (v == 1) {
			len[++k] = d + 1;
			return ;
		}
		DFS(v, e, d + 1);
	}
}

int A[MM * 2], S;
int Ans;

int main() {
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= M; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		uv[i] = x ^ y;
		G[x].push_back(i);
		G[y].push_back(i);
	}
	for (int e : G[1]) if (!vis[uv[e] ^ 1]) DFS(uv[e] ^ 1, e, 1);
	S = 2 * M;
	A[0] = 1;
	for (int i = 1; i <= k; ++i) {
		for (int j = S; j >= len[i]; --j) {
			A[j] = (A[j] + A[j - len[i]]) % Mod;
			if (j >= 2 * len[i])
				A[j] = (A[j] + A[j - 2 * len[i]]) % Mod;
		}
	}
	for (int i = 1; i <= k; ++i) {
		for (int j = len[i]; j <= S; ++j) {
			A[j] = (A[j] - A[j - len[i]] + Mod) % Mod;
			if (j >= 2 * len[i])
				A[j] = (A[j] - A[j - 2 * len[i]] + Mod) % Mod;
		}
		int rad = len[i] - 2;
		int lb = M - len[i] - rad;
		int rb = M - len[i] + rad;
		lb = std::max(lb, 0);
		rb = std::min(rb, S - 2 * len[i]);
		for (int j = lb; j <= rb; ++j)
			Ans = (Ans + A[j]) % Mod;
		for (int j = S; j >= len[i]; --j) {
			A[j] = (A[j] + A[j - len[i]]) % Mod;
			if (j >= 2 * len[i])
				A[j] = (A[j] + A[j - 2 * len[i]]) % Mod;
		}
	}
	Ans = 2 * Ans % Mod;
	for (int i = 0; i <= S; ++i) A[i] = 0;
	A[0] = 1;
	for (int i = 1; i <= k; ++i)
		for (int j = M; j >= len[i]; --j)
			A[j] = (A[j] + A[j - len[i]]) % Mod;
	if (M & 1) {
		int T = (M + 1) / 2;
		for (int i = 1; i <= k; ++i) {
			for (int j = len[i]; j <= M; ++j)
				A[j] = (A[j] - A[j - len[i]] + Mod) % Mod;
			if (T >= len[i]) Ans = (Ans + 4ll * A[T - len[i]]) % Mod;
			for (int j = M; j >= len[i]; --j)
				A[j] = (A[j] + A[j - len[i]]) % Mod;
		}
	} else Ans = (Ans + A[M / 2]) % Mod;
	printf("%d\n", Ans);
	return 0;
}