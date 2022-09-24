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

int N, Q;
int A[300011];
VI ans;

void MAIN() {
    scanf("%d%d", &N, &Q);
    REP (i, N) scanf("%d", A+i);

    bool top = true;
    ans.clear();
    REP (i, N) {
	if (top) {
	    if ((i == 0 || A[i-1] < A[i]) && (i == N-1 || A[i] > A[i+1])) {
		ans.push_back(A[i]);
		top = false;
	    }
	} else {
	    if (i != 0 && i != N-1 && A[i-1] > A[i] && A[i] < A[i+1]) {
		ans.push_back(A[i]);
		top = true;
	    }
	}
    }

    LL val = 0;
    REP (i, ans.size()) {
	if (i % 2 == 0) val += ans[i];
	else val -= ans[i];
    }

    printf("%lld\n", val);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}