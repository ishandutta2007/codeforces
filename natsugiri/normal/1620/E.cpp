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

int Q;
VI G[500011];
int ans[500011];

void MAIN() {
    scanf("%d", &Q);

    int idx = 0;

    REP ($, Q) {
	int op;
	scanf("%d", &op);
	if (op == 1) {
	    int x;
	    scanf("%d", &x);
	    G[x].push_back(idx++);
	} else {
	    int x, y;
	    scanf("%d%d", &x, &y);
	    if (x != y) {
		if (G[y].size() < G[x].size()) swap(G[x], G[y]);
		G[y].insert(G[y].end(), G[x].begin(), G[x].end());
		G[x].clear();
	    }
	}
    }

    REP (x, 500011) EACH (e, G[x]) ans[*e] = x;
    rprintf("%d", ans, ans+idx);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}