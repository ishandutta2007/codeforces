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
int A[3], T[3];
short X[11000011];
short Y[11000011];
short Z[11000011];

int main() {
    scanf("%d %d%d%d %d%d%d", &K, A, A+1, A+2, T, T+1, T+2);

    int c = K, p = 0;
    while (c) {
	p += T[0];
	int g = min(A[0], c);
	X[p] = g;
	c -= g;
    }

    int use = 0;
    REP (i, 11000000) {
	use -= Y[i];
	if (X[i]) {
	    int g = min(A[1] - use, (int)X[i]);
	    Y[i+T[1]] += g;
	    use += g;
	    X[i+1] += X[i] - g;
	    X[i] = 0;
	}
    }

    use = 0;
    REP (i, 11000000) {
	use -= Z[i];
	if (Y[i]) {
	    int g = min(A[2] - use, (int)Y[i]);
	    Z[i+T[2]] += g;
	    use += g;
	    Y[i+1] += Y[i] - g;
	    Y[i] = 0;
	}
    }

    int ans = 0;
    REP (i, 11000011) if (Z[i]) ans = i;
    printf("%d\n", ans);
    return 0;
}