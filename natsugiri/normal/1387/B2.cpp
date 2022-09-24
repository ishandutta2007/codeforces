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

int N;
VI G[100011];
int stk[100011];
int iter[100011];
int par[100011];
int sz[100011];
int dp[100011];

VI que;
void dfs(int root) {
    que.clear();
    que.push_back(root);
    stk[0] = stk[1] = root;
    int last = 1;

    while (last) {
	int p = stk[last-1];
	int v = stk[last];
	if (iter[v] == (int)G[v].size()) {
	    last--;
	} else {
	    int w = G[v][iter[v]++];
	    if (w == p) continue;
	    que.push_back(w);
	    stk[++last] = w;
	}
    }
}

void MAIN() {
    scanf("%d", &N);
    REP (i, N-1) {
	int x, y;
	scanf("%d%d", &x, &y);
	x--;
	y--;
	G[x].push_back(y);
	G[y].push_back(x);
    }
    que.reserve(N);
    que.push_back(0);
    REP (i, N) {
	int v = que[i];
	EACH (e, G[v]) if (*e != par[v]) {
	    par[*e] = v;
	    que.push_back(*e);
	}
    }

    LL ans = 0;
    REP (i, N) {
	int v = que[N-1-i];
	sz[v] = 1;
	EACH (e, G[v]) if (*e != par[v]) {
	    sz[v] += sz[*e];
	    amax(dp[v], sz[*e]);
	}

	ans += min(sz[v], N-sz[v]);
    }

    REP (i, N) if (dp[i]*2 <= N && (N-sz[i])*2 <= N) {
	dfs(i);
	int shift = max(dp[i], N-sz[i]);
	REP (k, N) {
	    iter[que[k]] = que[(k+shift) % N] + 1;
	}
	printf("%lld\n", ans*2);
	rprintf("%d", iter, iter+N);
	return;
    }
    assert(false);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}