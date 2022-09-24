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

int N, M;
int A[100011];
int B[100011];
int C[100011];
VI X[100011];
int ans[100011];

void MAIN() {
    scanf("%d%d", &N, &M);
    REP (i, N) scanf("%d", A+i);
    REP (i, N) scanf("%d", B+i);
    REP (i, M) scanf("%d", C+i);

    REP (i, N+1) X[i].clear();

    int over = -1;
    REP (i, N) {
	if (A[i] == B[i]) {
	    if (A[i] == C[M-1]) over = i+1;
	} else {
	    X[B[i]].push_back(i);
	}
    }
    
    bool yes = true;

    for (int i=M; i--;) {
	if (X[C[i]].size()) {
	    int pos = X[C[i]].back() + 1;
	    X[C[i]].pop_back();
	    ans[i] = pos;
	    over = pos;
	} else if (over != -1) {
	    ans[i] = over;
	} else {
	    yes = false;
	}
    }

    REP (i, N+1) {
	if (X[i].size()) yes = false;
	X[i].clear();
    }

    if (yes) {
	puts("YES");
	rprintf("%d", ans, ans + M);
    } else {
	puts("NO");
    }

}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}