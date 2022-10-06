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

int n, m;
char s[MN];
int ans1[MN], ans2[MN];

void Solve() {
	scanf("%d%d%s", &n, &m, s + 1);
	F(i, 1, n * m) ans1[i] = ans2[i] = 0;
	int lst = -1e9;
	F(i, 1, n * m) {
		if (s[i] == '1')
			lst = i;
		if (i - lst < m)
			ans1[i] = 1;
	}
	static int vis[MN];
	F2(i, 0, m) vis[i] = 0;
	F(i, 1, n * m) {
		if (s[i] == '1' && !vis[i % m])
			vis[i % m] = 1, ans2[i] = 1;
	}
	F(i, m + 1, n * m)
		ans1[i] += ans1[i - m];
	F(i, 2, n * m)
		ans2[i] += ans2[i - 1];
	F(i, 1, n * m)
		printf("%d%c", ans1[i] + ans2[i], " \n"[i == n * m]);
}