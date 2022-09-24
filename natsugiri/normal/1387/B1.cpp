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

VI que;
int par[100011];

const LL INF = 0x3f3f3f3f3f3f3f3fLL;

int last[100011];

struct State {
    LL cst;
    pair<int, int> left, right, op;

    State() {
	cst = INF;
	left = right = op = make_pair(-1, -1);
    }
};
State st[200011][2];

int name[100011];

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
	    G[*e].erase(remove(G[*e].begin(), G[*e].end(), v), G[*e].end());
	}
    }

    int cnt = 0;
    REP (i_, N) {
	int v = que[N-1-i_];
	int cur = cnt++; // (v, 0);
	st[cur][0].cst = 0;

	EACH (e, G[v]) {
	    int nxt = cnt++;
	    int pos = last[*e];

	    REP (a, 2) REP (b, 2) {
		if (st[nxt][1].cst > st[cur][a].cst + st[pos][b].cst + 2) {
		    st[nxt][1].cst = st[cur][a].cst + st[pos][b].cst + 2;
		    st[nxt][1].left = make_pair(cur, a);
		    st[nxt][1].right = make_pair(pos, b);
		    st[nxt][1].op = make_pair(v, *e);
		}
		// amin(tmp1, dp[v][a] + dp[*e][b] + 2);
	    }

	    REP (a, 2) {
		if (st[nxt][a].cst > st[cur][a].cst + st[pos][1].cst) {
		    st[nxt][a].cst = st[cur][a].cst + st[pos][1].cst;
		    st[nxt][a].left = make_pair(cur, a);
		    st[nxt][a].right = make_pair(pos, 1);
		    st[nxt][a].op = make_pair(-1, -1);
		}
		// amin(tmpa, dp[v][a] + dp[*e][1]);
	    }

	    cur = nxt;
	}

	last[v] = cur;
    }

    vector<pair<int, int> > stk;
    stk.emplace_back(cnt-1, 1);
    REP (i, N) name[i] = i;
    while (!stk.empty()) {
	int pos = stk.back().first;
	int a = stk.back().second;
	stk.pop_back();
	if (st[pos][a].op.first != -1) {
	    int x = st[pos][a].op.first;
	    int y = st[pos][a].op.second;
	    swap(name[x], name[y]);
	}
	if (st[pos][a].left.first != -1) stk.push_back(st[pos][a].left);
	if (st[pos][a].right.first != -1) stk.push_back(st[pos][a].right);
    }

    printf("%lld\n", st[cnt-1][1].cst);
    REP (i, N) name[i]++;
    rprintf("%d", name, name+N);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}