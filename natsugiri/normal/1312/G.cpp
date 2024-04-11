#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
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

int N;

char C[1000011];
VI G[1000011];
int dp[1000011];
bool in[1000011];
int A[1000011];

int dfs(int v, int cst) {
    int val = 0;
    if (in[v]) {
	amin(dp[v], cst + 1);
	val++;
    }

    amin(cst, dp[v]);

    EACH (e, G[v]) {
	amin(dp[*e], dp[v]+1);
	int tmp = dfs(*e, cst + val);
	val += tmp;
    }
    return val;
}

void MAIN() {
    scanf("%d", &N);
    REP (i, N) {
	int p;
	char c;
	scanf("%d %c", &p, &c);
	G[p].push_back(i+1);
	C[i+1] = c;
    }

    REP (v, N+1) sort(G[v].begin(), G[v].end(), [&](int i, int j) {
	    return C[i] < C[j];
	    });

    int K;
    scanf("%d", &K);
    REP (i, K) {
	scanf("%d", A+i);
	in[A[i]] = true;
    }

    memset(dp, 0x3f, sizeof dp);
    dp[0] = 0;
    int tmp = dfs(0, 0);
    assert(tmp == K);
    REP (i, K) printf("%d%c", dp[A[i]], " \n"[i==K-1]);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}