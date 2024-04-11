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

int K;
const int LIMIT = 100111;
int dp[27][LIMIT];

void MAIN() {
    scanf("%d", &K);

    memset(dp, -1, sizeof dp);
    dp[0][0] = 0;
    REP (c, 3) REP (i, LIMIT) if (dp[c][i] != -1) {
	for (int t=0; t*(t-1)/2 + i < LIMIT; t++) if (dp[c+1][t*(t-1)/2+i] == -1) {
	    dp[c+1][t*(t-1)/2 + i] = t;
	}
    }

    putchar('z');
    for (int c=3; c>0; c--) {
	int t = dp[c][K];
	printf("%s", string(t, 'a' + c).c_str());
	K -= t * (t-1)/2;
    }
    puts("");
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}