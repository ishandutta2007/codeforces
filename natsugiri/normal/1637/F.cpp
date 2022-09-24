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
int H[200011];
VI G[200011];
LL dp[200011];
int MA[200011];

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", H+i);
    REP (i, N-1) {
	int x, y;
	scanf("%d%d", &x, &y);
	x--; y--;
	G[x].push_back(y);
	G[y].push_back(x);
    }

    const LL MAXH = *max_element(H, H+N);
    int root = 0;
    REP (i, N) if (H[i] == MAXH) {
	root = i;
	break;
    }

    VI que;
    que.push_back(root);
    REP (i, N) {
	int v = que[i];
	EACH (e, G[v]) {
	    // par[*e] = v;
	    G[*e].erase(find(G[*e].begin(), G[*e].end(), v));
	    que.push_back(*e);
	}
    }

    REP (i, N-1) {
	int v = que[N-1-i];
	if (G[v].empty()) {
	    dp[v] = H[v];
	    MA[v] = H[v];
	} else {
	    EACH (e, G[v]) {
		dp[v] += dp[*e];
		amax(MA[v], MA[*e]);
	    }

	    if (H[v] > MA[v]) {
		dp[v] += H[v] - MA[v];
		MA[v] = H[v];
	    }
	}
    }

    LL ans = 0;
    if (G[root].size() == 1u) {
	int c = G[root][0];
	ans = MAXH + MAXH - MA[c] + dp[c];
    } else {
	int aux[3] = {0, 0, 0};
	EACH (e, G[root]) {
	    ans += dp[*e];
	    aux[0] = MA[*e];
	    sort(aux, aux+3);
	}
	ans += MAXH + MAXH - aux[1] - aux[2];
    }
    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}