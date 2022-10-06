#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int, int> pii;
#define F(i, a, b) for(int i = a; i <= (b); ++i)
#define F2(i, a, b) for(int i = a; i < (b); ++i)
#define dF(i, a, b) for(int i = a; i >= (b); --i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n", __FUNCTION__, __LINE__)
#define MN 1000005
#define ll long long
#define mod 998244353
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define pb push_back
#define mkp make_pair
#define fi first
#define se second

void Solve();

int main() {
	int tests = 1;
	scanf("%d", &tests);
	while (tests--)
		Solve();
	return 0;
}

int n, v;
int a[MN], b[MN], c[MN];

void Solve() {
	scanf("%d%d", &n, &v);
	F(i, 1, v) b[i] = 0;
	F(i, 1, n) scanf("%d", a + i), b[a[i]] = 1;
	F(i, 1, v) c[i] = c[i - 1] + b[i];
	bool ok = true;
	F(i, 1, v) if (!b[i]) {
		for (int j = 1; i * j <= v; ++j) if (b[j]) {
			int num = c[min((i + 1) * j - 1, v)] - c[i * j - 1];
			if (num)
				ok = false;
		}
	}
	puts(ok ? "Yes" : "No");
}