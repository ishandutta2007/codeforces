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

int rec(int l, int r, int s) {
    if (l == r) return 0;

    if (s == 0) {
	if ((A[l]&1) == (A[r-1]&1)) return 0;
	return 1;
    }

    int k;
    for (k=l; k<r; k++) {
	if (A[k]>>s&1) break;
    }

    if (l == k || k == r) {
	return rec(l, r, s-1);
    }

    int p = rec(l, k, s-1);
    int q = rec(k, r, s-1);
    return min(max(p, q|(1<<s)), max(p|(1<<s), q));
}

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);

    sort(A, A+N);
    int ans = rec(0, N, 30);
    printf("%d\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}