#include <cstdio>

typedef double r64;
const r64 eps = 1e-9;
const int MN = 2005;

int N, ca, cb;
r64 a[MN], b[MN];
r64 v[MN]; int ua[MN];

void solve(r64 xa) {
	static r64 _v[MN];
	static int _ua[MN];
	for (int j = 0; j <= cb; ++j) v[j] = 0, ua[j] = 0;
	for (int i = 1; i <= N; ++i) {
		for (int j = 0; j <= cb; ++j) _v[j] = v[j], _ua[j] = ua[j];
		for (int j = 0; j < cb; ++j) {
			if (_v[j + 1] < v[j] + b[i]) {
				_v[j + 1] = v[j] + b[i];
				_ua[j + 1] = ua[j];
			}
		}
		for (int j = 0; j <= cb; ++j) {
			if (_v[j] < v[j] + a[i] - xa) {
				_v[j] = v[j] + a[i] - xa;
				_ua[j] = ua[j] + 1;
			}
		}
		for (int j = 0; j < cb; ++j) {
			if (_v[j + 1] < v[j] + a[i] + b[i] - a[i] * b[i] - xa) {
				_v[j + 1] = v[j] + a[i] + b[i] - a[i] * b[i] - xa;
				_ua[j + 1] = ua[j] + 1;
			}
		}
		for (int j = 0; j <= cb; ++j) v[j] = _v[j], ua[j] = _ua[j];
	}
}

int main() {
	scanf("%d%d%d", &N, &ca, &cb);
	for (int i = 1; i <= N; ++i) scanf("%lf", &a[i]);
	for (int i = 1; i <= N; ++i) scanf("%lf", &b[i]);
	r64 la = 0, ra = 1, ma, va = 1;
	while (ra - la > eps) {
		ma = (la + ra) / 2;
		solve(ma);
		if (ua[cb] <= ca) va = ma, ra = ma;
		else la = ma;
	}
	solve(va);
	printf("%.5lf\n", v[cb] + ca * va);
	return 0;
}