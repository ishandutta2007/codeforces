#include <cstdio>
#include <algorithm>

typedef long long LL;
const int MN = 100005;

int N, Q;
int A[MN], B[MN];
LL S[MN], min[17][MN], max[17][MN];

int main() {
	scanf("%d%d", &N, &Q);
	for (int i = 1; i <= N; ++i) scanf("%d", &A[i]);
	for (int i = 1; i <= N; ++i) scanf("%d", &B[i]);
	for (int i = 1; i <= N; ++i) S[i + 1] = S[i] + B[i] - A[i];
	++N;
	for (int i = 1; i <= N; ++i) min[0][i] = max[0][i] = S[i];
	for (int j = 0; 2 << j <= N; ++j)
		for (int i = 2 << j; i <= N; ++i)
			min[j + 1][i] = std::min(min[j][i], min[j][i - (1 << j)]),
			max[j + 1][i] = std::max(max[j][i], max[j][i - (1 << j)]);
	while (Q--) {
		int l, r;
		scanf("%d%d", &l, &r);
		++r;
		if (S[l] != S[r]) { puts("-1"); continue; }
		int j = 31 - __builtin_clz(r - l + 1);
		LL mn = std::min(min[j][l + (1 << j) - 1], min[j][r]);
		if (mn < S[l]) { puts("-1"); continue; }
		LL mx = std::max(max[j][l + (1 << j) - 1], max[j][r]);
		printf("%lld\n", mx - S[l]);
	}
	return 0;
}