#include <cstdio>
#include <cstring>

typedef long long LL;
typedef double db;
const int MN = 100005;

int N, A[MN];
LL pre[MN], suf[MN], Inv;
LL b0[MN], b1[MN], b2[MN];
inline void add(LL *b, int i, LL x) { for (; i <= N; i += i & -i) b[i] += x; }
inline LL qur(LL *b, int i) { LL a = 0; for (; i; i -= i & -i) a += b[i]; return a; }
db Ans;

int main() {
	scanf("%d", &N), Ans = (db)(N - 1) * (N + 2) / 24;
	for (int i = 1; i <= N; ++i) scanf("%d", &A[i]);
	for (int i = 1; i <= N; ++i) add(b0, A[i], 1), pre[i] = pre[i - 1] + i - qur(b0, A[i]);
	Inv = pre[N], memset(b0, 0, sizeof b0);
	for (int i = N; i >= 1; --i) suf[i] = suf[i + 1] + qur(b0, A[i]), add(b0, A[i], 1);
	Ans += 2 * Inv;
	for (int i = 1; i <= N; ++i) Ans -= 2. * (i * pre[i] + (N - i + 1) * suf[i]) / N / (N + 1);
	memset(b0, 0, sizeof b0);
	for (int i = N; i >= 1; --i) {
		Ans -= (db)(qur(b2, A[i]) * i * i + qur(b1, A[i]) * i + qur(b0, A[i])) / N / (N + 1);
		add(b0, A[i], (LL)i * (i - 1));
		add(b1, A[i], 1 - 2 * i);
		add(b2, A[i], 1);
	}
	printf("%.15lf\n", Ans);
	return 0;
}