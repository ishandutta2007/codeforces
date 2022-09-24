#pragma GCC optimize ("O3")
// #pragma GCC target ("avx")
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

const int MAXN = 200011;
int N;
VI G[MAXN];

struct Seg {
    int sz;
    LL f, g;
    Seg() { // empty seg;
	sz = f = g = 0;
    } 
    Seg inc(int id) const {
	Seg z;
	z.sz = 1;
	z.f = g;
	z.g = f + sz;
	return z;
    }
};
Seg operator+(const Seg &x, const Seg &y) {
    Seg z;
    z.sz = x.sz + y.sz;
    z.f = x.f + y.f;
    z.g = x.g + y.g;
    return z;
}

VI ord;
Seg up[MAXN], dw[MAXN];
vector<Seg> L[MAXN], R[MAXN];
LL ans;

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
	REP (i, m)
	    L[v][i+1] = L[v][i] + up[G[v][i]];
	for (int i=m; i--; )
	    R[v][i] = up[G[v][i]] + R[v][i+1];
	up[v] = R[v][0].inc(v); // up[v] = L[v].all + v own, |sz[v]|;
	// eprintf("%d : %d %lld %lld\n", v+1, up[v].sz, up[v].f, up[v].g);
    }

    dw[ord[0]] = Seg();
    REP (i_, N) {
	int v = ord[i_];
	Seg guess = (R[v][0] + dw[v]).inc(v); // when v == 0, dw[v] is an empty tree, |N|;
	amin(ans, guess.f);
	REP (i, G[v].size()) {
	    int w = G[v][i];
	    dw[w] = (R[v][i+1] + dw[v] + L[v][i]).inc(v); // add v own, |N-sz[w]|;
	}
    }
}


void MAIN() {
//#ifdef LOCAL
//    N = 200000;
//    REP (i, N-1) {
//	int p = rand() % (i+1);
//	G[p].push_back(i+1);
//	G[i+1].push_back(p);
//    }
//#else
    scanf("%d", &N);
    REP (i, N-1) {
	int x, y;
	scanf("%d%d", &x, &y);
	x--; y--;
	G[x].push_back(y);
	G[y].push_back(x);
    }
//#endif

    ans = 1LL<<60;
    treeDP();
    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}