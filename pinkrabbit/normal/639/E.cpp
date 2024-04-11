#include <cstdio>
#include <algorithm>

typedef long long LL;
typedef double re;
const int MN = 150005;

int N;
struct dat {
	int p, t;
	LL l, r;
} a[MN];

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i) scanf("%d", &a[i].p);
	for (int i = 1; i <= N; ++i) scanf("%d", &a[i].t);
	std::sort(a + 1, a + N + 1, [](dat i, dat j) { return (LL)j.p * i.t < (LL)i.p * j.t; });
	LL sumt = 0;
	for (int i = 1, j; i <= N; i = j + 1) {
		for (j = i; j < N && (LL)a[j + 1].p * a[j].t == (LL)a[j].p * a[j + 1].t; ++j) ;
		for (int k = i; k <= j; ++k) a[k].l = sumt + a[k].t;
		for (int k = i; k <= j; ++k) sumt += a[k].t;
		for (int k = i; k <= j; ++k) a[k].r = sumt;
	}
	std::sort(a + 1, a + N + 1, [](dat i, dat j) { return i.p < j.p; });
	re ans = 1;
	for (int i = 1; i < N; ++i) if (a[i].p != a[i + 1].p) {
		LL mn = sumt, mx = 0;
		for (int j = i; a[j].p == a[i].p; --j)
			mn = std::min(mn, a[j].l);
		for (int j = i + 1; a[j].p == a[i + 1].p; ++j)
			mx = std::max(mx, a[j].r);
		re val = (re)sumt * (a[i + 1].p - a[i].p) / ((re)mx * a[i + 1].p - (re)mn * a[i].p);
		if (val >= -1e-11) ans = std::min(ans, val);
	}
	printf("%.11lf\n", ans);
	return 0;
}