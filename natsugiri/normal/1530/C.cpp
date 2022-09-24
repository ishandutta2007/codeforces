#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#pragma GCC optimize("unroll-loops")
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
#define rprintf(fmt, begin, end) do { const auto end_rp = (end); auto it_rp = (begin); for (bool sp_rp=0; it_rp!=end_rp; ++it_rp) { if (sp_rp) putchar(' '); else sp_rp = true; printf(fmt, *it_rp); } putchar('\n'); } while(0)

int N;
LL eval(int A[]) {
    LL ret = 0;
    int m = N - N/4;
    for (int i=100; i>=0 && m; i--) {
	int g = min(A[i], m);
	ret += i * g;
	m -= g;
    }
    return ret;
}

int A[101];
int B[101];

void MAIN() {
    scanf("%d", &N);
    memset(A, 0, sizeof A);
    memset(B, 0, sizeof B);

    REP (i, N) {
	int x;
	scanf("%d", &x);
	A[x]++;
    }
    REP (i, N) {
	int x;
	scanf("%d", &x);
	B[x]++;
    }

    int ans = 0;
    while (eval(A) < eval(B)) {
	A[100]++;
	B[0]++;
	ans++;
	N++;
    }

    printf("%d\n", ans);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}