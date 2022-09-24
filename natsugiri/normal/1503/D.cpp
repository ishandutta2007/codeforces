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
int A[200011];
int B[200011];
int F[200011];

int idx[200011];
bool isO[200011];

int cost[200011][2];


void MAIN() {
    scanf("%d", &N);
    REP (i, N) {
	scanf("%d%d", A+i, B+i);
	if (A[i] < B[i]) {
	    swap(A[i], B[i]);
	    F[i] = 1;
	}
    }

    bool yes = true;

    int high = -1;
    int low = 1<<29;

    REP (i, N) {
	amax(high, min(A[i], B[i]));
	amin(low, max(A[i], B[i]));
    }

    if (low < high) {
	yes = false;
    }

    VI Z, O;
    if (yes) {
	REP (i, N) idx[i] = i;
	sort(idx, idx+N, [&](int i, int j) {
		return A[i] < A[j];
		});

	int lis0 = 1<<29;
	int lis1 = 1<<29;

	REP (i_, N) {
	    int i = idx[i_];
	    if (B[i] < lis0) {
		Z.push_back(i);
		lis0 = B[i];
	    } else if (B[i] < lis1) {
		isO[i] = true;
		O.push_back(i);
		lis1 = B[i];
	    } else {
		yes = false;
		break;
	    }
	}
    }

    if (yes) {
	UnionFind U(N);

	VI As, Bs;
	As.resize(Z.size());
	Bs.resize(Z.size());
	REP (i, Z.size()) {
	    As[i] = A[Z[i]];
	    Bs[i] = -B[Z[i]];
	}

	VI sumsZ(Z.size()+1);

	EACH (e, O) {
	    int i = *e;
	    int x = lower_bound(As.begin(), As.end(), A[i]) - As.begin();
	    int y = lower_bound(Bs.begin(), Bs.end(), -B[i]) - Bs.begin();
	    if (y < x) {
		U.link(Z[y], i);
		sumsZ[y]++;
		sumsZ[x-1]--;
	    }
	}
	REP (i, Z.size()) {
	    sumsZ[i+1] += sumsZ[i];
	    if (i+1 < (int)Z.size() && sumsZ[i]) {
		U.link(Z[i], Z[i+1]);
	    }
	}

	///////////////////////////////////////////////////////////
	As.resize(O.size());
	Bs.resize(O.size());
	REP (i, O.size()) {
	    As[i] = A[O[i]];
	    Bs[i] = -B[O[i]];
	}
	VI sumsO(O.size()+1);
	EACH (e, Z) {
	    int i = *e;
	    int x = lower_bound(As.begin(), As.end(), A[i]) - As.begin();
	    int y = lower_bound(Bs.begin(), Bs.end(), -B[i]) - Bs.begin();
	    if (x < y) {
		U.link(O[x], i);
		sumsO[x]++;
		sumsO[y-1]--;
	    }
	}
	REP (i, O.size()) {
	    sumsO[i+1] += sumsO[i];
	    if (i+1 < (int)O.size() && sumsO[i]) {
		U.link(O[i], O[i+1]);
	    }
	}

	REP (i, N) {
	    int r = U.root(i);
	    // eprintf("%d %d\n", r, i);
	    if (isO[i]) {
		cost[r][0] += 1-F[i];
		cost[r][1] += F[i];
	    } else {
		cost[r][0] += F[i];
		cost[r][1] += 1-F[i];
	    }
	}
    }

    if (yes) {
	int ans = 0;
	REP (i, N) {
	    ans += min(cost[i][0], cost[i][1]);
	}
	printf("%d\n", ans);
    } else {
	puts("-1");
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}