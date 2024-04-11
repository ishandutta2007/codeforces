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

int A, B, C, D;
char S[55][55];

void go(char c, int t, int sy, int sx) {
    for (int i=1; i<24; i+=2) {
	for (int j=1; j<24; j+=2) {
	    if (t > 0) {
		S[i+sy][j+sx] = c;
		t--;
	    }
	}
    }
}

void MAIN() {
    scanf("%d%d%d%d", &A, &B, &C, &D);

    REP (i, 25) REP (j, 25) {
	S[i][j] = 'A';
	S[i][j+25] = 'B';
	S[i+25][j] = 'C';
	S[i+25][j+25] = 'D';
    }

    go('B', B-1, 0, 0);
    go('A', A-1, 0, 25);
    go('D', D-1, 25, 0);
    go('C', C-1, 25, 25);

    puts("50 50");
    REP (i, 50) puts(S[i]);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}