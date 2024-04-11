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

// transpose n = 2, m = 3 -> n = 3, m = 2
// 0 1 2    0 3 .
// 3 4 5 -> 1 4 .
// . . .    2 5 .
template<class T, int SIZE> void transpose(T a[][SIZE], int n, int m) {
    if (n < m) swap(n, m);
    for (int i=1; i<n; i++) for (int j=min(i, m); j--; ) swap(a[i][j], a[j][i]);
}

int N, M, K;
char F[2111][2111];

int solve() {
    int ret = 0;
    REP (i, N) {
	int cnt = 0;
	REP (j, M) {
	    if (F[i][j] == '.') cnt++;
	    else cnt = 0;
	    if (cnt >= K) ret++;
	}
    }
    return ret;
}

void MAIN() {
    scanf("%d%d%d", &N, &M, &K);
    REP (i, N) scanf("%s", F[i]);

    int ans = 0;
    ans += solve();
    if (K != 1) {
	transpose(F, N, M);
	swap(N, M);
	ans += solve();
    }

    printf("%d\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}