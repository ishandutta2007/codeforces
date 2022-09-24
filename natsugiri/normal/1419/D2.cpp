#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
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
int A[100011];
int B[100011];

bool ok(int mid) {
    if (mid * 2 + 1 > N) return false;
    if (mid == 0) {
	REP (i, N) B[i] = A[i];
	return true;
    }

    int pos;

    pos = 0;
    for (int i=N-mid-1; i<N; i++) {
	B[pos] = A[i];
	pos += 2;
    }
    pos = 1;
    for (int i=0; i<mid; i++) {
	B[pos] = A[i];
	if (B[pos-1] <= B[pos] || B[pos] >= B[pos+1]) return false;
	pos += 2;
    }

    for (int i=mid; i<N-mid-1; i++) {
	B[pos] = A[i];
	pos++;
    }
    assert(pos == N);

    return true;
}

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);
    sort(A, A+N);

    int lo = 0, hi = N;
    while (hi - lo > 1) {
	int mid = (lo + hi) / 2;
	(ok(mid)? lo: hi) = mid;
    }

    ok(lo);
    printf("%d\n", lo);
    rprintf("%d", B, B+N);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}