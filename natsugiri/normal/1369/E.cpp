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

int N, M;
struct Edge {
    int to, i;
    Edge(){}
    Edge(int to_, int i_): to(to_), i(i_) {}
};

int X[200011], Y[200011];
vector<Edge> G[100011];
int W[100011];
int deg[100011];
bool use[200011];

void MAIN() {
    scanf("%d%d", &N, &M);
    REP (i, N) scanf("%d", W+i);
    REP (i, M) {
	int x, y;
	scanf("%d%d", &x, &y);
	x--; y--;
	X[i] = x;
	Y[i] = y;
	G[x].emplace_back(y, i);
	G[y].emplace_back(x, i);
	deg[x]++;
	deg[y]++;
    }

    VI que;
    REP (i, N) if (W[i] >= deg[i]) {
	que.push_back(i);
    }

    VI ans;
    for (int i=0; i<(int)que.size(); i++) {
	int v = que[i];
	EACH (e, G[v]) {
	    if (!use[e->i]) {
		use[e->i] = true;
		ans.push_back(e->i+1);
	    }
	    deg[e->to]--;
	    if (W[e->to] == deg[e->to]) {
		que.push_back(e->to);
	    }
	}
    }

    if ((int)ans.size() == M) {
	puts("ALIVE");
	rprintf("%d", ans.rbegin(), ans.rend());
    } else {
	puts("DEAD");
    }

}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}