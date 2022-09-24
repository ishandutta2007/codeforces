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
int M;
LL COST;
LL A[300011];
int X[300011];
int Y[300011];

VI G[300011];

int par[300011];

void MAIN() {
    scanf("%d%d%lld", &N, &M, &COST);
    REP (i, N) scanf("%lld", A+i);

    UnionFind U(N);
    REP (i, M) {
	int x, y;
	scanf("%d%d", &x, &y);
	x--; y--;
	X[i] = x;
	Y[i] = y;

	if (!U.same(x, y)) {
	    G[x].push_back(i);
	    G[y].push_back(i);
	    U.link(x, y);
	}
    }

    LL sum = 0;
    REP (i, N) sum += A[i];

    if (COST * (N-1) > sum) {
	puts("NO");
    } else {
	VI que;
	que.push_back(0);
	REP (i, N) {
	    int v = que[i];
	    EACH (e, G[v]) {
		int w = v ^ X[*e] ^ Y[*e];
		if (w == par[v]) continue;
		par[w] = v;
		que.push_back(w);
	    }
	}

	VI ans, bad;
	REP (i, N) {
	    int v = que[N-1-i];
	    EACH (e, G[v]) {
		int w = v ^ X[*e] ^ Y[*e];
		if (w == par[v]) continue;

		if (A[w] + A[v] >= COST) {
		    ans.push_back(*e);
		    A[v] += A[w];
		    A[v] -= COST;
		    A[w] = 0;
		} else {
		    bad.push_back(*e);
		}
	    }
	}

	reverse(bad.begin(), bad.end());
	ans.insert(ans.end(), bad.begin(), bad.end());

	puts("YES");
	EACH (e, ans) printf("%d\n", *e+1);
    }

}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}