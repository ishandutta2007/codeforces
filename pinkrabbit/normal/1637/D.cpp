#include <cstdio>
#include <algorithm>
#include <bitset>

#define F(i, a, b) for(int i = a; i <= (b); ++i)
#define dF(i, a, b) for(int i = a; i >= (b); --i)

void Solve();

int main() {
	int tests = 1;
	scanf("%d", &tests);
	while (tests--)
		Solve();
	return 0;
}

const int MN = 105;
const int S = 10005;

int n;
int a[MN], b[MN];
std::bitset<S> f[MN];

void Solve() {
	int ans = 0, sum = 0;
	scanf("%d", &n);
	F(i, 1, n) scanf("%d", a + i), ans += a[i] * a[i], sum += a[i];
	F(i, 1, n) scanf("%d", b + i), ans += b[i] * b[i], sum += b[i];
	ans *= n - 2;
	f[0].reset();
	f[0][0] = 1;
	F(i, 1, n)
		f[i] = (f[i - 1] << a[i]) | (f[i - 1] << b[i]);
	int p = (sum + 1) / 2;
	while (!f[n][p]) ++p;
	ans += p * p + (sum - p) * (sum - p);
	printf("%d\n", ans);
}