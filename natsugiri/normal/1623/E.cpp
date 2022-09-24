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
int K;
char C[200011];
pair<int, int> G[200011];

int X[200011];


pair<char, char> dfs(int v, pair<char, char> tail) {
    if (v < 0) {
	return tail;
    } else {
	pair<char, char> r = dfs(G[v].second, tail);

	pair<char, char> m;
	if (C[v] == r.first) {
	    m = r;
	    if (r.first < r.second) {
		X[v] = 2;
	    } else {
		X[v] = 1;
	    }
	} else {
	    m.first = C[v];
	    m.second = r.first;
	    if (C[v] < r.first) {
		X[v] = 2;
	    } else if (C[v] > r.first) {
		X[v] = 1;
	    }
	}

	return dfs(G[v].first, m);
    }
}

bool dfs2(int v, bool can, int chain) {
    if (v < 0) {
	return false;
    } else {
	bool b = dfs2(G[v].first, can, chain+1);
	putchar(C[v]);
	if (b) {
	    putchar(C[v]);
	    dfs2(G[v].second, true, 0);
	    return true;
	} else if (can && X[v] == 2 && K >= chain+1) {
	    putchar(C[v]);
	    K -= chain+1;
	    dfs2(G[v].second, true, 0);
	    return true;
	} else {
	    dfs2(G[v].second, false, 0);
	    return false;
	}
    }
}

void MAIN() {
    scanf("%d%d", &N, &K);
    scanf("%s", C);
    REP (i, N) {
	int a, b;
	scanf("%d%d", &a, &b);
	G[i].first = a-1;
	G[i].second = b-1;
    }

    pair<char, char> tail(0, 0);
    dfs(0, tail);
    dfs2(0, true, 0);
    putchar('\n');

}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}