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

int N;
char F[4][111][111];

void MAIN() {
    scanf("%d", &N);
    REP (t, 4) {
	REP (i, N) scanf("%s", F[t][i]);
    }

    int ans = N*N*4;
    REP (a, 4) REP (b, a) {
	int mask = (1<<a) | (1<<b);
	int cost = 0;
	REP (t, 4) REP (i, N) REP (j, N) {
	    int tar = (mask>>t&1) ^ i ^ j;
	    char c = '0' | (tar&1);
	    if (F[t][i][j] != c) cost++;
	}

	amin(ans, cost);
    }

    printf("%d\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}