#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;

int ask(ll x, ll y) {
	printf("%lld %lld\n", x, y);
	fflush(stdout);
	int o; scanf("%d", &o);
	if (!o) exit(0);
	return o;
}


int main() {
	scanf("%lld", &n);
	ll xl = 1, xm = n, xr = n;
	ll yl = 1, ym = n, yr = n;
	for (; ;) {
		long double sa = (long double)(xm - xl) * (ym - yl);
		long double sb = (long double)(xm - xl) * (yr - ym);
		long double sc = (long double)(xr - xm) * (ym - yl);
		ll xx = (xl + xm) >> 1, yy = (yl + ym) >> 1;
		if (sb > sa + sc) yy = ym;
		else if (sc > sa + sb) xx = xm;
		int d = ask(xx, yy);
		if (d == 1) xl = xx + 1;
		else if (d == 2) yl = yy + 1;
		else {
			xm = xx - 1; ym = yy - 1;
		}
		if (xl > xm) {
			xm = xr; yr = ym;
		}
		if (yl > ym) {
			ym = yr; xr = xm;
		}
		if (xm == xr) ym = yr;
		if (ym == yr) xm = xr;
		xr = max(xr, xm); yr = max(yr, ym);
	}
}