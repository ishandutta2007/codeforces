#include <cstdio>

const int MN = 1000005;

int N, p[MN];
struct v {
	int f, m1, p, m2;
	v() {}
	v(int f, int m1, int p, int m2)
		: f(f), m1(m1), p(p), m2(m2) {}
	inline bool ins(int fv, int pv) {
		if (pv == p) m1 = fv;
		else if (fv > m1) m2 = m1, m1 = fv, p = pv;
		else if (fv > m2) m2 = fv;
		return f < m1 || f <= m2 ? f = m1 > m2 ? m1 : m2 + 1, 1 : 0;
	}
} f[MN];

int main() {
	scanf("%d", &N), ++N;
	f[1] = v(1, 0, 0, 0);
	for (int i = 2; i <= N; ++i) {
		scanf("%d", &p[i]);
		f[i] = v(1, 0, 0, 0);
		int x = i;
		while (p[x] && f[p[x]].ins(f[x].f, x)) x = p[x];
		printf("%d ", f[1].m1);
	}
	return 0;
}