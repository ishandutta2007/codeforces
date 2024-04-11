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

int N;
int K;
int A[100011];

struct Seg {
    int a[40];

    Seg() {}

    void clear() {
	memset(a, 0, sizeof a);
    }

    Seg inc(int id) const {
	Seg z;
	REP (i, 2*K-1) z.a[i+1] = a[i];
	z.a[0] = a[2*K-1] ^ A[id];
	return z;
    }

    int eval() const {
	int r = 0;
	for (int i=K; i<2*K; i++) r ^= a[i];
	return r?1:0;
    }
};

Seg operator+(const Seg &x, const Seg &y) {
    Seg z;
    REP (i, 2*K) z.a[i] = x.a[i] ^ y.a[i];
    return z;
}

const int MAXN = 100011;
VI G[MAXN];
VI ord;
Seg up[MAXN], dw[MAXN];
int ans[MAXN];
vector<Seg> L[MAXN], R[MAXN];

void treeDP() {
    ord.clear(); ord.reserve(N);
    ord.push_back(0);
    REP (i_, N) {
	int v = ord[i_];
	EACH (e, G[v]) {
	    ord.push_back(*e);
	    G[*e].erase(remove(G[*e].begin(), G[*e].end(), v), G[*e].end()); // remove parent
	}
    }

    REP (i_, N) {
	int v = ord[N-1-i_];
	int m = G[v].size();
	L[v].assign(m+1, Seg());
	R[v].assign(m+1, Seg());

	L[v][0].clear();
	REP (i, m)
	    L[v][i+1] = L[v][i] + up[G[v][i]];

	R[v][m].clear();
	for (int i=m; i--; )
	    R[v][i] = up[G[v][i]] + R[v][i+1];
	up[v] = R[v][0].inc(v); // up[v] = L[v].all + v own, |sz[v]|;
    }

    dw[ord[0]].clear();
    REP (i_, N) {
	int v = ord[i_];
	ans[v] = (R[v][0] + dw[v]).inc(v).eval(); // when v == 0, dw[v] is an empty tree, |N|;
	REP (i, G[v].size()) {
	    int w = G[v][i];
	    dw[w] = (R[v][i+1] + dw[v] + L[v][i]).inc(v); // add v own, |N-sz[w]|;
	}
    }
}

void MAIN() {
    scanf("%d%d", &N, &K);
    REP (i, N-1) {
	int x, y;
	scanf("%d%d", &x, &y);
	x--; y--;
	G[x].push_back(y);
	G[y].push_back(x);
    }
    REP (i, N) scanf("%d", A+i);

    treeDP();

    rprintf("%d", ans, ans + N);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}