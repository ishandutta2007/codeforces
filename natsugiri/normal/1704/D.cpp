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

int N, M;
vector<LL> C[100011];
LL Z[100011];

void MAIN() {
    scanf("%d%d", &N, &M);
    REP (i, N) {
	C[i].resize(M);
	REP (j, M) scanf("%lld", &C[i][j]);
    }

    REP (i, N) {
	LL tmp = 0;
	REP (j, M) tmp += (LL)j * C[i][j];
	Z[i] = tmp;
    }

    int c = count(Z, Z+N, Z[0]);
    int K = 0;
    LL OP = 0;
    if (c == 1) {
	K = 0;
	OP = Z[0] - Z[1];
    } else {
	REP (i, N) if (Z[i] != Z[0]) {
	    K = i;
	    OP = Z[i] - Z[0];
	    break;
	}
    }
    printf("%d %lld\n", K+1, OP);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}