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

int X[5], Y[5];

void MAIN() {
    REP (i, 3) scanf("%d%d", X+i, Y+i);

    int best = 1<<29;
    int bestX = 0, bestY = 0;

    for (int x=-1000; x<=1000; x++) for (int y=-1000; y<=1000; y++) {
	int cst = 0;
	REP (i, 3) {
	    cst += abs(x - X[i]);
	    cst += abs(y - Y[i]);
	}

	if (cst < best) {
	    best = cst;
	    bestX = x;
	    bestY = y;
	}
    }

    printf("%d\n", best + 1);
    printf("%d %d\n", bestX, bestY);
    REP (i, 3) {
	int x = bestX, y = bestY;
	while (x != X[i] || y != Y[i]) {
	    if (x < X[i]) {
		x++;
	    } else if (X[i] < x) {
		x--;
	    } else if (y < Y[i]) {
		y++;
	    } else {
		y--;
	    }

	    printf("%d %d\n", x, y);
	}
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}