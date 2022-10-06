#include <cstdio>
#include <algorithm>

typedef long long LL;
const int MN = 200005, MS = 1 << 19 | 7;

int N, Q;
int A[MN];

#define li (i << 1)
#define ri (li | 1)
#define mid ((l + r) >> 1)
#define ls li, l, mid
#define rs ri, mid + 1, r
int len[MS];
int mnv[MS], tg[MS];
LL sum[MS];
inline void P(int i, int x) {
	mnv[i] = x;
	sum[i] = (LL)len[i] * x;
	tg[i] = x;
}
inline void PushDown(int i) {
	if (tg[i]) P(li, tg[i]), P(ri, tg[i]), tg[i] = 0;
}
inline void PushUp(int i) {
	mnv[i] = mnv[ri];
	sum[i] = sum[li] + sum[ri];
}
void Build(int i, int l, int r) {
	len[i] = r - l + 1;
	if (l == r) {
		mnv[i] = A[l];
		sum[i] = A[l];
		return ;
	}
	Build(ls), Build(rs);
	PushUp(i);
}
void Mdf(int i, int l, int r, int a, int b, int x) {
	if (r < a || b < l) return ;
	if (a <= l && r <= b) return P(i, x);
	PushDown(i);
	Mdf(ls, a, b, x), Mdf(rs, a, b, x);
	PushUp(i);
}
int Find(int i, int l, int r, int x) {
	if (l == r) return mnv[i] <= x ? l : l + 1;
	PushDown(i);
	if (mnv[li] <= x) return Find(ls, x);
	else return Find(rs, x);
}
int Qur(int i, int l, int r, int p, int &x) {
	if (p <= l && sum[i] <= x) return x -= (int)sum[i], r;
	if (l == r) {
		if (mnv[i] <= x) return x -= mnv[i], l;
		return l - 1;
	}
	PushDown(i);
	int ret = 0;
	if (p <= mid) {
		ret = Qur(ls, p, x);
		if (ret == mid) ret = Qur(rs, p, x);
	} else ret = Qur(rs, p, x);
	return ret;
}

int main() {
	scanf("%d%d", &N, &Q);
	for (int i = 1; i <= N; ++i) scanf("%d", &A[i]);
	Build(1, 1, N);
	for (int i = 1; i <= Q; ++i) {
		int op, x, y;
		scanf("%d%d%d", &op, &x, &y);
		if (op == 1) {
			int pos = Find(1, 1, N, y);
			if (pos <= x) Mdf(1, 1, N, pos, x, y);
		}
		if (op == 2) {
			int Ans = 0;
			while (x <= N) {
				int pos = std::max(Find(1, 1, N, y), x);
				if (pos > N) break;
				x = Qur(1, 1, N, pos, y) + 1;
				Ans += x - pos;
			}
			printf("%d\n", Ans);
		}
	}
	return 0;
}