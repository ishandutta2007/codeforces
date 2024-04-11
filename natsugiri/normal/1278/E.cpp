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
VI G[500011];
int iter[500011];
int par[500011];
int L[500011];
int R[500011];

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

    VI stk;
    stk.push_back(0);
    int cnt = 1;
    L[0] = cnt++;

    while (!stk.empty()) {
	int v = stk.back();
	
	if (iter[v] == 0) {
	    for (int i=G[v].size(); i--;) {
		int w = G[v][i];
		if (w != par[v]) {
		    L[w] = cnt++;
		}
	    }
	    R[v] = cnt++;
	}
	if (iter[v] == (int)G[v].size()) {
	    stk.pop_back();
	    continue;
	}
	int w = G[v][iter[v]++];
	if (w == par[v]) continue;
	par[w] = v;
	stk.push_back(w);
    }

    REP (i, N) printf("%d %d\n", L[i], R[i]);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}