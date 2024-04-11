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
pair<LL, int> A[200011];

int solve(LL c) {
    int prv = A[0].first;
    int cnt = 0;
    int idx = 0;
    for (int i=1; i<N; i++) {
	if (A[i].first == prv + c) {
	    prv = A[i].first;
	} else {
	    idx = i;
	    cnt++;
	}
    }

    if (cnt <= 1) return A[idx].second;

    prv = A[1].first;
    cnt = 1;
    for (int i=2; i<N; i++) {
	if (A[i].first == prv + c) {
	    prv = A[i].first;
	} else {
	    cnt++;
	}
    }

    if (cnt <= 1) return A[0].second;
    return -1;
}

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%lld", &A[i].first), A[i].second = i;
    sort(A, A+N);

    int guess = solve(A[1].first - A[0].first);
    if (guess == -1 && N > 2) guess = solve(A[2].first - A[1].first);
    if (guess == -1 && N > 2) guess = solve(A[2].first - A[0].first);
    
    if (guess == -1) puts("-1");
    else printf("%d\n", guess+1);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}