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
int A;
int C[100111];
int D[1000111];

void MAIN() {
    scanf("%d%d", &N, &A);
    REP (i, N) scanf("%d", C+i);

    int cntA = 0;
    REP (i, N) {
	int c = C[i];
	if (c == A) {
	    cntA++;
	} else {
	    if (D[c] >= cntA) {
		D[c]++;
	    } else {
		D[c] = -1;
	    }
	}
    }

    for (int B=1; B<=1000000; B++) {
	if (A == B) continue;
	if (D[B] < cntA) continue;
	printf("%d\n", B);
	return;
    }

    puts("-1");
    return;
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}