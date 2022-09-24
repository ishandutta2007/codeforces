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

namespace CLIQUE {
;
const int MAXN = 64;
int n;
LL b[MAXN]; // neighber;
LL ans;
int ans_size;

void build(int n_, VI *g) {
    n = n_;
    REP (v, n) {
	b[v] = 0;
	EACH (e, g[v]) b[v] |= 1LL<<*e;
    }

    ans = 0;
    ans_size = 0;
}

// r: subset, current clique;
// p: subset, improves clique;
// x: subset, already checked;
void solve(LL r=0, LL p=-1LL, LL x=0LL) {
    if (p == 0 && x == 0) {
	int s = __builtin_popcountll(r);
	if (ans_size < s) {
	    ans = r;
	    ans_size = s;
	}
	return;
    }

    if (p == 0 || ans_size >= __builtin_popcountll(r | p)) {
	return;
    }

    int pivot = -1;
    REP (v, n) if ((p | x) >> v & 1) {
	if (pivot == -1 || __builtin_popcountll(p & b[pivot]) < __builtin_popcountll(p & b[v])) {
	    pivot = v;
	}
    }
    REP (v, n) if ((p & ~b[pivot]) >> v & 1) {
	solve(r | (1LL<<v), p & b[v], x & b[v]);
	p &= ~(1LL<<v);
	x |= 1LL<<v;
    }
}
};
int N, K;
int A[44][44];
VI G[44];
bool use[44];

int ans;

void MAIN() {
    scanf("%d%d", &N, &K);
    REP (i, N) REP (j, N) scanf("%d", &A[i][j]);
    REP (i, N) REP (j, N) if (A[i][j]) G[i].push_back(j);

    CLIQUE::build(N, G);
    CLIQUE::solve();
    int s = CLIQUE::ans_size;

    if (s <= 1) {
	puts("0.0");
    } else {
	double t = (double) K * K * (s - 1) / 2 / s;
	printf("%.12f\n", t);
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}