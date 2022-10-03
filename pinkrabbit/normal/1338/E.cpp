#include <cstdio>
#include <cctype>
#include <algorithm>
#include <vector>

typedef long long LL;
const int MN = 8005;

char s[MN];
int N, deg[MN], bel[MN], num[MN];
std::vector<bool> A[MN];
int que[MN], lb, rb;
LL Ans;

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i) {
		scanf("%s", s + 1);
		A[i].resize(N + 1);
		for (int j = 1; j <= N / 4; ++j) {
			int x = isdigit(s[j]) ? s[j] - '0' : 10 + (s[j] - 'A');
			for (int k = 0; k < 4; ++k)
				A[i][4 * j - k] = x >> k & 1;
		}
	}
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j) if (A[i][j])
			++deg[j];
	int C = N;
	lb = 1, rb = 0;
	for (int i = 1; i <= N; ++i) if (!deg[i]) que[++rb] = i;
	while (lb <= rb) {
		int u = que[lb++];
		bel[u] = 3;
		Ans += (614ll * N + 1) * --C;
		for (int i = 1; i <= N; ++i) if (A[u][i])
			if (!--deg[i]) que[++rb] = i;
	}
	if (!C) return printf("%lld\n", Ans), 0;
	int x = std::max_element(deg + 1, deg + N + 1) - deg;
	for (int i = 1; i <= N; ++i) if (bel[i] != 3)
		bel[i] = i == x || A[i][x] ? 1 : 2;
	for (int i = 1; i <= N; ++i) if (bel[i] != 3)
		for (int j = 1; j <= N; ++j) if (i != j && bel[j] != 3)
			if (bel[i] != bel[j] && A[i][j]) ++num[j];
	for (int i = 1; i < N; ++i) if (bel[i] != 3)
		for (int j = i + 1; j <= N; ++j) if (bel[j] != 3)
			Ans += 3 + (bel[i] == bel[j] && num[i] == num[j]);
	printf("%lld\n", Ans);
	return 0;
}