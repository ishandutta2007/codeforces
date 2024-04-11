#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <iterator>
using namespace std;

typedef pair<int, int> pii;
#define F(i, a, b) for(int i = a; i <= (b); ++i)
#define F2(i, a, b) for(int i = a; i < (b); ++i)
#define dF(i, a, b) for(int i = a; i >= (b); --i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n", __FUNCTION__, __LINE__)
#define MN 200005
#define MM 16000005
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
//	scanf("%d", &tests);
	while (tests--)
		Solve();
	return 0;
}

int n, A[MN], iA[MN];

#define mid ((l + r) >> 1)
int lc[MM], rc[MM], dat[MM], cnt;
void Mdf(int &rt, int l, int r, int p, int x) {
	++cnt, lc[cnt] = lc[rt], rc[cnt] = rc[rt], dat[cnt] = dat[rt], rt = cnt;
	if (l == r) return dat[rt] = x, void();
	if (p <= mid)
		Mdf(lc[rt], l, mid, p, x);
	else
		Mdf(rc[rt], mid + 1, r, p, x);
	dat[rt] = dat[lc[rt]] | dat[rc[rt]];
//	printf("Mdf(%d, %d, %d, %d, %d) : dat(%d) = %d\n", rt, l, r, p, x, rt, dat[rt]);
}
int Qur1(int rt, int l, int r, int a) {
//	printf("Qur1(%d, %d, %d, %d)\n", rt, l, r, a);
	if (!rt || r < a) return 0;
	if (a <= l) {
		if (~dat[rt] & 1)
			return 0;
		if (l == r) return l;
//		printf("dat[%d .. %d](%d) = %d\n", l, mid, lc[rt], dat[lc[rt]]);
		if (dat[lc[rt]] & 1)
			return Qur1(lc[rt], l, mid, a);
		return Qur1(rc[rt], mid + 1, r, a);
	}
	int ret = Qur1(lc[rt], l, mid, a);
	if (ret) return ret;
	return Qur1(rc[rt], mid + 1, r, a);
}
int Qur2(int rt, int l, int r, int a, int b) {
	if (!rt || r < a || b < l) return 0;
	if (a <= l && r <= b) return dat[rt] >> 1 & 1;
	int ret = Qur2(lc[rt], l, mid, a, b) | Qur2(rc[rt], mid + 1, r, a, b);
//	printf("Qur2(%d, %d, %d, %d, %d) = %d\n", rt, l, r, a, b, ret);
	return ret;
}

int rt1[MN], rt2[MN];

void Solve() {
	scanf("%d", &n);
	F(i, 1, n) scanf("%d", A + i), iA[A[i]] = i;
	{
		set<int> st;
		F(i, 1, n) {
			auto it = st.insert(iA[i]).fi;
			int p1 = iA[i];
			int p2 = next(it) == st.end() ? 0 : *next(it);
			int rt = rt1[i - 1];
			Mdf(rt, 1, n, p1, 1);
			if (p2) Mdf(rt, 1, n, p2, 3);
			rt1[i] = rt;
		}
	}
	{
		set<int> st;
		dF(i, n, 1) {
			auto it = st.insert(iA[i]).fi;
			int p1 = iA[i];
			int p2 = next(it) == st.end() ? 0 : *next(it);
			int rt = rt2[i + 1];
			Mdf(rt, 1, n, p1, 1);
			if (p2) Mdf(rt, 1, n, p2, 3);
			rt2[i] = rt;
//			printf("%d : (%d : %d) ,  (%d : %d)\n", i, p1, 1, p2, 3);
		}
	}
	ll ans = 0;
	static int stk1[MN], stk2[MN];
	int tp1 = 0, tp2 = 0;
	int lb = 1;
	F(i, 1, n) {
		while (tp1 && A[stk1[tp1]] < A[i]) --tp1;
		while (tp2 && A[stk2[tp2]] > A[i]) --tp2;
		while (true) {
//			printf("check for [%d .. %d]\n", lb, i);
			if (tp1 && stk1[tp1] >= lb + 2) {
				int r = stk1[tp1] - 1;
				int p = Qur1(rt1[A[i] - 1], 1, n, lb);
				if (p && p + 1 <= r && Qur2(rt1[A[i] - 1], 1, n, p + 1, r)) {
//					printf("wtf1");
					goto gg; }
			}
			if (tp2 && stk2[tp2] >= lb + 2) {
				int r = stk2[tp2] - 1;
				int p = Qur1(rt2[A[i] + 1], 1, n, lb);
//				printf("p = %d, ", p);
				if (p && p + 1 <= r && Qur2(rt2[A[i] + 1], 1, n, p + 1, r)) {
//					printf("wtf2");
					goto gg; }
			}
			break;
			gg: ++lb;
//			printf("\tgg.\n");
		}
//		printf("i = %d, lb = %d\n", i, lb);
		ans += i - lb + 1;
		stk1[++tp1] = i;
		stk2[++tp2] = i;
	}
	printf("%lld\n", ans);
}