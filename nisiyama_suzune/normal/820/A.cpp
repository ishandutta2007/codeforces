#include <bits/stdc++.h>

int main () {
	int c, v0, v1, a, l;
	scanf ("%d%d%d%d%d", &c, &v0, &v1, &a, &l);
	int r = v0, t = 1, s = v0 + a;
	for (; r < c; ++t) {
		r -= l;
		r += (s > v1) ? v1 : s;
		s += a;
	}
	printf ("%d\n", t);
}