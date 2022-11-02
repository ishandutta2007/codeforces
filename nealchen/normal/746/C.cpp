#include <stdio.h>
#include <algorithm>
int main() {
	int s, x1, x2, t1, t2, p, d;
	scanf("%d%d%d%d%d%d%d", &s, &x1, &x2, &t1, &t2, &p, &d);
	if(d == 1) {
		if(x1 > x2) {
			printf("%d\n", std::min((x1 - x2) * t2, (2 * s - x2 - p) * t1));
		} else if(p <= x1) {
			printf("%d\n", std::min((x2 - x1) * t2, (x2 - p) * t1));
		} else {
			printf("%d\n", std::min((x2 - x1) * t2, (x2 - p + 2 * s) * t1));
		}
	} else {
		if(x1 < x2) {
			printf("%d\n", std::min((x2 - x1) * t2, (x2 + p) * t1));
		} else if(p >= x1) {
			printf("%d\n", std::min((x1 - x2) * t2, (p - x2) * t1));
		} else {
			printf("%d\n", std::min((x1 - x2) * t2, (p - x2 + 2 * s) * t1));
		}
	}
	return 0;
}