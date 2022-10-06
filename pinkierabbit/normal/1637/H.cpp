#include <cstdio>
#include <algorithm>
#include <functional>

#define F(i, a, b) for(int i = a; i <= (b); ++i)
#define dF(i, a, b) for(int i = a; i >= (b); --i)

void Solve();

int main() {
	int tests = 1;
	scanf("%d", &tests);
	while (tests--) {
		Solve();
	}
	return 0;
}

typedef long long ll;
const int MN = 500005;

int n, a[MN], c[MN];
int b[MN];
inline void Add(int i, int x) {
	for (; i <= n; i += i & -i)
		b[i] += x;
}
inline int Qur(int i) {
	int s = 0;
	for (; i; i -= i & -i)
		s += b[i];
	return s;
}

void Solve() {
	scanf("%d", &n);
	F(i, 1, n) scanf("%d", &a[i]);
	ll ans = 0;
	F(i, 1, n) b[i] = 0;
	F(i, 1, n) {
		int d = Qur(a[i]);
		ans += i - 1 - d;
		c[i] = i - 1 - 2 * d;
		Add(a[i], 1);
	}
	F(i, 1, n) b[i] = 0;
	dF(i, n, 1) {
		c[i] -= 2 * Qur(a[i]);
		Add(a[i], 1);
	}
	std::sort(c + 1, c + n + 1, std::greater<>());
	printf("%lld ", ans);
	for (int k = 1; k <= n; ++k) {
		ans -= c[k] + (k - 1);
		printf("%lld%c", ans, " \n"[k == n]);
	}
}