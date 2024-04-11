#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
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
int A[400011];
int B[400011];

void MAIN() {
    scanf("%d", &N);

    REP (i, N) scanf("%d", A+i);

#ifdef MYTEST
    N = 2;
    REP (i, N) {
	A[i] = 10000000-i;
    }
#endif

    int ans = 0;
    REP (t, 26) {
	const int MASK = (1<<(t+1))-1;
	REP (i, N) B[i] = A[i] & MASK;
	sort(B, B+N);
	LL cnt = 0;

	for (int i=1; i<N; i++) {
	    int key0 = MASK - B[i];
	    key0 &= (1<<t)-1;
	    int key1 = key0 | (1<<t);

	    int pos0 = upper_bound(B, B+i, key0) - B;
	    int pos1 = upper_bound(B, B+i, key1) - B;

	    if (B[i]>>t&1) {
		cnt += i-pos1;
		cnt += pos0;
	    } else {
		cnt += pos1-pos0;
	    }
	}

	if (cnt & 1) ans |= 1<<t;
    }
    printf("%d\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}