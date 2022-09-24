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
template<class T> void sort_unique(vector<T> &v) {
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
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

int N, M;

struct Edge {
    int x, y, c;
    bool operator<(const Edge &o) const {
	return c < o.c;
    }
} E[311];
pair<int, int> aux[311];

void MAIN() {
    scanf("%d%d", &N, &M);
    REP (i, M) {
	int x, y, c;
	scanf("%d%d%d", &x, &y, &c);
	x--; y--;
	E[i].x = x;
	E[i].y = y;
	E[i].c = c;
    }
    sort(E, E+M);

    VI Xs;
    REP (i, M) for (int j=i; j<M; j++) {
	// x - E[i].c <= E[j].c - x;
	// x <= (E[i].c + E[j].c) / 2;
	Xs.push_back((E[i].c + E[j].c) / 2);

	//Xs.push_back((E[i].c + E[j].c) / 2 + 1);
    }
    Xs.push_back(0);
    Xs.push_back(100000001);

    sort_unique(Xs);

    vector<LL> C0(Xs.size());
    vector<LL> C1(Xs.size());

    REP (i, Xs.size()) {
	REP (j, M) {
	    aux[j].first = abs(Xs[i] - E[j].c);
	    aux[j].second = j;
	}
	sort(aux, aux+M);
	UnionFind U(N);
	REP (j, M) {
	    int k = aux[j].second;
	    int x = E[k].x;
	    int y = E[k].y;
	    if (!U.same(x, y)) {
		U.link(x, y);
		if (E[k].c >= Xs[i]) {
		    // c - x;
		    C0[i] += E[k].c;
		    C1[i] -= 1;
		} else {
		    // x - c;
		    C0[i] -= E[k].c;
		    C1[i] += 1;
		}
	    }
	}
    }

    LL ans = 0;

    int P, K;
    LL a, b, c;
    scanf("%d%d%lld%lld%lld", &P, &K, &a, &b, &c);
    LL q;
    REP (i, K) {
	if (i < P) {
	    scanf("%lld", &q);
	} else {
	    q = (q * a + b) % c;
	}

	int g = lower_bound(Xs.begin(), Xs.end(), q) - Xs.begin();
	LL cst = C0[g] + C1[g] * q;
	ans ^= cst;
    }
    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}