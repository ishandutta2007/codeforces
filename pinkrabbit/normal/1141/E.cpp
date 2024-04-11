#include <cstdio>
#include <algorithm>

typedef long long LL;
const int MN = 200005;

int N;
LL H, A[MN], S[MN];

int main() {
	scanf("%lld%d", &H, &N);
	for (int i = 1; i <= N; ++i)
		scanf("%lld", &A[i]), S[i] = S[i - 1] + A[i];
	for (int i = 1; i <= N; ++i)
		if (H + S[i] <= 0) return printf("%d\n", i), 0;
	if (S[N] >= 0) return puts("-1"), 0;
	LL Mn = *std::min_element(S + 1, S + N + 1);
	LL Seq = (H + Mn - 1) / -S[N] + 1;
	H += Seq * S[N];
	for (int i = 1; i <= N; ++i)
		if (H + S[i] <= 0) return printf("%lld\n", Seq * N + i), 0;
	return 0;
}

// lg