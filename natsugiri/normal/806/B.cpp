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
int A[5], B[5], O[5];

void test() {
    N = 120;
    memset(A, -1, sizeof A);
    A[0] = 119;
    REP (i, 5) {
	A[i] = 119;
	B[i] = 0;
	O[i] = 0;
    }
    B[0] = -1;
    O[0] = N-2;
}

inline LL score(int ac, int num) {
    if (ac * 2 > num) return 1;
    if (ac * 4 > num) return 2;
    if (ac * 8 > num) return 3;
    if (ac * 16 > num) return 4;
    if (ac * 32 > num) return 5;
    return 6;
}

void MAIN() {
    scanf("%d", &N);
    REP (i, 5) scanf("%d", A+i);
    REP (i, 5) scanf("%d", B+i);
    REP (t, N-2) {
	REP (i, 5) {
	    int x;
	    scanf("%d", &x);
	    if (x != -1) O[i]++;
	}
    }

//    test();

    for (int g=0; g<=N*33 + 10; g++) {
	LL tot = 0;
	REP (i, 5) {
	    if (A[i] == -1) {
		if (B[i] != -1) {
		    tot -= score(O[i] + 1, N + g) * (500 - 2 * B[i]);
		}
	    } else {
		if (B[i] == -1) {
		    tot += score(O[i] + 1, N + g) * (500 - 2 * A[i]);
		} else {
		    LL tmp = - (1LL<<60);
		    REP (k, g+1) {
			amax(tmp, score(O[i] + 2 + k, N + g) * (2 * B[i] - 2 * A[i]));
		    }
		    tot += tmp;
		}
	    }
	}

	if (tot > 0) {
	    printf("%d\n", g);
	    return;
	}
    }

    puts("-1");
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}