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

LL K;
int SA, SB;
int A[3][3];
int B[3][3];
int dp[3][3];

int TA[112], TB[112];


void MAIN() {
    scanf("%lld%d%d", &K, &SA, &SB);
    SA--; SB--;
    REP (i, 3) REP (j, 3) scanf("%d", A[i]+j), A[i][j]--;
    REP (i, 3) REP (j, 3) scanf("%d", B[i]+j), B[i][j]--;

    memset(dp, -1, sizeof dp);
    int xa = SA, xb = SB, cnt = 0;
    while (1) {
	TA[cnt+1] = TA[cnt];
	TB[cnt+1] = TB[cnt];
	if (xa == (xb+1) % 3) TA[cnt+1]++;
	if (xb == (xa+1) % 3) TB[cnt+1]++;

	if (dp[xa][xb] != -1) break;
	dp[xa][xb] = cnt;
	cnt++;
	int ya = A[xa][xb];
	int yb = B[xa][xb];
	xa = ya;
	xb = yb;
    }

    int z = dp[xa][xb];
    int c = cnt - z;
    LL ansA = 0, ansB = 0;
    if (K <= cnt+1) {
	ansA = TA[K];
	ansB = TB[K];
    } else {
	ansA = TA[z] + (K-z) / c * (TA[cnt] - TA[z]) + (TA[(K-z)%c+z] - TA[z]);
	ansB = TB[z] + (K-z) / c * (TB[cnt] - TB[z]) + (TB[(K-z)%c+z] - TB[z]);
    }

    printf("%lld %lld\n", ansA, ansB);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}