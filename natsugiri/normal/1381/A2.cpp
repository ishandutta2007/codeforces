#pragma GCC optimize ("O3")
// #pragma GCC target ("avx")
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

int N;
char A[100011], B[100011];

void MAIN() {
    scanf("%d", &N);
    scanf("%s%s", A, B);

    REP (i, N) {
	A[i] -= '0';
	B[i] -= '0';
    }

    int L = 0, R = N-1;
    bool flip = false;

    VI ans;

    for (int i=N-1; i>=0; i--) {
	if (flip) B[i] ^= 1;

	char first, last;
	if (flip) {
	    first = A[R];
	    last = A[L];
	} else {
	    first = A[L];
	    last = A[R];
	}

	if (last != B[i]) {
	    if (flip) R--;
	    else L++;

	    if (first == B[i]) {
		ans.push_back(1);
		B[i] ^= 1;
	    }
	    ans.push_back(i+1);
	    flip = !flip;
	} else {
	    if (flip) L++;
	    else R--;
	}
    }

    printf("%d ", (int)ans.size());
    rprintf("%d", ans.begin(), ans.end());
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}