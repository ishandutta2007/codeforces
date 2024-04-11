#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
#include<map>

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
template<class Iter> void rprintf(const char *fmt, Iter begin, Iter end) {
    for (bool sp=0; begin!=end; ++begin) { if (sp) putchar(' '); else sp = true; printf(fmt, *begin); }
    putchar('\n');
}
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

int N;
int X[1011], Y[1011];

struct ByXY {
    bool operator()(const int i, const int j) const {
	return X[i] != X[j]? X[i] < X[j]: Y[i] < Y[j];
    }
} byXY;

struct ByYX {
    bool operator()(const int i, const int j) const {
	return Y[i] != Y[j]? Y[i] < Y[j]: X[i] < X[j];
    }
} byYX;

struct Edge {
    int u, v, cst;
    Edge(){}
    Edge(int u_, int v_, int cst_):
	u(u_), v(v_), cst(cst_) {}

    bool operator<(const Edge &o) const {
	return cst < o.cst;
    }
};
vector<Edge> E;
UnionFind U;

const LL INF = 1LL<<60;
LL ans;
VI Xs, Ys;

int ROOT[4];
VI B[4];
map<int, VI> XY[4], YX[4];
void check(LL at_least) {
    if (ans < at_least) return;

    int cnt = 0;
    REP (i, N) if (U.root(i) == i) {
	ROOT[cnt++] = i;
    }

    if (cnt == 1) {
	amin(ans, at_least);
	return;
    }

    REP (t, cnt) {
	B[t].clear();
	XY[t].clear();
	YX[t].clear();
    }

    REP (i, N) {
	int r = U.root(i);
	REP (t, cnt) if (ROOT[t] == r) {
	    B[t].push_back(i);
	    XY[t][X[i]].push_back(Y[i]);
	    YX[t][Y[i]].push_back(X[i]);
	    break;
	}
    }


    REP (t, cnt) {
	EACH (e, XY[t]) {
	    VI &v = e->second;
	    sort(v.begin(), v.end());
	}
	EACH (e, YX[t]) {
	    VI &v = e->second;
	    sort(v.begin(), v.end());
	}
    }

    auto cost = [](map<int, VI> &mp, int x, int y) -> LL {
	auto it = mp.find(x);
	if (it == mp.end()) return INF;

	VI &v = it->second;
	auto lb = lower_bound(v.begin(), v.end(), y);
	LL ret = INF;
	if (lb != v.end()) amin(ret, (LL)*lb - y);
	if (lb != v.begin()) amin(ret, (LL)y - *prev(lb));

	return ret;
    };

    REP (xi, Xs.size()) REP (yi, Ys.size()) {
	REP (a, 2) {
	    int x;
	    if (a == 0) x = Xs[xi];
	    else if (xi+1 == (int)Xs.size()) continue;
	    else x = ((LL)Xs[xi+1] + Xs[xi]) / 2;

	    REP (b, 2) {
		int y;
		if (b == 0) y = Ys[yi];
		else if (yi+1 == (int)Ys.size()) continue;
		else y = ((LL)Ys[yi+1] + Ys[yi]) / 2;

		LL c = at_least;
		REP (t, cnt) {
		    LL tmp = min(cost(XY[t], x, y), cost(YX[t], y, x));
		    amax(c, tmp);
		}

		amin(ans, c);
	    }
	}
    }
}

void UNIQUE(VI &v) {
sort(v.begin(), v.end());
v.erase(unique(v.begin(), v.end()), v.end());
}

void MAIN() {
    scanf("%d", &N);
    REP (i, N) {
	int x, y;
	scanf("%d%d", &x, &y);
	X[i] = x;
	Y[i] = y;
	Xs.push_back(x);
	Ys.push_back(y);
    }

    UNIQUE(Xs);
    UNIQUE(Ys);

    VI idx;
    idx.resize(N);
    REP (i, N) idx[i] = i;

    sort(idx.begin(), idx.end(), byXY);
    for (int i=0; i<N;) {
	int j = i;
	while (j < N && X[idx[i]] == X[idx[j]]) j++;
	for (int k=i; k+1<j; k++) {
	    int u = idx[k];
	    int v = idx[k+1];
	    E.emplace_back(u, v, Y[v] - Y[u]);
	}

	i = j;
    }

    sort(idx.begin(), idx.end(), byYX);
    for (int i=0; i<N;) {
	int j = i;
	while (j < N && Y[idx[i]] == Y[idx[j]]) j++;
	for (int k=i; k+1<j; k++) {
	    int u = idx[k];
	    int v = idx[k+1];
	    E.emplace_back(u, v, X[v] - X[u]);
	}

	i = j;
    }


    sort(E.begin(), E.end());
    U = UnionFind(N);

    ans = INF;
    if (N <= 4) check(0);


    EACH (e, E) {
	int u = e->u;
	int v = e->v;
	if (!U.same(u, v)) {
	    U.link(u, v);
	    if (U.count_tree() <= 4) {
		check(e->cst);
	    }
	}
    }

    
    if (ans == INF) puts("-1");
    else printf("%lld\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}