#include<set>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>

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
struct ConvexHullTrick {
    typedef LL T;
    static const T INF = 1LL<<62;

    // line y = ax + b;
    struct Line {
	T a, b;
	T ar, br;
	Line(T a_, T b_, T ar_, T br_) {
	    a = a_; b = b_; ar = ar_; br = br_;
	}

	friend bool operator<(const Line& x, const Line &y) {
	    return x.a != y.a ? x.a < y.a : x.b < y.b;
	}

	friend bool operator<(const Line& k, T x) {
	    if (k.ar == INF) return false;
	    return k.a * x + k.b < k.ar * x + k.br;
	}
    };

    set<Line, less<> > se;

    void insert(T a, T b) {
	Line line(a, b, 0, 0);
	auto lb = se.lower_bound(line);
	if (lb != se.end() && a == lb->a) return;
	auto left = (lb == se.begin()? se.end(): prev(lb));
	if (left != se.end() && hide(left->a, left->b, a, b, left->ar, left->br)) return;

	while (lb != se.end() && hide(a, b, lb->a, lb->b, lb->ar, lb->br)) se.erase(lb++);

	if (left != se.end() && left->a == a) {
	    se.erase(left);
	    left = (lb == se.begin()? se.end(): prev(lb));
	}

	while (left != se.end() && left != se.begin()) {
	    auto prv = prev(left);
	    if (hide(prv->a, prv->b, left->a, left->b, a, b)) {
		se.erase(left);
		left = prv;
	    } else {
		break;
	    }
	}
	if (left != se.end()) {
	    Line left_line(left->a, left->b, a, b);
	    se.erase(left);
	    left = se.insert(lb, left_line);
	}
	if (lb == se.end()) {
	    se.insert(lb, Line(a, b, INF, INF));
	} else {
	    se.insert(lb, Line(a, b, lb->a, lb->b));
	}
    }

    Line max_line(T x) const {
	return *se.lower_bound(x);
    }

    T max_y(T x) const {
	const Line &l = max_line(x);
	return l.a * x + l.b;
    }

    inline bool hide(T a0, T b0, T a1, T b1, T a2, T b2) const {
	if ((a0 == a1 && b0 >= b1) || (a1 == a2 && b1 <= b2)) return true;
	if (a2 == INF) return false;
	return (b0 - b1) * (a2 - a1) >= (b1 - b2) * (a1 - a0);
    }
};

const int MAXN = 150011;
int N;
VI G[MAXN];

int A[MAXN];

namespace CENTROID {
;
bool use[MAXN];
int qu[MAXN], qn;
int par[MAXN];
int sz[MAXN], sub_sz[MAXN];

LL len[MAXN], sum[MAXN], path[MAXN];

bool active(int w, int v) {
    return !use[w] && par[v] != w;
}

void bfs(int s) {
    qu[0] = s;
    qn = 1;
    par[s] = -1;
    for (int i=0; i<qn; i++) {
	int v = qu[i];
	EACH (e, G[v]) if (active(*e, v)) {
	    int w = *e;
	    par[w] = v;
	    qu[qn++] = w;
	}
    }
}

int find_center(int s) {
    bfs(s);

    REP (i_, qn) {
	int v = qu[qn-1-i_];
	sz[v] = 1;
	sub_sz[v] = 0;
	EACH (e, G[v]) if (active(*e, v)) {
	    sz[v] += sz[*e];
	    amax(sub_sz[v], sz[*e]);
	}
    }

    int ret = s;
    REP (i, qn) {
	int v = qu[i];
	if (max(sub_sz[ret], qn-sz[ret]) > max(sub_sz[v], qn-sz[v])) {
	    ret = v;
	}
    }
    return ret;
}

ConvexHullTrick cht;
LL ans;
void dfs(int v, int p) {
    len[v] = len[p] + 1;
    path[v] = path[p] + A[v];
    sum[v] = sum[p] + (LL)A[v] * len[v];

    if (!cht.se.empty()) {
	LL tmp = cht.max_y(path[v]);
	amax(ans, tmp + sum[v]);
    }

    EACH (e, G[v]) if (*e != p && !use[*e]) {
	dfs(*e, v);
    }
}

void dfs2(int v, int p) {
    len[v] = len[p] + 1;
    path[v] = path[p] + A[v];
    sum[v] = sum[p] + path[v];

    cht.insert(len[v], sum[v]);

    EACH (e, G[v]) if (*e != p && !use[*e]) {
	dfs2(*e, v);
    }
}

void calc(int s) {
    REP (t, 2) {
	cht.se.clear();

	cht.insert(1, A[s]);
	amax(ans, (LL)A[s]);

	EACH (e, G[s]) if (!use[*e]) {
	    len[s] = path[s] = sum[s] = 0;
	    dfs(*e, s);
	    len[s] = 1;
	    path[s] = sum[s] = A[s];
	    dfs2(*e, s);
	}

	REP (i, qn) {
	    int v = qu[i];
	    reverse(G[v].begin(), G[v].end());
	}
    }
}

void rec(int s) {
    s = find_center(s);
    bfs(s);

    calc(s);

    use[s] = true;
    EACH (e, G[s]) if (active(*e, s)) {
	rec(*e);
    }
}

void solve() {
    memset(use, 0, sizeof (bool) * N);
    rec(0);

    printf("%lld\n", ans);
}
}; // namespace CENTROID;

void MAIN() {
    scanf("%d", &N);
    REP (i, N-1) {
	int x, y;
	scanf("%d%d", &x, &y);
	x--;
	y--;
	G[x].push_back(y);
	G[y].push_back(x);
    }
    REP (i, N) scanf("%d", A+i);

    CENTROID::solve();
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}