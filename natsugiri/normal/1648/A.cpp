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

int N, M;
int A[100011];

LL sum[100011];
LL cnt[100011];

void MAIN() {
    scanf("%d%d", &N, &M);
    REP (i, N) REP (j, M) scanf("%d", A+i*M+j);

    LL ans = 0;

    REP (i, N) {
	REP (j, M) {
	    int a = A[i*M+j];
	    ans += i*cnt[a] - sum[a];
	}
	REP (j, M) {
	    int a = A[i*M+j];
	    cnt[a]++;
	    sum[a] += i;
	}
    }

    memset(sum, 0, sizeof sum);
    memset(cnt, 0, sizeof cnt);

    REP (j, M) {
	REP (i, N) {
	    int a = A[i*M+j];
	    ans += j*cnt[a] - sum[a];
	}
	REP (i, N) {
	    int a = A[i*M+j];
	    cnt[a]++;
	    sum[a] += j;
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