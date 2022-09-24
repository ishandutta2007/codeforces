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

int N;
int A[100];

const int INF = 1<<30;

int solve(int a, int b, int c) {
    LL x = 1;
    REP (i, a) x |= x << 1;
    REP (i, b) x |= x << 2;
    REP (i, c) x |= x << 3;

    int ret = 0;

    REP (i, N) {
	int cst = INF;
	for (int s=A[i]%3; s<32 && s<=A[i]; s+=3) if (x>>s&1) {
	    cst = (A[i] - s) / 3;
	}
	amax(ret, cst);
    }

    return ret + a + b + c;
}


void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);

    int ans = INF;
    REP (a, 3) REP (b, 3) REP (c, 3) amin(ans, solve(a, b, c));
    printf("%d\n", ans);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}