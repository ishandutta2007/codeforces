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

int N, M;
LL W[200011];
int S;

VI G[200011];

bool T[200011];
int C[200011];

int par[200011];
LL down[200011];

void calc(int s) {
    par[s] = s;
    VI ord;
    ord.push_back(s);
    for (int i=0; i<(int)ord.size(); i++) {
	int v = ord[i];
	EACH (e, G[v]) if (*e != par[v] && T[*e]) {
	    par[*e] = v;
	    ord.push_back(*e);
	}
    }

    for (int i=ord.size(); i--;) {
	int v = ord[i];
	down[v] = W[v];
	EACH (e, G[v]) if (*e != par[v] && T[*e]) {
	    amax(down[v], down[*e] + W[v]);
	}
    }
}

void MAIN() {
    scanf("%d%d", &N, &M);
    REP (i, N) scanf("%lld", W+i);
    REP (i, M) {
	int x, y;
	scanf("%d%d", &x, &y);
	x--; y--;
	G[x].push_back(y);
	G[y].push_back(x);
    }
    scanf("%d", &S);
    S--;


    VI ord;
    REP (i, N) if (G[i].size() <= 1u) {
	T[i] = true;
	ord.push_back(i);
    }
    for (int i=0; i<(int)ord.size(); i++) {
	int v = ord[i];
	EACH (e, G[v]) {
	    C[*e]++;
	    if (!T[*e] && C[*e]+1 == (int)G[*e].size()) {
		T[*e] = true;
		ord.push_back(*e);
	    }
	}
    }

    LL ans = 0;

    if (N == M+1) {
	calc(S);
	ans = down[S];
    } else {
	VI hit;
	REP (v, N) if (!T[v]) EACH (e, G[v]) if (T[*e]) {
	    calc(*e);
	    hit.push_back(*e);
	}

	if (T[S]) {
	    REP (v, N) if (!T[v]) ans += W[v];

	    int x = S;
	    while (1) {
		ans += W[x];
		W[x] = 0;
		if (x == par[x]) break;
		x = par[x];
	    }

	    calc(x);

	    LL tmp = 0;
	    EACH (e, hit) amax(tmp, down[*e]);

	    ans += tmp;
	} else {
	    EACH (e, hit) amax(ans, down[*e]);
	    REP (v, N) if (!T[v]) ans += W[v];
	}
    }

    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}