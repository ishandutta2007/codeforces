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
const int BASE[11] = {
    0,
    10,
    11,
    13,
    16,
    20,
    25,
    31,
    38,
    46,
    0
};

int N;
char S[100011];
LL dp[100011][11];
void MAIN() {
    scanf("%s", S);
    N = strlen(S);
    REP (i, N) {
	int t = S[i] - '0';
	if (t > 0) {
	    dp[i+1][t] += 1;
	}
	for (int z=t+1; z<=10; z++) {
	    dp[i+1][(BASE[z] + t)%11] += dp[i][z];
	}
    }

    LL ans = 0;
    REP (i, N+1) REP (t, 11) ans += dp[i][t];
    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}