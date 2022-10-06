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

int N, K;
VI A;
VI test() {
    VI B(N+1, -1);
    int small = 0, large = N+1;
    for (int i=1; i<=N; i++) {
	if (A[i] <= K) {
	    B[A[i]] = large;
	    small = A[i];
	} else {
	    B[A[i]] = small;
	    large = A[i];
	}
    }
    return B;
}

int B[100011];
VI G[100011];

void MAIN() {
    scanf("%d", &N);
    for (int i=1; i<=N; i++) scanf("%d", B+i);

    REP (i, N+2) G[i].clear();
    for (int i=1; i<=N; i++) {
	G[B[i]].push_back(i);
    }
    int turn = 0;
    int prv = 0;
    if (!G[0].empty()) {
	prv = 0;
	turn = 0;
    } else {
	prv = N+1;
	turn = 1;
    }

    A.clear();
    A.push_back(-1);
    K = -1;

    while (1) {
	int nxt = -1;
	EACH (e, G[prv]) {
	    if (!G[*e].empty()) nxt = *e;
	}
	EACH (e, G[prv]) {
	    assert(G[*e].empty() || nxt == *e);

	    if (*e != nxt) A.push_back(*e);
	}
	if (turn == 1) {
	    EACH (e, G[prv]) {
		amax(K, *e);
	    }
	}
	turn = 1 - turn;

	if (nxt == -1) break;
	A.push_back(nxt);
	prv = nxt;
    }

    amax(K, 0);
    printf("%d\n", K);
    rprintf("%d", A.begin()+1, A.end());
    assert((int)A.size() == N+1);

//#ifdef MYTEST
//    VI B2 = test();
//    rprintf("%d", B2.begin()+1, B2.end());
//#endif
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}