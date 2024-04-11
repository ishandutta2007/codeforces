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
VI G[100011];
int A[100011];
int B[100011];
int ans[100011];

void MAIN() {
    scanf("%d", &N);

    REP (i, N) G[i].clear();

    REP (i, N-1) {
	int x, y;
	scanf("%d%d", &x, &y);
	x--;
	y--;

	A[i] = x;
	B[i] = y;
	G[x].push_back(i);
	G[y].push_back(i);
    }

    int deg = 0;
    REP (i, N) amax(deg, (int)G[i].size());

    if (deg <= 2) {
	int s = 0;
	REP (i, N) if (G[i].size() == 1u) {
	    s = i;
	    break;
	}
	int prv = -1;
	int val = 2;
	while (1) {
	    int nxt = -1;
	    EACH (e, G[s]) {
		int w = s ^ A[*e] ^ B[*e];
		if (w == prv) continue;

		ans[*e] = val;
		nxt = w;
		break;
	    }
	    if (nxt == -1) break;

	    val = 5 - val;
	    prv = s;
	    s = nxt;
	}
	rprintf("%d", ans, ans+N-1);
    } else {
	puts("-1");
    }
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}