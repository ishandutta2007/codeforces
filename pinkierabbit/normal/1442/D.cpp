#include <cstdio>
#include <algorithm>
#include <numeric>
#include <vector>

typedef long long LL;
const int MN = 3005, LOGN = 13, MK = 3005;

int N, K, len[MN];
std::vector<LL> A[MN];

LL f[LOGN][MK], Ans;
void Solve(int l, int r, int w) {
	if (l == r) {
		for (int k = 1; k <= K && k <= len[l]; ++k)
			Ans = std::max(Ans, f[w][K - k] + A[l][k]);
		return ;
	}
	int mid = (l + r) / 2;
	LL *g = f[w + 1];
	std::copy(f[w], f[w] + K + 1, g);
	for (int i = r; i > mid; --i)
		for (int j = K; j >= len[i]; --j)
			g[j] = std::max(g[j], g[j - len[i]] + A[i][len[i]]);
	Solve(l, mid, w + 1);
	std::copy(f[w], f[w] + K + 1, g);
	for (int i = l; i <= mid; ++i)
		for (int j = K; j >= len[i]; --j)
			g[j] = std::max(g[j], g[j - len[i]] + A[i][len[i]]);
	Solve(mid + 1, r, w + 1);
}

int main() {
	scanf("%d%d", &N, &K);
	for (int i = 1; i <= N; ++i) {
		scanf("%d", &len[i]);
		A[i].resize(len[i] + 1);
		for (int j = 1; j <= len[i]; ++j)
			scanf("%lld", &A[i][j]),
			A[i][j] += A[i][j - 1];
	}
	Solve(1, N, 0);
	printf("%lld\n", Ans);
	return 0;
}