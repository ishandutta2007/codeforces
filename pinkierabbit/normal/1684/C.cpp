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
#define MN 300005
#define MM 600005
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

void Solve() {
	scanf("%d%d", &n, &m);
	vector<vector<int>> a(n + 2, vector<int>(m + 2));
	F(i, 1, n) F(j, 1, m) scanf("%d", &a[i][j]);
	bool ok = true;
	int p = 0, q = 0;
	F(i, 1, n) F(j, 2, m)
		if (a[i][j - 1] > a[i][j]) {
			ok = false;
			int pmx = a[i][1];
			F(k, 2, m) {
				if (a[i][k] < pmx)
					q = k;
				pmx = max(pmx, a[i][k]);
			}
			int smn = a[i][m];
			dF(k, m - 1, 1) {
				if (a[i][k] > smn)
					p = k;
				smn = min(smn, a[i][k]);
			}
			break;
		}
	if (ok)
		return puts("1 1"), void();
	F(i, 1, n)
		swap(a[i][p], a[i][q]);
	bool ok2 = true;
	F(i, 1, n) F(j, 2, m)
		if (a[i][j - 1] > a[i][j])
			ok2 = false;
	if (ok2)
		return printf("%d %d\n", p, q), void();
	puts("-1");
}