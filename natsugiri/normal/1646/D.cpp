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
VI G[200011];
int par[200011];
int W[200011];


pair<int, LL> add(const pair<int, LL> &x, const pair<int, LL> &y) {
    return make_pair(x.first + y.first, x.second + y.second);
}

bool LEFT(const pair<int, LL> &x, const pair<int, LL> &y) {
    return (x.first > y.first || (x.first == y.first && x.second <= y.second));
}

pair<int, LL> choose(const pair<int, LL> &x, const pair<int, LL> &y) {
    if (LEFT(x, y)) return x;
    return y;
}

pair<int, LL> dp[200011][2];
int val[200011];

void MAIN() {
    scanf("%d", &N);
    REP (i, N-1) {
	int x, y;
	scanf("%d%d", &x, &y);
	x--; y--;
	G[x].push_back(y);
	G[y].push_back(x);
    }

    if (N == 2) {
	puts("2 2");
	puts("1 1");
	return;
    }

    VI que;
    que.push_back(0);
    REP (i, N) {
	int v = que[i];
	EACH (e, G[v]) if (*e != par[v]) {
	    par[*e] = v;
	    que.push_back(*e);
	}
    }
    REP (i, N) {
	int v = que[N-1-i];

	dp[v][0] = make_pair(0, 1);
	dp[v][1] = make_pair(1, G[v].size());

	EACH (e, G[v]) if (*e != par[v]) {
	    pair<int, LL> a = choose(add(dp[v][0], dp[*e][0]), add(dp[v][0], dp[*e][1]));
	    pair<int, LL> b = add(dp[v][1], dp[*e][0]);

	    dp[v][0] = a;
	    dp[v][1] = b;
	}
    }

    pair<int, LL> ans;
    if (LEFT(dp[0][0], dp[0][1])) {
	val[0] = 0;
	W[0] = 1;
	ans = dp[0][0];
    } else {
	val[0] = 1;
	W[0] = G[0].size();
	ans = dp[0][1];
    }
    REP (i, N) {
	int v = que[i];

	EACH (e, G[v]) if (*e != par[v]) {
	    if (val[v] == 1 || LEFT(dp[*e][0], dp[*e][1])) {
		val[*e] = 0;
		W[*e] = 1;
	    } else {
		val[*e] = 1;
		W[*e] = G[*e].size();
	    }
	}
    }
    printf("%d %lld\n", ans.first, ans.second);
    rprintf("%d", W, W+N);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}