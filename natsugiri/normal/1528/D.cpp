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

template<class T> inline void amin(T &x, const T y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T y) { if (x<y) x=y; }
#define rprintf(fmt, begin, end) do { const auto end_rp = (end); auto it_rp = (begin); for (bool sp_rp=0; it_rp!=end_rp; ++it_rp) { if (sp_rp) putchar(' '); else sp_rp = true; printf(fmt, *it_rp); } putchar('\n'); } while(0)

int N, M;
int C[611][611];

LL ADJ[611][611];
LL E[611];
bool fix[611];


void MAIN() {
    scanf("%d%d", &N, &M);

    memset(C, -1, sizeof C);
    REP (i, M) {
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	C[a][b] = c;
    }

    memset(ADJ, 0x3f, sizeof ADJ);

    REP (from, N) {
	LL *D = ADJ[from];

	memset(fix, 0, sizeof fix);
	D[from] = 0;

	REP (z, N) {
	    int v = -1;
	    REP (i, N) if (!fix[i] && (v == -1 || D[v] > D[i])) v = i;
	    assert(v != -1);
	    fix[v] = true;

	    memset(E, 0x3f, sizeof E);

	    int add = D[v] % N;

	    REP (i, N) {
		if (C[v][i] != -1) {
		    int to = i + add;
		    if (to >= N) to -= N;
		    if (E[to] > D[v] + C[v][i]) {
			E[to] = D[v] + C[v][i];
		    }
		}
	    }

	    REP (t, 2) REP (i, N) {
		int j = i+1;
		if (j >= N) j -= N;
		if (E[j] > E[i]+1) {
		    E[j] = E[i]+1;
		}
	    }
	    REP (i, N) {
		if (D[i] > E[i]) {
		    D[i] = E[i];
		}
	    }
	}
    }


    REP (i, N) rprintf("%lld", ADJ[i], ADJ[i]+N);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}