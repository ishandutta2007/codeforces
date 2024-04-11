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

int N, K;

const int SIZE = 1<<12;
vector<pair<int, LL> > seg[SIZE*2];

void add(int x, int y, int len, LL sum) {
    x += SIZE;
    y += SIZE;
    for (; x<y; x>>=1, y>>=1) {
	if (x&1) seg[x++].emplace_back(len, sum);
	if (y&1) seg[--y].emplace_back(len, sum);
    }
}

VI A[3011];

LL ans;
int depth;
LL dp[14][SIZE];
void rec(int k, int l, int r) {
    if (N <= l) return;

    memcpy(dp[depth+1], dp[depth], sizeof dp[depth]);
    depth++;

    EACH (e, seg[k]) {
	for (int i=K - e->first; i>=0; i--) {
	    amax(dp[depth][i + e->first], dp[depth][i] + e->second);
	}
    }

    if (l + 1 == r) {
	amax(ans, dp[depth][K]);
	LL sum = 0;
	REP (i, min(K, (int)A[l].size())) {
	    sum += A[l][i];
	    amax(ans, dp[depth][K-i-1] + sum);
	}
    } else {
	rec(k*2, l, (l+r)/2);
	rec(k*2+1, (l+r)/2, r);
    }

    depth--;
}

void MAIN() {
    scanf("%d%d", &N, &K);
    REP (i, N) {
	int len;
	scanf("%d", &len);
	A[i].resize(len);
	REP (j, len) scanf("%d", &A[i][j]);

	LL sum = 0;
	REP (j, len) sum += A[i][j];

	add(0, i, len, sum);
	add(i+1, SIZE, len, sum);
    }


    rec(1, 0, SIZE);

    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}