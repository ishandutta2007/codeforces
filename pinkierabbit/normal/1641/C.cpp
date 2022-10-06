#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int, int> pii;
#define F(i, a, b) for(int i = a; i <= (b); ++i)
#define F2(i, a, b) for(int i = a; i < (b); ++i)
#define dF(i, a, b) for(int i = a; i >= (b); --i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n", __FUNCTION__, __LINE__)
#define MN 200005
#define MQ 200005
#define ll long long
#define mod 998244353
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define pb push_back
#define mkp make_pair
#define fi first
#define se second

void Solve();

int main() {
	int tests = 1;
	while (tests--)
		Solve();
	return 0;
}

int n, q;
int qt[MQ], qo[MQ], ql[MQ], qr[MQ], qp[MQ];
int ans[MN], anst[MN];

#define li (i << 1)
#define ri (li | 1)
#define mid ((l + r) >> 1)
#define ls li, l, mid
#define rs ri, mid + 1, r
const int MS = 1 << 19 | 7;
int len[MS], sum[MS], mx[MS], tag[MS];
void Build(int i, int l, int r) {
	len[i] = r - l + 1;
	if (l == r) return ;
	Build(ls);
	Build(rs);
}
inline void P(int i, int x) { tag[i] = x; }
inline void PushDown(int i) { if (tag[i]) P(li, tag[i]), P(ri, tag[i]), tag[i] = 0; }
void Mdf(int i, int l, int r, int a, int b, int x) {
	if (r < a || b < l) return ;
	if (a <= l && r <= b) return P(i, x);
	PushDown(i);
	Mdf(ls, a, b, x);
	Mdf(rs, a, b, x);
}
void PushUps(int i, int l, int r) {
	if (l == r) {
//		printf("(l, t) = (%d, %d)\n", l, tag[i]);
		if (tag[i])
			sum[i] = 1,
			mx[i] = tag[i],
			ans[l] = -1,
			anst[l] = tag[i];
		else
			sum[i] = 0,
			mx[i] = 0;
		return ;
	}
	PushDown(i);
	PushUps(ls);
	PushUps(rs);
	sum[i] = sum[li] + sum[ri];
	mx[i] = max(mx[li], mx[ri]);
}
int Qsum(int i, int l, int r, int a, int b) {
	if (r < a || b < l) return 0;
	if (a <= l && r <= b) return sum[i];
	return Qsum(ls, a, b) + Qsum(rs, a, b);
}
int Qmx(int i, int l, int r, int a, int b) {
	if (r < a || b < l) return 0;
	if (a <= l && r <= b) return mx[i];
	return max(Qmx(ls, a, b), Qmx(rs, a, b));
}
int Qpos(int i, int l, int r, int a, int b) {
//	printf("Qpos(%d, %d, %d, %d, %d) ; sum=%d, len=%d\n", i, l, r, a, b, sum[i], len[i]);
	if (r < a || b < l) return 0;
	if (a <= l && r <= b) {
		if (sum[i] == len[i])
			return 0;
		if (l == r)
			return l;
		if (sum[li] != len[li])
			return Qpos(ls, a, b);
		else
			return Qpos(rs, a, b);
	}
	int ret = Qpos(ls, a, b);
	if (ret) return ret;
	return Qpos(rs, a, b);
}

void Solve() {
	scanf("%d%d", &n, &q);
	F(i, 1, q) {
		scanf("%d", &qt[i]);
		if (qt[i] == 0)
			scanf("%d%d%d", &ql[i], &qr[i], &qo[i]);
		else
			scanf("%d", &qp[i]);
	}
	Build(1, 1, n);
	dF(i, q, 1)
		if (qt[i] == 0 && qo[i] == 0)
			Mdf(1, 1, n, ql[i], qr[i], i);
	F(i, 1, n)
		anst[i] = q + 1;
	PushUps(1, 1, n);
	F(i, 1, q)
		if (qt[i] == 0 && qo[i] == 1) {
			int s = Qsum(1, 1, n, ql[i], qr[i]);
			int l = qr[i] - ql[i] + 1;
			if (s != l - 1)
				continue;
			int p = Qpos(1, 1, n, ql[i], qr[i]);
			int t = Qmx(1, 1, n, ql[i], qr[i]);
//			printf("(i, [l - r], p, t) = (%d, [%d - %d], %d, %d)\n", i, ql[i], qr[i], p, t);
			ans[p] = 1;
			anst[p] = min(anst[p], max(i, t));
		}
	F(i, 1, q)
		if (qt[i] == 1) {
			int p = qp[i];
//			printf("p = %d, ", p);
			if (!ans[p] || i < anst[p])
				puts("N/A");
			else if (ans[p] == 1)
				puts("YES");
			else
				puts("NO");
		}
}

/*
6 11
0 4 5 0
1 5
1 6
0 4 6 1
1 6
0 2 5 1
1 3
1 2
0 2 2 0
1 3
1 2


5 10
1 3
0 1 5 1
0 2 2 0
0 4 4 0
1 3
0 2 4 1
1 3
0 1 1 0
0 5 5 0
1 3

*/