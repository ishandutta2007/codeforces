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

int N, Q;
int X[200011];
int Y[200011];
int W[200011];
int ans[200011];

char S[100011];
VI G[100011];

VI stk;

void ZERO() {
    while (!stk.empty()) {
	int v = stk.back();
	stk.pop_back();
	EACH (e, G[v]) {
	    S[*e] = '1';
	}
    }
}

void MAIN() {
    scanf("%d%d", &N, &Q);
    REP (i, Q) {
	int x, y, w;
	scanf("%d%d%d", &x, &y, &w);
	x--; y--;
	X[i] = x;
	Y[i] = y;
	W[i] = w;
    }

    REP (t, 30) {
	REP (i, N) {
	    S[i] = '?';
	    G[i].clear();
	}

	REP (i, Q) {
	    int x = X[i];
	    int y = Y[i];
	    int w = W[i];
	    if (w >> t & 1) {
		G[x].push_back(y);
		G[y].push_back(x);
	    } else {
		S[x] = '0';
		S[y] = '0';
	    }
	}

	stk.clear();
	REP (i, N) if (S[i] == '0') stk.push_back(i);

	REP (i, N) {
	    ZERO();
	    if (S[i] == '?') {
		S[i] = '0';
		stk.push_back(i);
	    }
	}

	ZERO();

	REP (i, N) ans[i] |= (S[i]-'0') << t;
    }
    rprintf("%d", ans, ans+N);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}