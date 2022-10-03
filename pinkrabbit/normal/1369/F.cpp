#include <cstdio>

typedef long long LL;

int calc(LL s, LL e, int a1, int a2) {
	return s > e ? s & 1 ? a1 : a2 : calc(s, e / 2, a2 ? a1 ? ~e & 1 : 0 : 1, a2 && a1 ? e & 1 : 1);
}

int main() {
	int t, p1 = 1, p2 = 0;
	scanf("%d", &t);
	while (t--) {
		LL s, e;
		scanf("%lld%lld", &s, &e);
		int q1 = calc(s, e, 0, 0) ? p1 : p2;
		int q2 = calc(s, e, 1, 1) ? p1 : p2;
		p1 = q1, p2 = q2;
	}
	printf("%d %d\n", p2, p1);
	return 0;
}