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
int A[200011];
int B[200011];
VI R, X;
VI G[200011];

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i), A[i]--;
    
    REP (v, N) G[v].clear();
    REP (i, N) G[A[i]].push_back(i);

    R.clear();
    REP (v, N) if (G[v].empty()) R.push_back(v);

    int ans = 0;
    REP (v, N) if (G[v].size()) {
	ans++;
	X.clear();
	X.push_back(v);
	REP (t, G[v].size() - 1u) {
	    X.push_back(R.back());
	    R.pop_back();
	}

	for (int i=0; i<(int)X.size()-1; i++) {
	    if (X[i] == G[v][i] || X[i+1] == G[v][i+1]) {
		swap(X[i], X[i+1]);
	    }
	}
	REP (i, X.size()) B[G[v][i]] = X[i];
    }

    REP (i, N) B[i]++;

    printf("%d\n", ans);
    rprintf("%d", B, B+N);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}