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

int Q;
int A[300011];
int C[300011];
int par[19][300011];
int limit[300011];

int rest;
LL ans_w;
LL ans_c;

void rec(int v) {
    if (rest == 0) return;

    while (limit[v] >= 0) {
	int p = par[limit[v]][v];
	if (A[p]) rec(p);
	if (rest == 0) return;
	limit[v]--;
    }

    int g = min(rest, A[v]);

    A[v] -= g;
    rest -= g;
    ans_w += g;
    ans_c += (LL)C[v] * g;
}

void MAIN() {
    scanf("%d%d%d", &Q, A, C);

    memset(par, -1, sizeof par);
    REP (t, 19) par[t][0] = 0;
    limit[0] = -1;

    for (int i=1; i<=Q; i++) {
	static char op[11];
	scanf("%s", op);
	if (*op == '1') {
	    int p, a, c;
	    scanf("%d%d%d", &p, &a, &c);

	    A[i] = a;
	    C[i] = c;
	    limit[i] = 18;

	    int v = i;
	    par[0][v] = p;
	    REP (t, 18) {
		par[t+1][v] = par[t][par[t][v]];
	    }
	} else {
	    int v;
	    scanf("%d%d", &v, &rest);

	    ans_c = ans_w = 0;
	    rec(v);
	    printf("%lld %lld\n", ans_w, ans_c);
	    fflush(stdout);
	}
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}