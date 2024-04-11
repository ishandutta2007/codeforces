#include<unordered_map>
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

int N, H, M;
int L[55], R[55], X[55], C[55];

LL dp[55][55][55];
LL D[55];


void MAIN() {
    scanf("%d%d%d", &N, &H, &M);
    REP (i, M) {
	scanf("%d%d%d%d", L+i, R+i, X+i, C+i), L[i]--;
    }

    for (int l=N; l--;) {
	REP (h, H+1) {
	    memset(D, 0, sizeof D);
	    REP (i, M) if (l == L[i] && l+1 == R[i]) {
		D[X[i]+1] += C[i];
	    }
	    REP (a, h+1) {
		D[a+1] += D[a];
		LL tmp = a*a - D[a];
		amax(dp[l][l+1][h], tmp);
	    }
	}

	for (int k=l; k<N; k++) for (int r=k+1; r<=N; r++) REP (h, H+1) {
	    memset(D, 0, sizeof D);
	    REP (i, M) if (l <= L[i] && L[i] <= k && k < R[i] && R[i] <= r) {
		D[X[i]+1] += C[i];
	    }
	    REP (a, h+1) {
		D[a+1] += D[a];
		LL tmp = a*a - D[a] + dp[l][k][a] + dp[k+1][r][a];
		amax(dp[l][r][h], tmp);
	    }
	}
    }

    LL ans = dp[0][N][H];
    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}