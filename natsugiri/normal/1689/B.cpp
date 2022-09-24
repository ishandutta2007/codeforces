#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#pragma GCC optimize("unroll-loops")
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
#include<set>

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
#define rprintf(fmt, begin, end) do { const auto end_rp = (end); auto it_rp = (begin); for (bool sp_rp=0; it_rp!=end_rp; ++it_rp) { if (sp_rp) putchar(' '); else sp_rp = true; printf(fmt, *it_rp); } putchar('\n'); } while(0)

int N;
int A[1011];
int B[1011];

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);

    if (N == 1) {
	puts("-1");
	return;
    }

    set<int> se(A, A+N);
    REP (i, N-2) {
	if (A[i] != *se.begin()) {
	    B[i] = *se.begin();
	    se.erase(se.begin());
	} else {
	    auto it = next(se.begin());
	    B[i] = *it;
	    se.erase(it);
	}
    }

    int a = *se.begin();
    int b = *next(se.begin());
    if (A[N-2] != a && A[N-1] != b) {
	B[N-2] = a;
	B[N-1] = b;
    } else {
	B[N-2] = b;
	B[N-1] = a;
    }

    rprintf("%d", B, B+N);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}