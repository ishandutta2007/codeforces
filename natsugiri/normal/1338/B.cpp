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
int depth[100011];

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
    que.reserve(N);
    que.push_back(0);
    memset(depth, -1, sizeof depth);
    depth[0] = 0;

    REP (i_, N) {
	int v = que[i_];
	EACH (e, G[v]) if (depth[*e] == -1) {
	    depth[*e] = depth[v] + 1;
	    que.push_back(*e);
	}
    }

    int even = 0;
    int odd = 0;
    REP (i, N) if (G[i].size() == 1u) {
	if (depth[i] % 2) odd++;
	else even++;
    }

    int ans_mi;
    if (even == 0 || odd == 0) ans_mi = 1;
    else ans_mi = 3;

    int ans_ma = N-1;
    REP (i, N) {
	int c = 0;
	EACH (e, G[i]) if (G[*e].size() == 1u) c++;
	if (c) ans_ma -= c-1;
    }

    printf("%d %d\n", ans_mi, ans_ma);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}