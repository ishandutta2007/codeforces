#include <cstdio>
#include <cstring>
#include <algorithm>

typedef long long LL;
const int MN = 500005;

void Z(char *str, int N, int *z) {
	z[1] = N;
	for (int i = 2; i <= N; ++i) z[i] = 0;
	for (int i = 2, l = 0, r = 0; i <= N; ++i) {
		if (i <= r) z[i] = std::min(z[i - l + 1], r - i + 1);
		while (i + z[i] <= N && str[i + z[i]] == str[1 + z[i]]) ++z[i];
		if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
	}
}

int N, M, W;
char S1[MN], S2[MN], T1[MN * 2], T2[MN * 2];
char Str[MN * 3];
int z[MN * 3], Zlcp[MN], Zlcs[MN];
LL b1[MN * 2], b2[MN * 2];
inline void Add(LL *b, int i, LL x) { for (; i <= M; i += i & -i) b[i] += x; }
inline LL Qur(LL *b, int i) { LL a = 0; for (; i; i -= i & -i) a += b[i]; return a; }
inline void Mdf(int p, int t) {
	int lcp = std::min(M - 1, Zlcp[p]);
	Add(b1, M - lcp, t), Add(b2, M - lcp, t * lcp);
}
inline LL Qur(int i) {
	return Qur(b2, M - i) - (i - 1) * Qur(b1, M - i);
}
LL Ans;

int main() {
	scanf("%d%d%s%s%s", &N, &M, S1 + 1, S2 + 1, T1 + 1);
	for (int i = 1; i <= M; ++i) T2[i] = T1[M - i + 1];
	std::reverse(S2 + 1, S2 + N + 1);
	for (int i = 1; i <= M; ++i) Str[i] = T1[i]; Str[M + 1] = 'A';
	for (int i = 1; i <= N; ++i) Str[M + 1 + i] = S1[i];
	Z(Str, M + 1 + N, z);
	for (int i = 1; i <= N; ++i) Zlcp[i] = z[M + 1 + i];
	for (int i = 1; i <= M; ++i) Str[i] = T2[i]; Str[M + 1] = 'A';
	for (int i = 1; i <= N; ++i) Str[M + 1 + i] = S2[i];
	Z(Str, M + 1 + N, z);
	for (int i = 1; i <= N; ++i) Zlcs[i] = z[M + 1 + N - i + 1];
	for (int i = 1; i <= N; ++i) {
		Mdf(i, 1);
		if (i >= M) Mdf(i - M + 1, -1);
		int lcs = std::min(M - 1, Zlcs[i]);
		if (!lcs) continue;
		Ans += Qur(M - lcs);
	}
	printf("%lld\n", Ans);
	return 0;
}