#pragma GCC optimize ("O3")
// #pragma GCC target ("avx")
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
template<class Iter> void rprintf(const char *fmt, Iter begin, Iter end) {
    for (bool sp=0; begin!=end; ++begin) { if (sp) putchar(' '); else sp = true; printf(fmt, *begin); }
    putchar('\n');
}

const int MAXN = 200011;
int N;
int A[MAXN];
int B[MAXN];
VI G[MAXN];

LL dp[MAXN];

VI root;
VI ord;
void dfs(int v) {
    EACH (e, G[v]) {
	if (dp[*e] <= 0) root.push_back(*e);
	else dfs(*e);
    }
    ord.push_back(v+1);
}

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);
    REP (i, N) scanf("%d", B+i);

    VI que;
    REP (i, N) {
	if (B[i] != -1) {
	    B[i]--;
	    G[B[i]].push_back(i);
	} else {
	root.push_back(i);
	    que.push_back(i);
	}
    }

    REP (i, N) {
	int v = que[i];
	EACH (e, G[v]) {
	    que.push_back(*e);
	}
    }

    REP (i_, N) {
	int v = que[N-1-i_];
	dp[v] = A[v];
	EACH (e, G[v]) {
	    if (dp[*e] > 0) dp[v] += dp[*e];
	}
    }

    LL ans = 0;
    REP (i, N) ans += dp[i];
    printf("%lld\n", ans);

    for (int i=0; i<(int)root.size(); i++) dfs(root[i]);

    rprintf("%d", ord.begin(), ord.end());
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}