#include <cstdio>
#include <algorithm>

const int MN = 200005;
const int MS = 1 << 19 | 7;

#define li (i << 1)
#define ri (i << 1 | 1)
#define mid ((l + r) >> 1)
#define ls li, l, mid
#define rs ri, mid + 1, r
int mn[MS], tg[MS];
inline void P(int i, int x) { mn[i] += x, tg[i] += x; }
inline void pd(int i) { if (tg[i]) P(li, tg[i]), P(ri, tg[i]), tg[i] = 0; }
void Build(int i, int l, int r) {
	mn[i] = tg[i] = 0;
	if (l == r) return ;
	Build(ls), Build(rs);
}
void Mdf(int i, int l, int r, int a, int b, int x) {
	if (r < a || b < l) return ;
	if (a <= l && r <= b) return P(i, x);
	pd(i), Mdf(ls, a, b, x), Mdf(rs, a, b, x);
	mn[i] = std::min(mn[li], mn[ri]);
}
int Qur(int i, int l, int r, int a, int b, int x) {
	if (r < a || b < l || mn[i] > x) return -1;
	if (l == r) return l;
	pd(i);
	int lpos = Qur(ls, a, b, x);
	return ~lpos ? lpos : Qur(rs, a, b, x);
}

int Ans, MaxLen;
inline void Solve(int *A, int N, int K, int offset) {
	if (N <= MaxLen) return ;
	static int B[MN], C[MN], Lst[MN], stk1[MN], stk2[MN];
	for (int i = 1; i <= N; ++i) B[i] = A[i];
	std::sort(B + 1, B + N + 1);
	int M = std::unique(B + 1, B + N + 1) - B - 1;
	for (int i = 1; i <= N; ++i)
		C[i] = std::lower_bound(B + 1, B + M + 1, A[i]) - B;
	for (int i = 1; i <= M; ++i) Lst[i] = 0;
	int MinL = 1, tp1 = 0, tp2 = 0;
	Build(1, 1, N);
	for (int i = 1; i <= N; ++i) {
		MinL = std::max(MinL, Lst[C[i]] + 1);
		Lst[C[i]] = i;
		for (; tp1 && A[stk1[tp1]] <= A[i]; --tp1)
			Mdf(1, 1, N, stk1[tp1 - 1] + 1, stk1[tp1], A[i] - A[stk1[tp1]]);
		for (; tp2 && A[stk2[tp2]] >= A[i]; --tp2)
			Mdf(1, 1, N, stk2[tp2 - 1] + 1, stk2[tp2], A[stk2[tp2]] - A[i]);
		stk1[++tp1] = stk2[++tp2] = i;
		Mdf(1, 1, N, i, i, i);
		int lpos = Qur(1, 1, N, MinL, i, K + i);
		if (~lpos && MaxLen < i - lpos + 1) {
			MaxLen = i - lpos + 1;
			Ans = lpos + offset;
		}
	}
}

int N, K, D;
int A[MN], R[MN], B[MN], t;

int main() {
	scanf("%d%d%d", &N, &K, &D);
	for (int i = 1; i <= N; ++i) scanf("%d", &A[i]);
	if (D == 0) {
		int mxl = 1, lst = A[1], len = 1, ans = 1;
		for (int i = 2; i <= N; ++i) {
			if (A[i] == lst) ++len;
			else len = 1, lst = A[i];
			if (len > mxl) mxl = len, ans = i - mxl + 1;
		}
		printf("%d %d\n", ans, ans + mxl - 1);
		return 0;
	}
	for (int i = 1; i <= N; ++i) R[i] = (A[i] % D + D) % D;
	for (int i = 1; i <= N; ++i) {
		B[++t] = (A[i] - R[i]) / D;
		if (i == N || R[i] != R[i + 1])
			Solve(B, t, K, i - t), t = 0;
	}
	printf("%d %d\n", Ans, Ans + MaxLen - 1);
	return 0;
}