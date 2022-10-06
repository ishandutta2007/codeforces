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

int n, m, q, k;
int a[MN], b[MN], c[MN];
vector<int> G[MN];

void Solve();

int main() {
	int tests = 1;
	scanf("%d", &tests);
	while (tests--) {
		Solve();
	}
	return 0;
}

void Solve() {
	int x;
	scanf("%d", &n);
	F(i, 1, n) scanf("%d", &x), a[x] = i;
	F(i, 1, n) scanf("%1d", b + i);
	int p = n;
	dF(i, n, 1) if (b[a[i]]) c[a[i]] = p--;
	p = 1;
	F(i, 1, n) if (!b[a[i]]) c[a[i]] = p++;
	F(i, 1, n) printf("%d%c", c[i], " \n"[i == n]);
}