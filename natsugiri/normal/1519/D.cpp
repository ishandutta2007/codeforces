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
#define rprintf(fmt, begin, end) do { const auto end_rp = (end); auto it_rp = (begin); for (bool sp_rp=0; it_rp!=end_rp; ++it_rp) { if (sp_rp) putchar(' '); else sp_rp = true; printf(fmt, *it_rp); } putchar('\n'); } while(0)

int N;
LL A[10011];
LL B[10011];
LL sums[10011];

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%lld", A+i*2);
    REP (i, N) scanf("%lld", B+i*2);

    REP (i, N*2) sums[i+1] = sums[i] + A[i] * B[i];

    LL ans = sums[N];

    REP (c, N*2-1) {
	int l = c;
	int r = c + 1;
	LL tmp = A[c] * B[c];

	while (1) {
	    amax(ans, sums[l] + (sums[N*2-1] - sums[r]) + tmp);

	    if (l == 0) break;
	    if (r == N*2-1) break;
	    tmp += A[l-1] * B[r] + B[l-1] * A[r];
	    l--; r++;
	}
    }

    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}