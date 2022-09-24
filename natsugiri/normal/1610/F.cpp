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

int N, M;
int X[300011];
int Y[300011];
int W[300011];
VI G1[300011];
VI G2[300011];

bool useE[300011];
bool flip[300011];

VI H[300011];

VI start, stop;
vector<VI> paths;

int deg[300011];


void build(VI G[]) {
    REP (t, 2) {
	REP (i, N) {
	    int c = 0;
	    EACH (e, G[i]) if (!useE[*e]) c++;
	    if (c == 0) continue;
	    if (t == 0 && c % 2 == 0) continue;

	    VI E;

	    int v = i;
	    while (1) {
		while (!G[v].empty() && useE[G[v].back()]) G[v].pop_back();
		if (G[v].empty()) break;
		int e = G[v].back();
		E.push_back(e);
		useE[e] = true;

		if (v == Y[e]) {
		    flip[e] = !flip[e];
		    v = X[e];
		} else {
		    assert(v == X[e]);
		    v = Y[e];
		}
	    }

	    // i -- v;
	    int cnt = paths.size();
	    paths.push_back(E);
	    start.push_back(i);
	    stop.push_back(v);

	    if (t == 0) {
		H[i].push_back(cnt);
		H[v].push_back(cnt);
	    }
	}
    }
}


void buildX() {
    memset(useE, 0, sizeof useE);

    REP (t, 2) {
	REP (i, N) {
	    int c = 0;
	    EACH (e, H[i]) if (!useE[*e]) c++;
	    if (c == 0) continue;
	    if (t == 0 && c % 2 == 0) continue;

	    int v = i;
	    while (1) {
		while (!H[v].empty() && useE[H[v].back()]) H[v].pop_back();
		if (H[v].empty()) break;
		int e = H[v].back();
		useE[e] = true;

		if (v == stop[e]) {
		    EACH (k, paths[e]) flip[*k] = !flip[*k];
		    v = start[e];
		} else {
		    assert(v == start[e]);
		    v = stop[e];
		}
	    }

	    // eprintf("%d -- %d X\n", i+1, v+1);
	}
    }
}

void MAIN() {
    scanf("%d%d", &N, &M);

    REP (i, M) {
	scanf("%d%d%d", X+i, Y+i, W+i);
	X[i]--;
	Y[i]--;
	if (W[i] == 1) {
	    deg[X[i]]++;
	    deg[Y[i]]++;
	    G1[X[i]].push_back(i);
	    G1[Y[i]].push_back(i);
	} else {
	    G2[X[i]].push_back(i);
	    G2[Y[i]].push_back(i);
	}
    }
    build(G2);
    build(G1);
    assert(count(useE, useE+M, true) == M);
    buildX();

    int odd = 0;
    REP (i, N) if (deg[i] % 2 == 1) odd++;
    printf("%d\n", odd);
    REP (i, M) putchar('1' + flip[i]);
    putchar('\n');
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}