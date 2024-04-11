#include <cstdio>
#include <algorithm>

const int MN = 200005;

int N, A[MN], per[MN], Ans[MN];

#define li (i << 1)
#define ri (li | 1)
#define mid ((l + r) >> 1)
#define ls li, l, mid
#define rs ri, mid + 1, r
const int MS = 1 << 19 | 7;
struct dat {
	int s, l, r;
	dat() {}
	dat(int S, int L, int R) : s(S), l(L), r(R) {}
	friend dat operator + (dat p, dat q) {
		return dat(p.s + q.s, std::max(p.l, p.s + q.l), std::max(q.r, q.s + p.r));
	}
} tr[MS];
void Build(int i, int l, int r) {
	if (l == r) {
		tr[i] = dat(-1, -1, -1);
		return ;
	}
	Build(ls), Build(rs);
	tr[i] = tr[li] + tr[ri];
}
void Mdf(int i, int l, int r, int p) {
	if (l == r) return tr[i] = dat(1, 1, 1), void();
	p <= mid ? Mdf(ls, p) : Mdf(rs, p);
	tr[i] = tr[li] + tr[ri];
}
dat Qur(int i, int l, int r, int a, int b) {
	if (r < a || b < l) return dat(0, 0, 0);
	if (a <= l && r <= b) return tr[i];
	return Qur(ls, a, b) + Qur(rs, a, b);
}

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i)
		scanf("%d", &A[i]), per[i] = i;
	std::sort(per + 1, per + N + 1, [](int i, int j) {
		return A[i] < A[j];
	});
	Build(1, 1, N);
	for (int i = 1; i <= N; ++i) {
		int j = i;
		while (j < N && A[per[j + 1]] == A[per[i]]) ++j;
		for (int k = i; k <= j; ++k)
			Mdf(1, 1, N, per[k]);
		for (int k = i; k <= j; ++k) {
			int p = per[k];
			dat q1 = Qur(1, 1, N, 1, p);
			dat q2 = Qur(1, 1, N, p, N);
			Ans[p] = std::max(Ans[p], (q1.r + q2.l) / 2 - 1);
		}
		i = j;
	}
	Build(1, 1, N);
	for (int i = N; i >= 1; --i) {
		int j = i;
		while (j > 1 && A[per[j - 1]] == A[per[i]]) --j;
		for (int k = i; k >= j; --k)
			Mdf(1, 1, N, per[k]);
		for (int k = i; k >= j; --k) {
			int p = per[k];
			dat q1 = Qur(1, 1, N, 1, p);
			dat q2 = Qur(1, 1, N, p, N);
			Ans[p] = std::max(Ans[p], (q1.r + q2.l - 1) / 2);
		}
		i = j;
	}
	for (int i = 1; i <= N; ++i)
		printf("%d%c", Ans[i], " \n"[i == N]);
	return 0;
}