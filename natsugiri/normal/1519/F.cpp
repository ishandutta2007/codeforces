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

struct State {
    int a[6];
    int j, i, f;
};

int encode(State s) {
    int e = 0;
    REP (i, 6) e = e * 5 + s.a[i];
    e = e * 6 + s.j;
    e = e * 6 + s.i;
    e = e * 5 + s.f;
    return e;
}

State decode(int e) {
    State s;
    s.f = e % 5; e /= 5;
    s.i = e % 6; e /= 6;
    s.j = e % 6; e /= 6;
    for (int i=6; i--;) {
	s.a[i] = e % 5;
	e /= 5;
    }
    return s;
}


int N;
int M;
int A[6];
int B[6];

int C[6][6];
const int SIZE = 3000111;
int dp[SIZE];


void MAIN() {
    scanf("%d%d", &N, &M);
    REP (i, N) scanf("%d", A+i);
    REP (i, M) scanf("%d", B+i);
    REP (i, N) REP (j, M) scanf("%d", &C[i][j]);

    memset(dp, 0x3f, sizeof dp);
    const int INF = dp[0];
    int ans = INF;
    dp[0] = 0;

    REP (e, SIZE) {
	if (dp[e] == INF) continue;

	const State s = decode(e);

	for (int f=0; s.a[s.i] + f <= A[s.i] && s.f + f <= B[s.j]; f++) {
	    State ns = s;
	    ns.a[s.i] += f;
	    ns.f += f;
	    int c = (f == 0? 0: C[s.i][s.j]);
	    ns.i++;
	    if (ns.i == N) {
		ns.i = 0;
		ns.j++;
		ns.f = 0;

		if (ns.j == M) {
		    bool same = true;
		    REP (i, N) if (ns.a[i] != A[i]) same = false;
		    if (same) {
			amin(ans, dp[e] + c);
		    }
		}
	    }

	    if (ns.j != M) {
		amin(dp[encode(ns)], dp[e] + c);
	    }
	}
    }

    if (ans == INF) puts("-1");
    else printf("%d\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}