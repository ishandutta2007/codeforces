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


void MAIN() {
    int X, Y, Z;
    int A, B, C;
    scanf("%d%d%d %d%d%d", &X, &Y, &Z, &A, &B, &C);

    if (A >= X) {
	A -= X;
	if (A+B >= Y) {
	    int g = min(A, Y);
	    A -= g;
	    Y -= g;
	    g = min(B, Y);
	    B -= g;
	    Y -= g;
	    if (A+B+C >= Z) {
		puts("YES");
		return;
	    }
	}
    }

    puts("NO");
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}