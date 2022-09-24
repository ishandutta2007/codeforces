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

int N, P;
int A[100011];

bool ok(int mid) {
    int idx = 0;
    int cur = mid;
    int cnt = 0;
    REP (i, N) {
	while (idx < N && A[idx] <= cur) {
	    cnt++;
	    idx++;
	}
	if (cnt >= P) {
	    return false;
	}
	cnt--;
	cur++;
    }

    return true;
}

void MAIN() {
    scanf("%d%d", &N, &P);
    REP (i, N) scanf("%d", A+i);
    sort(A, A+N);

    int mi = 0;
    REP (i, N) amax(mi, A[i] - i);
    int ma = A[N-1];

    int lo = mi - 1, hi = ma;
    while (hi - lo > 1) {
	int mid = (lo + hi) / 2;
	(ok(mid)? lo: hi) = mid;
    }

    VI ans;
    for (int x=mi; x<hi; x++) ans.push_back(x);

    printf("%d\n", (int)ans.size());
    rprintf("%d", ans.begin(), ans.end());
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}