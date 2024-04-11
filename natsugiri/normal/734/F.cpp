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
LL A[200111], B[200111], C[200111], D[200111];
LL B2[200111], C2[200111];

int main() {
    scanf("%d", &N);
    REP (i, N) scanf("%lld", B+i);
    REP (i, N) scanf("%lld", C+i);
    REP (i, N) D[i] = C[i] + B[i];

    LL sum = 0;
    REP (i, N) sum += D[i];
    LL S = sum / 2 / N;
    REP (i, N) A[i] = (D[i] - S) / N;
    REP (d, 40) {
	LL x = 0;
	REP (i, N) if (A[i] & (1LL << d)) x++;
	REP (i, N) {
	    if (A[i] & (1LL << d)) {
		B2[i] += x << d;
		C2[i] += (LL)N << d;
	    } else {
		C2[i] += x << d;
	    }
	}
    }

    bool yes = true;
    REP (i, N) if (B[i] != B2[i] || C[i] != C2[i]) yes = false;

    if (yes) {
	rprintf("%lld", A, A+N);
    } else {
	puts("-1");
    }

    return 0;
}