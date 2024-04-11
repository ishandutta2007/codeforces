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

const int INF = 1<<29;
int N;
LL H, W, Y, X;
LL A[100111];

int ans;

const int SIZE = 19;
void rec(LL y0, LL x0, int I) {
    if (Y <= H * y0 && X <= W * x0) { amin(ans, I); return;}
    if (X <= H * y0 && Y <= W * x0) { amin(ans, I); return;}
    if (Y <= H * x0 && X <= W * y0) { amin(ans, I); return;}
    if (X <= H * x0 && Y <= W * y0) { amin(ans, I); return;}

    if (I == N || I == SIZE || I >= ans) {
	return ;
    } else {
	if (y0 <= 100000) rec(y0 * A[I], x0, I+1);
	if (x0 <= 100000) rec(y0, x0 * A[I], I+1);
    }
}

const int MAX = 1000111;
bool dp[MAX];
int solve() {
    memset(dp, 0, sizeof dp);
    dp[1] = true;

    LL prod = 1;

    REP (i, min(N, 40)) {
	for (int j=MAX; j--;) {
	    if (dp[j] && j * A[i] < MAX) {
		dp[j * A[i]] = true;

		if (Y <= H * j * A[i] && X <= W * (prod / j)) return i+1;
	    }
	}

	prod *= A[i];
	amin(prod, 1000000000000LL);
    }
    return INF;
}

void MAIN() {
    scanf("%lld%lld%lld%lld%d", &Y, &X, &H, &W, &N);
    REP (i, N) scanf("%lld", A+i);

    sort(A, A+N);
    reverse(A, A+N);

    ans = INF;
    rec(1, 1, 0);

    if (ans == INF) {
	REP (a, 2) {
	    REP (b, 2) {
		amin(ans, solve());
		swap(Y, X);
	    } 
	    swap(H, W);
	}
    }

    if (ans > N) ans = -1;
    printf("%d\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}