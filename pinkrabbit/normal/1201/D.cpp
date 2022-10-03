#include <bits/stdc++.h>
using namespace std;

#define F(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)
#define dF(i, a, b) for (int i = (int)(a); i >= (int)(b); --i)
#define F2(i, a, b) for (int i = (int)(a); i < (int)(b); ++i)
#define vF(i, v) for (auto i : V)

typedef long long LL;
typedef pair<int, int> pii;

#define pb push_back
#define mp make_pair
#define fi first
#define se second

const int MN = 300005;
const int MM = 600005;
const int Inf = 0x3f3f3f3f;
const LL Infll = 0x3f3f3f3f3f3f3f3f;

int N, M, K, Q, MaxX;
int Vmax[MN], Vmin[MN];
int nl[MN], nr[MN];
LL Ans;

inline int Dis(int x, int y) { return x < y ? y - x : x - y; }

int main() {
	scanf("%d%d%d%d", &N, &M, &K, &Q);
	F(i, 1, N) Vmax[i] = 0, Vmin[i] = M + 1;
	F(i, 1, K) {
		int x, y;
		scanf("%d%d", &x, &y);
		Vmax[x] = max(Vmax[x], y);
		Vmin[x] = min(Vmin[x], y);
		MaxX = max(MaxX, x);
	}
	Ans = MaxX - 1;
	F(i, 1, Q) {
		int x;
		scanf("%d", &x);
		nl[x] = nr[x] = x;
	}
	F(i, 1, M) if (!nl[i]) nl[i] = nl[i - 1];
	dF(i, M, 1) if (!nr[i]) nr[i] = nr[i + 1];
	int lp = 1, rp = 1;
	LL lf = 0, rf = 0;
	F(n, 1, MaxX) {
		if (!Vmax[n]) continue;
		int lb = Vmin[n], rb = Vmax[n];
		LL lg = Infll, rg = Infll;
		Ans += rb - lb;
		if (n == 1) {
			lg = rb - 1;
			rg = lb - 1;
		}
		else {
			if (nl[lp]) lg = min(lg, lf + (lp - nl[lp]) + Dis(nl[lp], rb));
			if (nr[lp]) lg = min(lg, lf + (nr[lp] - lp) + Dis(nr[lp], rb));
			if (nl[lp]) rg = min(rg, lf + (lp - nl[lp]) + Dis(nl[lp], lb));
			if (nr[lp]) rg = min(rg, lf + (nr[lp] - lp) + Dis(nr[lp], lb));
			if (nl[rp]) lg = min(lg, rf + (rp - nl[rp]) + Dis(nl[rp], rb));
			if (nr[rp]) lg = min(lg, rf + (nr[rp] - rp) + Dis(nr[rp], rb));
			if (nl[rp]) rg = min(rg, rf + (rp - nl[rp]) + Dis(nl[rp], lb));
			if (nr[rp]) rg = min(rg, rf + (nr[rp] - rp) + Dis(nr[rp], lb));
		}
		lp = lb, rp = rb;
		lf = lg, rf = rg;
//		printf(" %d : %lld, %lld\n", n, lf, rf);
	}
	printf("%lld\n", Ans + min(lf, rf));
	return 0;
}