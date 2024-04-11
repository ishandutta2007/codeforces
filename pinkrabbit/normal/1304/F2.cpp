#include <cstdio>
#include <algorithm>

const int MM = 20005;

int N, M, K, A0[MM], A1[MM], S0[MM], S1[MM];
int f[MM], g[MM];
int que[MM], id[MM];

int main() {
	scanf("%d%d%d", &N, &M, &K);
	for (int j = 1; j <= M; ++j) scanf("%d", &A0[j]);
	for (int _ = 1; _ <= N; ++_) {
		for (int i = 1; i <= M; ++i) _ < N ? scanf("%d", &A1[i]) : A1[i] = 0;
		for (int i = 1; i <= M; ++i) S0[i] = S0[i - 1] + A0[i], S1[i] = S1[i - 1] + A1[i];
		if (_ == 1) {
			for (int i = 1; i <= M - K + 1; ++i) f[i] = S0[i + K - 1] - S0[i - 1] + S1[i + K - 1] - S1[i - 1];
			std::swap(A0, A1);
			continue;
		}
		for (int i = 1; i <= M - K + 1; ++i) g[i] = 0;
		int val = 0, l = 1, r = 0, bias = 0;
		for (int i = 1; i <= M - K + 1; ++i) {
			if (i > K) val = std::max(val, f[i - K]);
			bias += A0[i - 1];
			int vnow = f[i] - S0[i + K - 1] + S0[i - 1] - bias;
			while (l <= r && que[r] <= vnow) --r;
			que[++r] = vnow, id[r] = i;
			while (l <= r && id[l] <= i - K) ++l;
			g[i] = std::max({g[i], val, que[l] + bias});
		}
		val = 0, l = 1, r = 0, bias = 0;
		for (int i = M - K + 1; i >= 1; --i) {
			if (i <= M - 2 * K + 1) val = std::max(val, f[i + K]);
			bias += A0[i + K];
			int vnow = f[i] - S0[i + K - 1] + S0[i - 1] - bias;
			while (l <= r && que[r] <= vnow) --r;
			que[++r] = vnow, id[r] = i;
			while (l <= r && id[l] >= i + K) ++l;
			g[i] = std::max({g[i], val, que[l] + bias});
		}
		for (int i = 1; i <= M - K + 1; ++i) g[i] += S0[i + K - 1] - S0[i - 1] + S1[i + K - 1] - S1[i - 1];
		std::swap(A0, A1);
		std::swap(f, g);
	}
	printf("%d\n", *std::max_element(f + 1, f + M - K + 2));
	return 0;
}