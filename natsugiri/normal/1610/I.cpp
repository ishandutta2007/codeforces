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
int X[300011];
int Y[300011];
bool ground[300011];
int par[300011];

VI G[300011];
int dp[300011];

void MAIN() {
    scanf("%d", &N);
    REP (i, N-1) {
	int x, y;
	scanf("%d%d", &x, &y);
	x--;
	y--;
	G[x].push_back(i);
	G[y].push_back(i);
	X[i] = x;
	Y[i] = y;
    }

    VI que;
    ground[0] = true;
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

    REP (i, N) {
	int v = que[N-1-i];
	EACH (e, G[v]) {
	    int w = v ^ X[*e] ^ Y[*e];
	    if (w == par[v]) continue;
	    dp[v] ^= dp[w] + 1;
	}
    }

    int game = dp[0];
    string ans;
    ans.push_back(game? '1': '2');
    ground[0] = true;
    int gg = 0;

    for (int i=1; i<N; i++) {
	VI vs;
	int x = i;
	while (!ground[x]) {
	    vs.push_back(x);
	    ground[x] = true;
	    gg++;
	    x = par[x];
	}


	game ^= dp[x];
	int y = x;
	for (int j=vs.size(); j--;) {
	    dp[y] ^= dp[vs[j]] + 1;
	    game ^= dp[y];
	    y = vs[j];
	}
	game ^= dp[i];

	int tmp = game;
	if (gg % 2 == 1) tmp ^= 1;

	ans.push_back(tmp? '1': '2');
    }

    puts(ans.c_str());
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}