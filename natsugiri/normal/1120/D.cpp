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
int C[MAXN];
VI G[MAXN];
int par[MAXN];

LL dpA[MAXN], dp1[MAXN];
bool bA[MAXN], b1[MAXN];
bool act[MAXN];

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", C+i);
    REP (i, N-1) {
	int x, y;
	scanf("%d%d", &x, &y);
	x--; y--;
	G[x].push_back(y);
	G[y].push_back(x);
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

    memset(dpA, 0x3f, sizeof dpA);
    memset(dp1, 0x3f, sizeof dp1);

    REP (i_, N) {
	int v = ord[N-1-i_];
	if (v != 0 && G[v].size() == 1u) {
	    dpA[v] = C[v];
	    dp1[v] = 0;
	} else {
	    LL sum = 0;
	    EACH (e, G[v]) if (*e != par[v]) {
		sum += dpA[*e];
	    }
	    dpA[v] = sum;
	    EACH (e, G[v]) if (*e != par[v]) {
		amin(dpA[v], sum - dpA[*e] + dp1[*e] + C[v]);
		amin(dp1[v], sum - dpA[*e] + dp1[*e]);
	    }
	}
    }

    bA[0] = true;
    REP (i_, N) {
	int v = ord[i_];

	if (v != 0 && G[v].size() == 1u) {
	    if (bA[v]) act[v] = true;
	} else {
	    LL sum = 0;
	    EACH (e, G[v]) if (*e != par[v]) {
		sum += dpA[*e];
	    }

	    if (bA[v]) {
		VI c;
		EACH (e, G[v]) if (*e != par[v]) {
		    if (dpA[v] == sum - dpA[*e] + dp1[*e] + C[v]) {
			act[v] = true;
			b1[*e] = true;
			if (c.size() <= 1u) c.push_back(*e);
		    }
		}

		if (c.size() >= 2u || dpA[v] == sum) {
		    EACH (e, G[v]) if (*e != par[v]) {
			bA[*e] = true;
		    }
		} else if (c.size() == 1u) {
		    EACH (e, G[v]) if (*e != par[v] && *e != c[0]) {
			bA[*e] = true;
		    }
		}
	    }

	    if (b1[v]) {
		VI c;
		EACH (e, G[v]) if (*e != par[v]) {
		    if (dp1[v] == sum - dpA[*e] + dp1[*e]) {
			b1[*e] = true;
			if (c.size() <= 1u) c.push_back(*e);
		    }
		}

		if (c.size() >= 2u) {
		    EACH (e, G[v]) if (*e != par[v]) {
			bA[*e] = true;
		    }
		} else if (c.size() == 1u) {
		    EACH (e, G[v]) if (*e != par[v] && *e != c[0]) {
			bA[*e] = true;
		    }
		}
	    }
	}
    }

    LL ans = dpA[0];
    VI ansv;
    REP (i, N) if (act[i]) ansv.push_back(i+1);
    printf("%lld %d\n", ans, (int)ansv.size());
    rprintf("%d", ansv.begin(), ansv.end());
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}