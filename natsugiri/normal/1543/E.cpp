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
VI G[1<<16];

int depth[1<<16];
int rnk[1<<16];
VI que;

int ans[1<<16];
int C[1<<16];

void MAIN() {
    scanf("%d", &N);
    int NN = 1<<N;
    REP (i, NN) G[i].clear();
    REP (i, N * (1<<(N-1))) {
	int x, y;
	scanf("%d%d", &x, &y);
	G[x].push_back(y);
	G[y].push_back(x);
    }


    que.clear();
    que.push_back(0);
    memset(rnk, 0, sizeof (int) * NN);
    memset(depth, 0x3f, sizeof (int) * NN);
    depth[0] = 0;

    REP (i, NN) {
	// rprintf("%d", que.begin(), que.end());
	int cnt = 1;
	int v = que[i];
	EACH (e, G[v]) if (depth[v] < depth[*e]) {
	    if (depth[v] + 1 < depth[*e]) {
		depth[*e] = depth[v] + 1;
		que.push_back(*e);
	    }

	    if (v == 0) {
		rnk[*e] = cnt;
		cnt *= 2;
	    } else {
		rnk[*e] |= rnk[v];
	    }

	}
    }

    REP (i, NN) {
	ans[rnk[i]] = i;
    }
    rprintf("%d", ans, ans+NN);

    if (__builtin_popcount(N) == 1u) {
	REP (i, NN) {
	    int x = 0;
	    REP (t, N) {
		if (i>>t&1) {
		    x ^= t;
		}
	    }
	    C[ans[i]] = x;
	}
	rprintf("%d", C, C+NN);
    } else {
	puts("-1");
    }
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}