#include <cstdio>
#include <algorithm>
#include <vector>
#include <bitset>
#include <iostream>
using namespace std;

typedef pair<int, int> pii;
#define F(i, a, b) for(int i = a; i <= (b); ++i)
#define F2(i, a, b) for(int i = a; i < (b); ++i)
#define dF(i, a, b) for(int i = a; i >= (b); --i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n", __FUNCTION__, __LINE__)
#define MN 105
#define ll long long
#define mod 998244353
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define pb push_back
#define mkp make_pair
#define fi first
#define se second

int n;
int a[MN], b[MN];

void Solve();

int main() {
	int tests = 1;
	scanf("%d", &tests);
	while (tests--) {
		Solve();
	}
	return 0;
}

const int S = 10005;
std::bitset<2 * S> f[MN];

void Solve() {
	scanf("%d", &n);
	F(i, 1, n) scanf("%d", a + i);
	F(i, 1, n) scanf("%d", b + i);
	f[0].reset();
	f[0][S] = 1;
	F(i, 1, n) {
		int d = std::abs(a[i] - b[i]);
		f[i] = (f[i - 1] << d) | (f[i - 1] >> d);
	}
	int p = S;
	while (!f[n][p]) ++p;
	dF(i, n, 1) {
		int d = a[i] - b[i];
		if (p + d >= 0 && p + d < 2 * S && f[i - 1][p + d])
			p += d;
		else
			p -= d, std::swap(a[i], b[i]);
	}
	ll ans = 0;
	F(i, 1, n)
		F(j, i + 1, n)
			ans += (a[i] + a[j]) * (a[i] + a[j]);
	F(i, 1, n)
		F(j, i + 1, n)
			ans += (b[i] + b[j]) * (b[i] + b[j]);
	printf("%lld\n", ans);
}