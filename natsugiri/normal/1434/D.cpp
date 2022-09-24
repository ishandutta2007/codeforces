#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
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

struct Seg {
    int ma, mi;
    Seg() : ma(0), mi(0) {}
    Seg(int ma_, int mi_): ma(ma_), mi(mi_) {}

    static const Seg IDENTITY;
};
const Seg Seg::IDENTITY = Seg();

Seg operator+(const Seg &x, const Seg &y) {
    Seg z;
    z.ma = max(x.ma, y.ma);
    z.mi = min(x.mi, y.mi);
    return z;
};

struct Lazy {
    bool flip;
    Lazy() : flip(0) {}
    Lazy(bool flip_) : flip(flip_) {}

    Lazy& operator*=(const Lazy &y) {
	if (y.flip) flip = !flip;
	return *this;
    }

    static const Lazy IDENTITY;
};
const Lazy Lazy::IDENTITY = Lazy();

Seg operator*(const Seg &x, const Lazy &y) {
    if (y.flip) return Seg(-x.mi, -x.ma);
    else return x;
}
struct SegTreeLazy {
    int m;
    vector<Seg> d;
    vector<Lazy> lazy;

    SegTreeLazy(int n=1) {
	if (n < 2) m = 1;
	else m = 2 << __lg(n-1);
	d.assign(m*2, Seg::IDENTITY);
	lazy.assign(m*2, Lazy::IDENTITY);
    }

    template<class Iter> SegTreeLazy(Iter begin, Iter end) {
	int n = end - begin;
	if (n < 2) m = 1;
	else m = 2 << __lg(n-1);
	d.assign(m*2, Seg::IDENTITY);
	REP (i, n) d[i+m] = *(begin+i);
	for (int i=m; --i; ) d[i] = d[i*2] + d[i*2+1];
	lazy.assign(m*2, Lazy::IDENTITY);
    }

    void force_down(int x) {
	x += m;
	for (int i=__lg(x); i>=1; i--) {
	    int k = x >> i;
	    lazy[k*2] *= lazy[k];
	    lazy[k*2+1] *= lazy[k];
	    d[k] = eval(k*2) + eval(k*2+1);
	    lazy[k] = Lazy::IDENTITY;
	}
    }

    inline Seg eval(int k) {
	return d[k] * lazy[k];
    }

    Seg at(int x) {
	x += m;
	Seg s = d[x];
	for (; x; x>>=1) s = s * lazy[x];
	return s;
    }

    void modify(int x, const Seg &s) {
	force_down(x);
	x += m;
	d[x] = s;
	lazy[x] = Lazy::IDENTITY;
	for (x>>=1; x; x>>=1) d[x] = eval(x*2) + eval(x*2+1);
    }

    Seg query(int x, int y) {
	if (x >= y) return Seg::IDENTITY;
	force_down(x);
	if (x+1 < y) force_down(y-1);
	x += m; y += m;
	Seg ls = Seg::IDENTITY, rs = Seg::IDENTITY;
	for (; x < y; x>>=1, y>>=1) {
	    if (y & 1) rs = eval(--y) + rs;
	    if (x & 1) ls = ls + eval(x++);
	}
	return ls + rs;
    }

    void add(const int x, const int y, const Lazy &v) {
	if (x >= y) return;
	force_down(x);
	if (x+1 < y) force_down(y-1);
	int x0 = x + m, y0 = y + m;
	for (; x0 < y0; x0>>=1, y0>>=1) {
	    if (y0 & 1) lazy[--y0] *= v;
	    if (x0 & 1) lazy[x0++] *= v;
	}
	for (x0=(x+m)>>1; x0; x0>>=1)
	    d[x0] = eval(x0*2) + eval(x0*2+1);
	if (x+1 < y)
	    for (y0=(y+m-1)>>1; y0; y0>>=1)
		d[y0] = eval(y0*2) + eval(y0*2+1);
    }

    inline void force(int k) {
	if (k < m) { // Lazy down
	    lazy[k*2] *= lazy[k];
	    lazy[k*2+1] *= lazy[k];
	    d[k] = eval(k*2) + eval(k*2+1);
	    lazy[k] = Lazy::IDENTITY;
	}
    }

    Seg query_template(int x, int y) { return query_template(x, y, 1, 0, m); }

    Seg query_template(int x, int y, int k, int l, int r) {
	force(k);
	if (r<=x || y<=l) return Seg::IDENTITY;
	if (x<=l && r<=y) return eval(k);
	Seg left = query_template(x, y, k*2, l, (l+r)/2);
	Seg right = query_template(x, y, k*2+1, (l+r)/2, r);
	return left + right;
    }
};

int N;
VI G[500011];
int X[500011];
int Y[500011];
int T[500011];

int iter[500011];

struct DFS {
    int root;
    VI que;
    VI par, dist, sz, rnk;
    SegTreeLazy tree;

    DFS(int s) {
	root = s;
	VI stk;
	VI dp(N);
	que.push_back(s);
	stk.push_back(s);

	iter[s] = 0;

	rnk.resize(N);
	rnk[s] = 0;
	par.resize(N);
	par[s] = s;
	dist.resize(N);
	dist[s] = 0;

	while (!stk.empty()) {
	    int v = stk.back();
	    if (iter[v] == (int)G[v].size()) {
		stk.pop_back();
	    } else {
		int idx = G[v][iter[v]++];
		int w = v ^ X[idx] ^ Y[idx];
		if (w == par[v]) continue;
		rnk[w] = que.size();
		que.push_back(w);
		stk.push_back(w);
		iter[w] = 0;
		par[w] = v;
		dist[w] = dist[v] + 1;
		dp[w] = dp[v] ^ T[idx];
	    }
	}

	sz.resize(N);
	for (int i=N; i--;) {
	    int v = que[i];
	    sz[v] = 1;
	    EACH (e, G[v]) {
		int w = v ^ X[*e] ^ Y[*e];
		if (w != par[v]) {
		    sz[v] += sz[w];
		}
	    }
	}

	tree = SegTreeLazy(N);

	REP (i, N) {
	    int v = que[i];
	    if (dp[v]) {
		tree.modify(rnk[v], Seg(-dist[v], -dist[v]));
	    } else {
		tree.modify(rnk[v], Seg(dist[v], dist[v]));
	    }
	}
    }

    int far() const {
	return max_element(dist.begin(), dist.end()) - dist.begin();
    }

    void update(int id) {
	int x;
	if (dist[X[id]] < dist[Y[id]]) x = Y[id];
	else x = X[id];
	tree.add(rnk[x], rnk[x] + sz[x], Lazy(1));
    }

    int find() {
	return tree.query(0, N).ma;
    }
};

void MAIN() {
    scanf("%d", &N);
    REP (i, N-1) {
	scanf("%d%d%d", X+i, Y+i, T+i);
	X[i]--;
	Y[i]--;
	G[X[i]].push_back(i);
	G[Y[i]].push_back(i);
    }

    int x;
    {
	DFS dfs(0);
	x = dfs.far();
    }
    DFS dfs_x(x);
    int y = dfs_x.far();
    DFS dfs_y(y);

    int Q;
    scanf("%d", &Q);
    REP ($, Q) {
	int id;
	scanf("%d", &id);
	id--;

	dfs_x.update(id);
	dfs_y.update(id);
	int ans = max(dfs_x.find(), dfs_y.find());
	printf("%d\n", ans);
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}