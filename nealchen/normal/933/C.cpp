#include <stdio.h>
#include <string.h>
#include <algorithm>
#define sqr(x) ((x) * (x))
//Ax+By=C
struct L {double A, B, C;};
int n, x[3], y[3], r[3], a[3];
int pos(register int i, register int j) {
	register int d = sqr(x[i] - x[j]) + sqr(y[i] - y[j]), inner = sqr(r[i] - r[j]), outer = sqr(r[i] + r[j]);
	if(d < inner) return 0;
	if(d == inner) return 1;
	if(d < outer) return 2;
	if(d == outer) return 3;
	return 4;
}
L root(register int i, register int j) {
	return (L){2.0*(x[i]-x[j]), 2.0*(y[i]-y[j]), sqr(x[i]) + sqr(y[i]) - sqr(r[i]) - sqr(x[j]) - sqr(y[j]) + sqr(r[j])};
}
int main() {
	register int i;
	scanf("%d", &n);
	for(i = 0; i < n; ++i) scanf("%d%d%d", &x[i], &y[i], &r[i]);
	if(n == 1) return !printf("2");
	if(n == 2) return !printf("%d", 3 + (pos(0, 1) == 2));
	a[0] = pos(1, 2), a[1] = pos(2, 0), a[2] = pos(0, 1);
	register int ans = 4 + (a[0] == 2) + (a[1] == 2) + (a[2] == 2);
	if(ans == 7) ++ans;
	if(ans == 6 && (a[0]%2 + a[1]%2 + a[2]%2) == 1) ++ans;
	if(ans == 5 && (a[0]%2 + a[1]%2 + a[2]%2) == 2) ++ans;
	if(ans == 4 && (a[0]%2 + a[1]%2 + a[2]%2) == 3) ++ans;
	if(a[0] >= 1 && a[0] <= 3 && a[1] >= 1 && a[1] <= 3 && a[2] >= 1 && a[2] <= 3) {
		L u = root(0, 1), v = root(1, 2), w = root(2, 0);
		if(u.A * v.B - u.B * v.A == 0) {
			if(u.C * v.A == v.C * u.A && u.C * v.B == v.C * u.B) --ans;
			if(a[0] == 2 && a[1] == 2 && a[2] == 2 && u.C * w.A == w.C * u.A && u.C * w.B == w.C * u.B) --ans;
		} else {
			register double xx = (u.C * v.B - v.C * u.B) / (u.A * v.B - u.B * v.A);
			register double yy = (u.C * v.A - v.C * u.A) / (u.B * v.A - u.A * v.B);
			if(sqr(xx - x[0]) + sqr(yy - y[0]) == sqr(r[0])) --ans;
		}
	}
	printf("%d\n", ans);
	return 0;
}