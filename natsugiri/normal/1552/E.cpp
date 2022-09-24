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

int N, K;
int C[10011];
VI G[111];

pair<int, int> ans[111];
bool use[111];
int H[111];

void MAIN() {
#ifdef LOCAL
    N = 10;
    K = 10;
    REP (i, N*K) C[i] = i/K;
    random_shuffle(C, C+N*K);
    rprintf("%d", C, C+N*K);
    REP (i, N*K) G[C[i]].push_back(i);
#else
    scanf("%d%d", &N, &K);
    REP (i, N*K) {
	scanf("%d", C+i);
	C[i]--;
	G[C[i]].push_back(i);
    }
#endif

    VI V;
    for (int s=0; s<N; s+=K-1) {
	// [s, s+K-1);
	int lo = s, hi = s+K-1;
	V.clear();
	for (int i=lo; i<hi; i++) V.insert(V.end(), G[i].begin(), G[i].end());
	sort(V.begin(), V.end());

	for (int i=lo; i<hi; i++) H[i] = -1;

	REP (k, V.size()) {
	    int c = C[V[k]];
	    if (use[c]) continue;

	    if (H[c] != -1) {
		ans[c] = make_pair(H[c], V[k]);
		use[c] = true;
		for (int i=lo; i<hi; i++) H[i] = -1;
	    } else {
		H[c] = V[k];
	    }
	}
    }

    REP (i, N) {
	assert(C[ans[i].first] == i);
	printf("%d %d\n", ans[i].first+1, ans[i].second+1);
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}