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
int A, B, DA, DB;
VI G[100011];

int par[100011];
int dist[100011];
VI que;

void bfs(int s) {
    par[s] = -1;
    dist[s] = 0;
    que.clear();
    que.push_back(s);

    REP (i_, N) {
	int v = que[i_];
	EACH (e, G[v]) if (*e != par[v]) {
	    dist[*e] = dist[v] + 1;
	    par[*e] = v;
	    que.push_back(*e);
	}
    }
}

bool alice() {
    if (DA * 2 >= DB) return true;

    bfs(A);
    if (dist[B] <= DA) return true;

    int x = max_element(dist, dist + N) - dist;
    bfs(x);
    int w = *max_element(dist, dist + N);

    return DA * 2 >= w;
}

void MAIN() {
    scanf("%d%d%d%d%d", &N, &A, &B, &DA, &DB);
    REP (i, N) G[i].clear();

    A--;
    B--;
    REP (i, N-1) {
	int x, y;
	scanf("%d%d", &x, &y);
	x--; y--;
	G[x].push_back(y);
	G[y].push_back(x);
    }

    bool a = alice();
    puts(a? "Alice": "Bob");
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}