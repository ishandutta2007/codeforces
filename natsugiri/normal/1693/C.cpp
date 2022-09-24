#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#pragma GCC optimize("unroll-loops")
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
#include<queue>

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
VI G[200011];

LL D[200011];
LL add[200011];
bool fix[200011];

void MAIN() {
    scanf("%d%d", &N, &M);
    REP (i, M) {
	int x, y;
	scanf("%d%d", &x, &y);
	x--; y--;
	G[y].push_back(x);
	add[x]++;
    }

    memset(D, 0x3f, sizeof D);
    D[N-1] = 0;
    priority_queue<pair<LL, int> > Q;
    Q.emplace(0, N-1);

    while (!Q.empty()) {
	LL cst = -Q.top().first;
	int v = Q.top().second;
	Q.pop();

	if (D[v] != cst) continue;
	if (fix[v]) continue;

	fix[v] = true;

	EACH (e, G[v]) if (!fix[*e]) {
	    LL tmp = add[*e] + cst;
	    add[*e]--;
	    if (D[*e] > tmp) {
		D[*e] = tmp;
		Q.emplace(-D[*e], *e);
	    }
	}
    }
    printf("%lld\n", D[0]);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}