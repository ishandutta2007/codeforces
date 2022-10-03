#include <cstdio>
#include <algorithm>

typedef long long LL;
const int MN = 500005;

int N;
LL val, A[MN], S[MN];

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= (N + 1) / 2; ++i) scanf("%lld", &A[i]), S[i] = S[i - 1] + A[i];
	scanf("%lld", &val);
	for (int i = (N + 3) / 2; i <= N; ++i) A[i] = val, S[i] = S[i - 1] + A[i];
	if (val >= 0) return printf("%d\n", S[N] > 0 ? N : -1), 0;
	int mid = (N + 1) / 2, maxlen = N;
	for (int i = 1; i <= mid; ++i) {
		if (S[mid] - S[i - 1] <= 0) return puts("-1"), 0;
		LL num = (S[mid] - S[i - 1] - 1) / -val;
		int nlen = std::min(mid + num, (LL)N) - i + 1;
		maxlen = std::min(maxlen, nlen);
		if (N - i + 1 <= maxlen) return printf("%d\n", N - i + 1), 0;
	}
	puts("-1");
	return 0;
}