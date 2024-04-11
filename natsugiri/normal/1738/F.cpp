#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#pragma GCC optimize("unroll-loops")
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

int N;
int D[1001];
UnionFind U;

int query(int v) {
    printf("? %d\n", v+1);
    fflush(stdout);
    int ret;
    scanf("%d", &ret);
    ret--;
    return ret;
}
void answer() {
    printf("!");
    REP (i, N) printf(" %d", U.root(i) + 1);
    putchar('\n');
    fflush(stdout);
}

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", D+i);

    int start = max_element(D, D+N) - D;

    U = UnionFind(N);

    if (D[start] == 0) {
	// NOP;
    } else {
	REP (i, D[start]) {
	    int q = query(start);
	    U.link(start, q);
	}

	while (1) {
	    int nxt = -1;
	    REP (i, N) if (D[i] && U.count_node(i) == 1 && (nxt == -1 || D[i] > D[nxt])) {
		nxt = i;
	    }
	    if (nxt == -1) break;

	    REP (i, D[nxt]) {
		int q = query(nxt);
		if (U.count_node(q) != 1) {
		    U.link(nxt, q);
		    break;
		} else {
		    U.link(nxt, q);
		}
	    }
	}
    }

    answer();
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}