#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
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
int a[MN];
pii q[MM];
vector<int> w[MN];
int V[MN];
int L[MN], R[MN];

void Solve() {
	scanf("%d%d", &n, &m);
	F(i, 1, n) scanf("%d", a + i);
	{
		static int d[MN];
		int c = 0;
		F(i, 1, n) d[++c] = a[i];
		sort(d + 1, d + c + 1);
		c = (int)(unique(d + 1, d + c + 1) - d - 1);
		F(i, 1, n) a[i] = (int)(lower_bound(d + 1, d + c + 1, a[i]) - d);
	}
	F(i, 1, m) scanf("%d%d", &q[i].fi, &q[i].se);
	{
		sort(q + 1, q + m + 1);
		int t = 0;
		F(i, 1, m) if (i == m || q[i].fi != q[i + 1].fi)
			if (t == 0 || q[i].se > q[t].se)
				q[++t] = q[i];
		m = t;
	}
//	printf("[");
//	F(i, 1, n) printf("%d%s", a[i], i == n ? "]\n" : ", ");
//	F(i, 1, m) printf("(%d, %d)\n", q[i].fi, q[i].se);
	{
		static int lst[MN];
		F(i, 1, n) lst[i] = 0;
		int val = 0;
		F(i, 1, n) {
			val = max(val, lst[a[i]] + 1);
			lst[a[i]] = i;
			L[i] = val;
		}
		F(i, 1, n) lst[i] = n + 1;
		val = n + 1;
		dF(i, n, 1) {
			val = min(val, lst[a[i]] - 1);
			lst[a[i]] = i;
			R[i] = val;
		}
	}
	bool ok = true;
	F(i, 1, m)
		if (R[q[i].fi] < q[i].se)
			ok = false;
	if (ok)
		return puts("0"), void();
	F(i, 1, n) w[i].clear();
	F(i, 1, n) w[a[i]].push_back(i);
	F(i, 1, n) V[i] = 0;
	F(i, 1, m) V[q[i].fi] = q[i].se;
	int ans = n - 1, rb = 1;
	F(i, 1, m) rb = max(rb, L[q[i].se] - 1);
	int j = 1;
	F(i, 1, n) {
		if (i >= 2) {
			while (j <= m && q[j].se < i - 1)
				++j;
			if (j <= m && q[j].fi < L[i - 1])
				break;
			int pos = (int)(lower_bound(q + 1, q + m + 1, pii{i, 0}) - q - 1);
			if (pos) {
				int p2 = *(lower_bound(w[a[i - 1]].begin(), w[a[i - 1]].end(), q[pos].se + 1) - 1);
//				printf("col = %d, pos = %d, p2 = %d\n", a[i - 1], q[pos].se, p2);
				rb = max(rb, p2);
			}
		}
//		printf("[%d -- %d]\n", i, rb);
		ans = min(ans, rb - i + 1);
	}
	printf("%d\n", ans);
}