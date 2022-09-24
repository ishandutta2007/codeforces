#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>

#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define NDEBUG
#define eprintf(...) do {} while (0)
#endif
#include<cassert>

using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }
template<class Iter> void rprintf(const char *fmt, Iter begin, Iter end) {
    for (bool sp=0; begin!=end; ++begin) { if (sp) putchar(' '); else sp = true; printf(fmt, *begin); }
    putchar('\n');
}

int N, Q;
int A[100011];
char S[100011];
int X[100011];
int ans[100011];

const int BASE = 100022;
int V[BASE*2];
void MAIN() {
    scanf("%d%d", &N, &Q);
    REP (i, N) scanf("%d", A+i);
    REP (i, Q) scanf("%s%d", S+i, X+i);

    int low = -100011, high = 100011;
    int sgn = 1;
    for (int i=Q; i--;) {
	int add = 0;
	if (S[i] == '>') {
	    int v;
	    if (X[i] >= 0) {
		v = X[i]+1;
	    } else {
		v = -X[i];
		add = 1;
	    }
	    // -
	    while (v <= high) {
		V[BASE+high] = -high * sgn;
		high--;
	    }
	    while (v <= -low) {
		V[BASE+low] = low * sgn;
		low++;
	    }
	} else {
	    int v;
	    if (X[i] <= 0) {
		v = -X[i]+1;
	    } else {
		v = X[i];
		add = 1;
	    }
	    // +
	    while (v <= high) {
		V[BASE+high] = high * sgn;
		high--;
	    }
	    while (v <= -low) {
		V[BASE+low] = -low * sgn;
		low++;
	    }
	}
	if (add) sgn = -sgn;
    }

    REP (i, N) {
	if (low <= A[i] && A[i] <= high) {
	    ans[i] = A[i] * sgn;
	} else {
	    ans[i] = V[BASE+A[i]];
	}
    }
    rprintf("%d", ans, ans+N);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}