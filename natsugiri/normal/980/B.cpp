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
char F[4][222];

void MAIN() {
    scanf("%d%d", &N, &K);
    puts("YES");

    REP (i, 4) REP (j, N) F[i][j] = '.';

    if (K % 2 == 0) {
	REP (j, K/2) F[1][j+1] = F[2][j+1] = '#';
    } else {
	F[1][N/2] = '#';
	int row = 1;
	int col = N/2-1;
	int rest = K-1;
	while (rest) {
	    if (col == 0) {
		row = 2;
		col = N/2-1;
	    }
	    F[row][col] = F[row][N-1-col] = '#';
	    col--;
	    rest -= 2;
	}
    }
    REP (i, 4) puts(F[i]);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}