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
VI G[MAXN];
int par[MAXN];
int B[MAXN];
int W[MAXN];


void MAIN() {
    scanf("%d", &N);
    REP (i, N-1) {
	int x, y;
	scanf("%d%d", &x, &y);
	x--; y--;
	G[x].push_back(y);
	G[y].push_back(x);
    }
    VI que;
    que.push_back(0);
    REP (i_, N) {
	int v = que[i_];
	EACH (e, G[v]) if (*e != par[v]) {
	    par[*e] = v;
	    que.push_back(*e);
	}
    }

    int ans = 0;

    REP (i_, N) {
	int v = que[N-1-i_];
	int ch = G[v].size();
	if (v) ch--;

	int a0 = 0, a1 = 0;
	// W
	EACH (e, G[v]) if (*e != par[v]) {
	    int tmp = max(B[*e], W[*e]);
	    if (a1 < tmp) a1 = tmp;
	    if (a0 < a1) swap(a0, a1);
	}
	int add = 0;
	if (ch >= 2) add += ch - 2;
	if (v) add++;
	amax(ans, a0 + a1 + add);

	a0 = 0; a1 = 0;
	// B
	EACH (e, G[v]) if (*e != par[v]) {
	    int tmp = W[*e];
	    if (a1 < tmp) a1 = tmp;
	    if (a0 < a1) swap(a0, a1);
	}
	amax(ans, a0 + a1 + 1);

	B[v] = 1;
	W[v] = 0;
	EACH (e, G[v]) if (*e != par[v]) {
	    amax(B[v], W[*e] + 1);
	    amax(W[v], max(B[*e], W[*e]));
	}

	if (ch >= 1) W[v] += ch - 1;
	amax(ans, B[v]);
	amax(ans, W[v]);
	if (v) amax(ans, W[v]+1);
	//eprintf("%d %d %d\n", v+1, B[v], W[v]);
    }

    printf("%d\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}