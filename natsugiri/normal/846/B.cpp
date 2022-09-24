#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)
#define eprintf(...) fprintf(stderr, __VA_ARGS__)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }
template<class Iter> void rprintf(const char *fmt, Iter begin, Iter end) {
    for (bool sp=0; begin!=end; ++begin) { if (sp) putchar(' '); else sp = true; printf(fmt, *begin); }
    putchar('\n');
}

int N, K;
LL M;
int T[55];
int sums[55];

const int SIZE = 2600;
LL dp[SIZE];

void MAIN() {
    scanf("%d%d%lld", &N, &K, &M);
    REP (i, K) scanf("%d", T+i);
    sort(T, T+K);
    REP (i, K+2) sums[i+1] = sums[i] + T[i];

    memset(dp, 0x3f, sizeof dp);
    dp[0] = 0;
    REP (i, N) {
	for (int j=SIZE-K-1; j--; ) if (dp[j] < M) {
	    for (int g=1; g<=K+1; g++) {
		amin(dp[j+g], dp[j] + sums[g]);
	    }
	}
    }

    int ans = 0;
    REP (i, SIZE) if (dp[i] <= M) ans = i;
    printf("%d\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}