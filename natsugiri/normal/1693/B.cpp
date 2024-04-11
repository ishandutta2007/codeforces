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
int P[200011];
LL L[200011];
LL R[200011];

LL Z[200011];
LL D[200011];

VI G[200011];

void MAIN() {
    scanf("%d", &N);
    for (int i=1; i<N; i++) scanf("%d", P+i), P[i]--;
    REP (i, N) scanf("%lld%lld", L+i, R+i);

    REP (i, N) G[i].clear();
    for (int i=1; i<N; i++) G[P[i]].push_back(i);

    for (int v=N; v--;) {
	if (G[v].size() == 0u) {
	    Z[v] = R[v];
	    D[v] = 1;
	} else {
	    Z[v] = 0;
	    D[v] = 0;
	    EACH (e, G[v]) {
		Z[v] += Z[*e];
		D[v] += D[*e];
	    }
	    amin(Z[v], R[v]);
	    if (Z[v] < L[v]) {
		Z[v] = R[v];
		D[v]++;
	    }
	}
    }

    printf("%lld\n", D[0]);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}