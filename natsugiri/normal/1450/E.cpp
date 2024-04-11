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
int X[4011], Y[4011], B[4011];

// CC : # conected components
// C[i] : if C[i] < 0 : Black, if C[i] > 0 : White (for i=0..N-1)
// ret[i] : connected componen i (#Black, #White)
int C[4011], CC;
vector<pair<int, int> > bipartite() {
    memset(C, 0, sizeof (char) * 2 * N);
    CC = 0;
    UnionFind U(2*N);
    REP (i, M) {
	U.link(X[i], Y[i]+N);
	U.link(X[i]+N, Y[i]);
    }
    vector<pair<int, int> > ret;
    REP (i, N) if (U.same(i, i+N)) return ret; // not bipartite
    vector<int> cnt(2*N, 0);
    REP (i, N) cnt[U.root(i)]++;
    REP (i, N) {
	int a = U.root(i), b = U.root(i+N);
	if ((a == i && a < b) || (b == i+N && b < a)) {
	    ret.push_back(make_pair(cnt[a], cnt[b]));
	    CC++;
	    C[a] = -CC; C[b] = CC;
	}
    }
    REP (i, N) C[i] = C[U.root(i)];
    return ret;
}

VI G[211];
int D[211];
VI q0, q1;
bool in[211];
int cnt[211];

bool neg;
int MID;

void solve(int root) {
    memset(D, 0x3f, sizeof D);
    D[root] = 0;
    memset(in, 0, sizeof in);
    memset(cnt, 0, sizeof cnt);
    q0.clear();
    q1.clear();
    q0.push_back(root);
    in[root] = true;
    neg = false;

    while (!q0.empty()) {
	while (!q0.empty()) {
	    int v = q0.back();
	    q0.pop_back();
	    in[v] = false;

	    EACH (e, G[v]) {
		int i = *e;
		int cst, w = v ^ X[i] ^ Y[i];
		if (B[i] == 1) {
		    if (v == X[i]) { cst = 1; }
		    else { cst = -1; }
		} else if (B[i] == 0) {
		    cst = 1;
//		} else if (B[i] == 2) {
//		    cst = MID;
//		    if (C[root] != C[w]) cst = MID-1;
		} else {
		    assert(false);
		    cst = 0;
		}

		if (D[w] > D[v] + cst) {
		    D[w] = D[v] + cst;
		    if (!in[w]) {
			cnt[w]++;
			if (cnt[w] > N) {
			    neg = true;
			    return;
			}
			q1.push_back(w);
			in[w] = true;
		    }
		}
	    }
	}

	swap(q0, q1);
	reverse(q0.begin(), q0.end());
    }
}
int bestD[211];

void MAIN() {
    scanf("%d%d", &N, &M);
    REP (i, M) {
	scanf("%d%d%d", X+i, Y+i, B+i);
	X[i]--;
	Y[i]--;
    }

    auto b = bipartite();
    bool yes = !b.empty();
    if (yes) {
	REP (i, M) {
	    G[X[i]].push_back(i);
	    G[Y[i]].push_back(i);
	}


	solve(0);
	if (neg) yes = false;
    }
    if (yes) {
	REP (i, M) if (B[i] == 1) {
	    if (D[X[i]] + 1 != D[Y[i]]) {
		yes = false;
	    }
	}
    }

    int ans = -1;
    if (yes && N == 1) {
	ans = 0;
	D[0] = 0;
    }

    if (yes && N >= 2) {
	REP (s, N) {
	    solve(s);
	    if (*min_element(D, D+N) < 0) continue;


	    int tmp = *max_element(D, D+N);
	    if (ans < tmp) {
		ans = tmp;
		REP (i, N) bestD[i] = D[i];
	    }
	}
    }

    if (yes) {
	puts("YES");
	printf("%d\n", ans);
	rprintf("%d", bestD, bestD+N);
    } else {
	puts("NO");
    }

}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}