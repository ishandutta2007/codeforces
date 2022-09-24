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
LL M;
LL P[100011];
LL H[100011];

LL good[100011];
LL bad[100011];

VI G[100011];
int par[100011];
VI que;

void MAIN() {
    scanf("%d%lld", &N, &M);
    REP (i, N) G[i].clear();
    REP (i, N) scanf("%lld", P+i);
    REP (i, N) scanf("%lld", H+i);
    REP (i, N-1) {
	int x, y;
	scanf("%d%d", &x, &y);
	x--; y--;
	G[x].push_back(y);
	G[y].push_back(x);
    }


    que.clear();
    que.push_back(0);
    REP (i, N) {
	int v = que[i];
	EACH (e, G[v]) if (*e != par[v]) {
	    que.push_back(*e);
	    par[*e] = v;
	}
    }

    bool yes = true;

    REP (i_, N) {
	int v = que[N-1-i_];
	good[v] = 0;
	bad[v] = P[v];

	EACH (e, G[v]) if (*e != par[v]) {
	    good[v] += good[*e];
	    bad[v] += bad[*e];
	}

	// H[v] == (good[v] + x) - (bad[v] - x);
	// 2x = H[v] - good[v] + bad[v];
	LL x2 = H[v] - good[v] + bad[v];

	if (x2 < 0 || x2 % 2 != 0) {
	    yes = false;
	    break;
	}
	LL x = x2 / 2;
	if (x > bad[v]) {
	    yes = false;
	    break;
	}

	good[v] += x;
	bad[v] -= x;
    }

    puts(yes? "YES": "NO");
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}