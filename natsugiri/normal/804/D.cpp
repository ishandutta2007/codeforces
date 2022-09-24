#include<map>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)
#define eprintf(...) fprintf(stderr, __VA_ARGS__)

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
    int size(int x) { return -u[root(x)]; }
    int count() { return cc; }
};

const int MAXN = 100111;

int N, M, Q;
VI G[MAXN];
int par[MAXN];

VI ord;
int bfs(int r, int *len) {
    ord.clear();
    ord.push_back(r);
    par[r] = r;
    len[r] = 0;
    for (int i=0; i<(int)ord.size(); i++) {
	int v = ord[i];
	EACH (e, G[v]) if (*e != par[v]) {
	    par[*e] = v;
	    len[*e] = len[v] + 1;
	    ord.push_back(*e);
	}
    }

    int p = r;
    EACH (e, ord) if (len[p] < len[*e]) p = *e;
    return p;
}

int len[MAXN], len1[MAXN];
int D[MAXN];
VI F[MAXN];
vector<LL> sums[MAXN];

map<LL, double> cache;

void MAIN() {
    scanf("%d%d%d", &N, &M, &Q);

    UnionFind U(N);

    REP (i, M) {
	int x, y;
	scanf("%d%d", &x, &y);
	x--; y--;
	G[x].push_back(y);
	G[y].push_back(x);
	U.link(x, y);
    }

    REP (i, N) if (U.root(i) == i) {
	int s = bfs(i, len);
	int t = bfs(s, len);
	bfs(t, len1);

	D[i] = len[t];

	EACH (e, ord) {
	    F[i].push_back(max(len[*e], len1[*e]));
	}

	sort(F[i].begin(), F[i].end());
	sums[i].resize(F[i].size() + 1);
	REP (j, F[i].size()) {
	    sums[i][j+1] = sums[i][j] + F[i][j];
	}
    }


    REP ($, Q) {
	int x, y;
	scanf("%d%d", &x, &y);
	x--; y--;
	x = U.root(x);
	y = U.root(y);

	if (x == y) {
	    puts("-1");
	} else {
	    if (x > y) swap(x, y);

	    LL key = ((LL)x << 32) | y;
	    auto it = cache.lower_bound(key);
	    double ans;
	    if (it != cache.end() && it->first == key) {
		ans = it->second;
	    } else {
		if (F[x].size() > F[y].size()) swap(x, y);
		int b = max(D[x], D[y]);
		vector<double> dd;

		EACH (e, F[x]) {
		    int k = lower_bound(F[y].begin(), F[y].end(), b - 1 - *e) - F[y].begin();
		    // [0, k), [k, size);

		    dd.push_back((double)k * b);

		    dd.push_back(sums[y].back() - sums[y][k] +
			    ((double)F[y].size() - k) * (1.0 + *e));
		}

		for (int i=dd.size(); --i;) {
		    dd[i/2] += dd[i];
		}

		ans = dd[0] / ((double) F[x].size() * F[y].size());

		if (F[x].size() > 20u) {
		    cache.emplace_hint(it, key, ans);
		}
	    }

	    printf("%.9f\n", ans);
	}
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}