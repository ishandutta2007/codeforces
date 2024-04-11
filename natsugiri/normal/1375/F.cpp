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

LL A[3], B[3];

bool query_update(LL y) {
    printf("%lld\n", y);
    fflush(stdout);

    int t;
    scanf("%d", &t);
    if (t == 0) {
	return true;
    } else {
	A[t-1] += y;
	return false;
    }
}

void MAIN() {
    REP (i, 3) scanf("%lld", A+i);
    puts("First");
    fflush(stdout);

    bool b = query_update(*max_element(A, A+3));
    if (b) return;

    REP (i, 3) B[i] = A[i];
    sort(B, B+3);
    LL a = B[1] - B[0], s = B[2] - B[1];

    b = query_update(a + 2 * s);

    REP (i, 3) B[i] = A[i];
    sort(B, B+3);

    assert(B[2] - B[1] == B[1] - B[0]);
    b = query_update(B[1] - B[0]);

    assert(b);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}