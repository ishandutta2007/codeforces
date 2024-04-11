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

const int MAXN = 1000111;
int N, K;
VI G[MAXN];
int par[MAXN];
int up[MAXN];
int has[MAXN];
int dp[MAXN];

void MAIN() {
    scanf("%d%d", &N, &K);
    REP (i, N-1) {
	int p;
	scanf("%d", &p);
	p--;
	G[p].push_back(i+1);
	G[i+1].push_back(p);
    }

    VI ord;
    ord.reserve(N);
    ord.push_back(0);
    REP (i_, N) {
	int v = ord[i_];
	EACH (e, G[v]) if (*e != par[v]) {
	    par[*e] = v;
	    ord.push_back(*e);
	}
    }
    REP (i_, N-1) {
	int v = ord[N-1-i_];
	if (G[v].size() == 1u) {
	    up[v] = K;
	    has[v] = 1;
	}
	if (up[v] > 0) {
	    amax(up[par[v]], up[v] - 1);
	    has[par[v]] += has[v];
	    has[v] = 0;
	}
    }

    REP (i_, N) {
	int v = ord[N-1-i_];
	EACH (e, G[v]) if (*e != par[v]) {
	    amax(dp[v], dp[*e]);
	}
	dp[v] += has[v];
    }

    printf("%d\n", dp[0]);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}