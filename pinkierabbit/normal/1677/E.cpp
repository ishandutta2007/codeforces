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
#define MN 200005
#define MQ 1000005
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
//	scanf("%d", &tests);
	while (tests--)
		Solve();
	return 0;
}

int n, Q;
int a[MN], ia[MN];
vector<pii> V[MN];
int L[MN], R[MN];

vector<int> Q1[MN];
vector<pii> Q2[MN];
ll ans[MQ];

ll bit[MN][4];
void add(int i, ll *x) {
	for (; i <= n; i += i & -i)
		bit[i][0] += x[0],
		bit[i][1] += x[1],
		bit[i][2] += x[2],
		bit[i][3] += x[3];
}
void qur(int i, ll *x) {
	x[0] = x[1] = x[2] = x[3] = 0;
	for (; i; i -= i & -i)
		x[0] += bit[i][0],
		x[1] += bit[i][1],
		x[2] += bit[i][2],
		x[3] += bit[i][3];
}

void Solve() {
	scanf("%d%d", &n, &Q);
	F(i, 1, n) scanf("%d", a + i), ia[a[i]] = i;
	F(i, 1, n) if ((ll)i * (i + 1) <= n) {
		int lim = n / i;
		F(j, i + 1, lim) {
			int p = ia[i], q = ia[j];
			if (p > q) swap(p, q);
			V[ia[i * j]].push_back({p, q});
		}
	}
	/* monotonic stack */ {
		static int stk[MN];
		int tp = 1;
		a[0] = n + 1;
		F(i, 1, n) {
			while (a[stk[tp]] < a[i])
				R[stk[tp]] = i,
				--tp;
			L[i] = stk[tp];
			stk[++tp] = i;
		}
		while (tp)
			R[stk[tp]] = n + 1,
			--tp;
	}
//	F(i, 1, n) printf("[%d, %d] x [%d, %d]\n", L[i] + 1, i, i, R[i] - 1);
	F(i, 1, n) {
		vector<pii> v;
		for (pii &w : V[i])
			w.fi = min(w.fi, i),
			w.se = max(w.se, i);
		sort(V[i].begin(), V[i].end());
		for (pii w : V[i]) {
			if (w.fi <= L[i] || R[i] <= w.se) continue;
			while (!v.empty() && v.back().se >= w.se) v.pop_back();
			if (v.empty() || v.back().fi < w.fi) v.push_back(w);
		}
		V[i].swap(v);
//		printf("[%d]%d: ", i, a[i]);
//		for (pii w : V[i]) printf("(%d, %d), ", w.fi, w.se);
//		puts("");
	}
	F(i, 1, n) if (!V[i].empty()) {
		int s = (int)V[i].size();
		F2(j, 0, s) {
			Q1[V[i][j].fi].push_back(V[i][j].se);
			Q1[V[i][j].fi].push_back(-R[i]);
			if (j) {
				Q1[V[i][j - 1].fi].push_back(-V[i][j].se);
				Q1[V[i][j - 1].fi].push_back(R[i]);
			} else {
				Q1[L[i]].push_back(-V[i][j].se);
				Q1[L[i]].push_back(R[i]);
			}
		}
	}
	F(i, 1, Q) {
		int x, y;
		scanf("%d%d", &x, &y);
		Q2[x].push_back({y, i});
	}
	dF(i, n, 1) {
		for (int c : Q1[i]) {
			int v = c < 0 ? -1 : 1;
			int j = v * c;
			static ll x[4];
			x[0] = v;
			x[1] = v * i;
			x[2] = v * j;
			x[3] = (ll)v * i * j;
			add(j, x);
		}
		for (pii p : Q2[i]) {
			int j = p.fi;
			int q = p.se;
			static ll x[4];
			qur(j, x);
			ans[q] = (j + 1) * x[1] + (i - 1) * x[2] - x[3] - (ll)(i - 1) * (j + 1) * x[0];
		}
	}
	F(i, 1, Q) printf("%lld\n", ans[i]);
}