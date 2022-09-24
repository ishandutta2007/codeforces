#pragma GCC optimize ("O3")
// #pragma GCC target ("avx")
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

const int DIGIT[10] ={
    1|2|4|0|16|32|64,
    0|0|4|0| 0|32| 0,
    1|0|4|8|16| 0|64,
    1|0|4|8| 0|32|64,
    0|2|4|8| 0|32| 0,
    1|2|0|8| 0|32|64,
    1|2|0|8|16|32|64,
    1|0|4|0| 0|32| 0,
    1|2|4|8|16|32|64,
    1|2|4|8| 0|32|64,
};

int N, K;
int A[2011];
char S[111];
char dp[2111][2111];
char cst[2111][2111];

void MAIN() {
    //REP (d, 10) {
    //    int D = DIGIT[d];
    //    printf(" %d \n", D>>0&1);
    //    printf("%d %d\n", D>>1&1, D>>2&1);
    //    printf(" %d \n", D>>3&1);
    //    printf("%d %d\n", D>>4&1, D>>5&1);
    //    printf(" %d \n", D>>6&1);
    //    puts("");
    //    assert((D>>7) == 0);
    //}
    scanf("%d%d", &N, &K);
    REP (i, N) {
	scanf("%s", S);
	int mask = 0;
	REP (j, 7) if (S[j] == '1') mask |= 1<<j;
	A[i] = mask;
    }

    dp[0][0] = '.';
    REP (i, N) {
	int a = A[N-1-i];
	REP (d, 10) if ((DIGIT[d]&a) == a) {
	    int add = __builtin_popcount(DIGIT[d]^a);
	    REP (k, K+1) {
		if (dp[i][k] && dp[i+1][k+add] < d + '0') {
		    dp[i+1][k+add] = d + '0';
		    cst[i+1][k+add] = add;
		}
	    }
	}
    }

    if (dp[N][K]) {
	REP (i, N) {
	    putchar(dp[N][K]);
	    K -= cst[N][K];
	    N--;
	}
	putchar('\n');
	assert(K == 0);
    } else {
	puts("-1");
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}