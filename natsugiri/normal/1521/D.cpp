#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
#include<tuple>

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
VI G[100011];
bool cut[100011];

int par[100011];
int deg[100011];
VI que;

int X[100011];
int Y[100011];
int dp[100011][2];

using Tuple = tuple<int, int, int, int>;
vector<Tuple> ans;
VI down;

void MAIN() {
    scanf("%d", &N);
    REP (i, N) {
	G[i].clear();
	cut[i] = false;
	deg[i] = 0;
    }
    ans.clear();

    REP (i, N-1) {
	int x, y;
	scanf("%d%d", &x, &y);
	x--; y--;
	X[i] = x;
	Y[i] = y;
	G[x].push_back(i);
	G[y].push_back(i);
	deg[x]++;
	deg[y]++;
    }

    que.clear();
    que.push_back(0);
    REP (i, N) {
	int v = que[i];
	EACH (e, G[v]) {
	    int w = v ^ X[*e] ^ Y[*e];
	    if (w == par[v]) continue;
	    par[w] = v;
	    que.push_back(w);
	}
    }

    int prv = -1;

    REP (i, N) {
	int v = que[N-1-i];
	EACH (e, G[v]) {
	    int w = v ^ X[*e] ^ Y[*e];
	    if (w == par[v]) continue;

	    if (deg[w] > 2) {
		assert(deg[w] == 3);
		deg[w]--;
		deg[v]--;

		ans.emplace_back(v, w, prv, dp[w][0]);
		prv = dp[w][1];

		cut[*e] = true;
	    }
	}

	down.clear();
	EACH (e, G[v]) {
	    if (cut[*e]) continue;

	    int w = v ^ X[*e] ^ Y[*e];
	    if (w == par[v]) continue;

	    if (deg[v] > 3 || (v == 0 && deg[v] > 2)) {
		assert(deg[w] == 3);
		deg[w]--;
		deg[v]--;

		ans.emplace_back(v, w, prv, dp[w][0]);
		prv = dp[w][1];

		cut[*e] = true;
	    }

	    if (!cut[*e]) {
		down.push_back(w);
	    }
	}

	if (down.empty()) {
	    dp[v][0] = dp[v][1] = v;
	} else if (down.size() == 1u) {
	    dp[v][0] = dp[down[0]][0];
	    dp[v][1] = v;
	} else {
	    assert(down.size() == 2u);
	    dp[v][0] = dp[down[0]][0];
	    dp[v][1] = dp[down[1]][0];
	}
    }

    printf("%d\n", (int)ans.size());
    EACH (e, ans) {
	int x, y, a, b;
	tie(x, y, a, b) = *e;
	if (a == -1) a = dp[0][0];

	printf("%d %d %d %d\n", x+1, y+1, a+1, b+1);
    }
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}