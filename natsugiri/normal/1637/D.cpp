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
int A[111];
int B[111];

LL buf[2][10001];
LL *cur = buf[0];
LL *nxt = buf[1];

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);
    REP (i, N) scanf("%d", B+i);

    if (N == 1) {
	puts("0");
	return;
    }

    memset(cur, 0x3f, sizeof buf[0]);
    const LL INF = cur[0];
    cur[0] = 0;
    LL left = 0;

    REP (i, N) {
	memset(nxt, 0x3f, sizeof buf[0]);
	REP (s, 10001) if (cur[s] < INF) {
	    if (s + A[i] <= 10000) {
		LL tmp = cur[s] + s * A[i] + (left-s) * B[i];
		amin(nxt[s + A[i]], tmp);
	    }
	    if (s + B[i] <= 10000) {
		LL tmp = cur[s] + s * B[i] + (left-s) * A[i];
		amin(nxt[s + B[i]], tmp);
	    }
	}
	swap(cur, nxt);
	left += A[i];
	left += B[i];
    }

    LL ans = 0;
    REP (i, N) {
	ans += A[i]*A[i];
	ans += B[i]*B[i];
    }
    ans *= N-1;

    ans += 2 * *min_element(cur, cur+10001);
    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}