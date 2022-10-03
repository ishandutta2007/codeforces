#include <cstdio>

#define F(i, a, b) for(int i = a; i <= (b); ++i)

void Solve();

int main() {
	int tests = 1;
	scanf("%d", &tests);
	while (tests--)
		Solve();
	return 0;
}

typedef long long ll;
const int MN = 100005;

int n, a[MN];

void Solve() {
	scanf("%d", &n), n -= 2;
	F(i, 0, n + 1) scanf("%d", a + i);
	if (n == 1 && a[1] % 2)
		return puts("-1"), void();
	bool ok = 0;
	F(i, 1, n)
		if (a[i] != 1)
			ok = 1;
	if (!ok)
		return puts("-1"), void();
	ll ans = 0;
	F(i, 1, n)
		ans += a[i] + (a[i] & 1);
	printf("%lld\n", ans / 2);
}