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

vector<pair<int, int> > ans;

void dfs(int v, int p, int tm) {
    int deg = G[v].size();

    bool jump = false;
    ans.emplace_back(v, tm);
    if (!jump && p != -1 && tm >= deg) {
	tm -= deg;
	ans.emplace_back(v, tm);
	jump = true;
    }
    EACH (e, G[v]) if (*e != p) {
	dfs(*e, v, tm+1);
	tm = ans.back().second;
	tm++;
	ans.emplace_back(v, tm);
	if (!jump && p != -1 && tm >= deg) {
	    tm -= deg;
	    ans.emplace_back(v, tm);
	    jump = true;
	}
    }
}

void MAIN() {
    scanf("%d", &N);
    REP (i, N-1) {
	int x, y;
	scanf("%d%d", &x, &y);
	x--; y--;
	G[x].push_back(y);
	G[y].push_back(x);
    }
    dfs(0, -1, 0);

    printf("%d\n", (int)ans.size());
    EACH (e, ans) printf("%d %d\n", e->first+1, e->second);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}