#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
#include<tuple>
#include<set>

#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define NDEBUG
#define eprintf(...) do {} while (0)
#endif
#include<cassert>

using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }
#define rprintf(fmt, begin, end) do { const auto end_rp = (end); auto it_rp = (begin); for (bool sp_rp=0; it_rp!=end_rp; ++it_rp) { if (sp_rp) putchar(' '); else sp_rp = true; printf(fmt, *it_rp); } putchar('\n'); } while(0)

struct UnionFind {
    int n, cc, *u;
    UnionFind() : n(0), cc(0), u(NULL) {}
    UnionFind(int n_) : n(n_), cc(n_) {
	u = new int[n_];
	memset(u, -1, sizeof (int) * n);
    }
    UnionFind(const UnionFind &y) : n(y.n), cc(y.cc) {
	u = new int[y.n];
	memcpy(u, y.u, sizeof (int) * n);
    }
    ~UnionFind() {
	delete[] u; u = NULL;
	n = cc = 0;
    }
    friend void swap(UnionFind &x, UnionFind &y) {
	swap(x.n, y.n); swap(x.cc, y.cc); swap(x.u, y.u);
    }
    UnionFind& operator=(UnionFind y) { 
	swap(*this, y);
	return *this;
    }
    int root(int x) {
	int y = x, t;
	while (u[y] >= 0) y = u[y];
	while (x != y) { t = u[x]; u[x] = y; x = t; }
	return y;
    }
    bool link(int x, int y) {
	x = root(x); y = root(y);
	if (x == y) return false;
	if (u[y] < u[x]) swap(x, y);
	u[x] += u[y]; u[y] = x; cc--;
	return true;
    }
    bool same(int x, int y) { return root(x) == root(y); }
    int count_node(int x) { return -u[root(x)]; }
    int count_tree() { return cc; }
};

int N, M;

int X[200011];
int Y[200011];
int C[200011];

vector<pair<int, int> > G[200011];

using Tuple = tuple<int, int, int>;

int deg[200011];
bool use[200011];
void solve1() {
    REP (i, M) {
	int x = X[i];
	int y = Y[i];
	int c = C[i];

	G[x].emplace_back(y, c);
	G[y].emplace_back(x, c);
    }
    UnionFind U(N);

    set<pair<int, int> > se;
    REP (v, N) {
	se.emplace(0, v);
    }

    int cnt = 0;

    while (!se.empty()) {
	int v = se.begin()->second;
	use[v] = true;
	se.erase(se.begin());
	cnt++;

	while (!se.empty()) {
	    EACH (e, G[v]) {
		int y = e->first;
		if (!use[y]) {
		    bool b = se.erase(make_pair(deg[y], y));
		    assert(b);
		    deg[y]++;
		    se.emplace(deg[y], y);
		}
	    }

	    if (se.empty()) break;

	    if (se.begin()->first < cnt) {
		int y = se.begin()->second;
		U.link(v, y);
		v = y;
		use[v] = true;
		se.erase(se.begin());
		cnt++;
	    } else {
		break;
	    }
	}

	if (se.empty()) break;
    }

    vector<Tuple> E;

    REP (i, M) {
	int x = X[i];
	int y = Y[i];
	int c = C[i];
	if (!U.same(x, y)) {
	    E.emplace_back(c, x, y);
	}
    }

    sort(E.begin(), E.end());

    LL ans = 0;
    EACH (e, E) {
	int x, y, c;
	tie(c, x, y) = *e;
	if (!U.same(x, y)) {
	    ans += c;
	    U.link(x, y);
	}
    }
    printf("%lld\n", ans);
}

int A[1011][1011];
void solve2() {
    int XOR = 0;
    REP (i, M) {
	int x = X[i];
	int y = Y[i];
	int c = C[i];
	XOR ^= c;
	A[x][y] = A[y][x] = c;
    }

    vector<Tuple> E;
    bool loop = false;

    UnionFind U(N);
    REP (i, N) REP (j, i) {
	if (A[i][j] == 0) {
	    if (U.same(i, j)) loop = true;
	    U.link(i, j);
	}
    }

    REP (i, N) REP (j, i) if (A[i][j]) {
	E.emplace_back(A[i][j], i, j);
    }

    sort(E.begin(), E.end());

    LL ans = 0;
    if (!loop) ans += XOR;

    EACH (e, E) {
	int x, y, c;
	tie(c, x, y) = *e;
	if (!U.same(x, y)) {
	    ans += c;
	    U.link(x, y);
	}
    }

    if (!loop) {
	U = UnionFind(N);
	REP (i, N) REP (j, i) {
	    if (A[i][j] == 0) {
		// G[i].emplace_back(j, 0);
		// G[j].emplace_back(i, 0);
		U.link(i, j);
	    }
	}

	vector<Tuple> small, large;
	LL small_sum = 0;
	EACH (e, E) {
	    int x, y, c;
	    tie(c, x, y) = *e;
	    if (!U.same(x, y)) {
		// G[x].emplace_back(y, c);
		// G[y].emplace_back(x, c);
		U.link(x, y);
		small.push_back(*e);
		small_sum += c;
	    } else {
		large.push_back(*e);
	    }
	}

	U = UnionFind(N);
	EACH (e, small) {
	    int x, y, c;
	    tie(c, x, y) = *e;
	    U.link(x, y);
	}
	EACH (e, large) {
	    int x, y, c;
	    tie(c, x, y) = *e;
	    if (!U.same(x, y)) {
		LL tmp = small_sum + c;
		amin(ans, tmp);
		break;
	    }
	}
    }

    printf("%lld\n", ans);
}

void MAIN() {
    scanf("%d%d", &N, &M);

    REP (i, M) {
	int x, y, w;
	scanf("%d%d%d", &x, &y, &w);
	x--; y--;
	X[i] = x;
	Y[i] = y;
	C[i] = w;

    }

    if (N >= 1000) {
	solve1();
    } else {
	solve2();
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}