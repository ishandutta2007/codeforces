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

const int MAXN = 100011;

int N;
int S, T;
VI G[MAXN];

int par[MAXN];
VI que;

void bfs(int root) {
    par[root] = -1;
    que.clear();
    que.push_back(root);
    REP (i, N) {
	int v = que[i];
	EACH (e, G[v]) if (*e != par[v]) {
	    par[*e] = v;
	    que.push_back(*e);
	}
    }
}


bool path[MAXN];
int path_len; // #E

void fill_path() {
    bfs(S);

    path_len = 0;
    memset(path, 0, sizeof (path[0]) * N);

    int v = T;
    while (1) {
	path[v] = true;
	path_len++;
	if (v == S) break;
	v = par[v];
    }

    path_len--;
}


int dp[MAXN][3];
int fall[MAXN];
int core;
bool valid_core[MAXN];

void solve_dp(bool update_core) {
    int buf[4];
    
    REP (i, N) {
	int v = que[N-1-i];
	REP (t, 4) buf[t] = 0;
	EACH (e, G[v]) if (*e != par[v]) {
	    buf[0] = dp[*e][0] + 1;
	    sort(buf, buf+4);
	}

	REP (t, 3) dp[v][t] = buf[3-t];
    }

    memset(fall, 0, sizeof (fall[0]) * N);

    if (!update_core) return;

    core = -1;
    REP (i, N) {
	int v = que[i];
	REP (t, 3) buf[t] = dp[v][t];
	buf[3] = fall[v];
	sort(buf, buf+4);
	if (buf[1] >= path_len) { // buf[1 .. 3];
	    core = v;
	}

	valid_core[v] = (buf[1] >= path_len);

	EACH (e, G[v]) if (*e != par[v]) {
	    if (dp[*e][0] + 1 == buf[3]) fall[*e] = buf[2] + 1;
	    else fall[*e] = buf[3] + 1;
	}
    }
}

bool solve_snake() {
    bfs(core);
    solve_dp(false);

    int enter = -1;
    REP (i, N) {
	int v = que[i];
	if (path[v]) {
	    enter = v;
	    break;
	}
    }

    int X = S, Y = T;
    int XW = 0, YW = 0;
    int XUP = 0, YUP = 0;
    while (1) {
	// eprintf("%d %d %d %d %d %d\n", X+1, Y+1, XW, YW, XUP, YUP);
	if (X == enter || Y == enter) return true;

	amax(XW, dp[X][0] - XUP);
	amax(YW, dp[Y][0] - YUP);

	if (XUP < YW) {
	    XUP++;
	    X = par[X];
	} else if (YUP < XW) {
	    YUP++;
	    Y = par[Y];
	} else {
	    return false;
	}
    }
}

void MAIN() {
    scanf("%d%d%d", &N, &S, &T);
    S--; T--;

    path_len = 0;
    REP (i, N) {
	G[i].clear();
    }

    REP (i, N-1) {
	int x, y;
	scanf("%d%d", &x, &y);
	x--; y--;
	G[x].push_back(y);
	G[y].push_back(x);
    }

    fill_path();
    solve_dp(true);


    bool yes;

    if (core != -1) {
	yes = solve_snake();
    } else {
	yes = false;
    }


    puts(yes? "YES": "NO");
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}