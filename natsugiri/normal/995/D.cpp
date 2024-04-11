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

const int SIZE = 1<<18;
int N, R;
int C[SIZE+11];
int Z[SIZE+11];
int G[SIZE+11];


void MAIN() {
    scanf("%d%d", &N, &R);
    REP (i, 1<<N) scanf("%d", C+i);
    REP (i, R) scanf("%d%d", Z+i, G+i);

    LL sum = 0;
    REP (i, 1<<N) sum += C[i];
    REP (i, R+1) {
	printf("%.12f\n", (double)sum / (1<<N));

	if (i == R) break;

	sum = sum - C[Z[i]] + G[i];
	C[Z[i]] = G[i];
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}