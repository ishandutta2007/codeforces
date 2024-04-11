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

int K;
LL calc(vector<LL> &A) {
    sort(A.begin(), A.end());
    reverse(A.begin(), A.end());
    LL ret = 0;

    for (int i=0; i<(int)A.size(); i+=K) {
	if (i == 0) ret += A[i];
	else ret += A[i] * 2;
    }
    return ret;
}

void MAIN() {
    int N;
    scanf("%d%d", &N, &K);

    vector<LL> A, B;
    REP (i, N) {
	int x;
	scanf("%d", &x);
	if (x > 0) A.push_back(x);
	if (x < 0) B.push_back(-x);
    }
    A.push_back(0);
    B.push_back(0);

    LL a = calc(A);
    LL b = calc(B);
    LL ans = a + b + min(A[0], B[0]);

    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}