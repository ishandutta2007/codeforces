#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
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
VI G[200011];
VI que;
int par[200011];
int height[200011];

VI H;

void MAIN() {
    scanf("%d", &N);
    REP (i, N) G[i].clear();
    REP (i, N-1) {
	int x, y;
	scanf("%d%d", &x, &y);
	x--; y--;
	G[x].push_back(y);
	G[y].push_back(x);
    }

    que.clear();
    que.push_back(0);
    REP (i, N) {
	int v = que[i];
	EACH (e, G[v]) if (*e != par[v]) {
	    par[*e] = v;
	    que.push_back(*e);
	}
    }

    int ans = 0;
    REP (i, N) {
	int v = que[N-1-i];
	H.clear();
	EACH (e, G[v]) if (*e != par[v]) {
	    H.push_back(height[*e] + 1);
	}

	if (H.empty()) {
	    height[v] = 0;
	} else if (H.size() == 1u) {
	    height[v] = H[0];
	    amax(ans, H[0]);
	} else {
	    sort(H.begin(), H.end());

	    if (v == 0) {
		amax(ans, H.back());
		amax(ans, H.rbegin()[1]+1);
	    } else {
		height[v] = H[0];
		amax(ans, H.back() + 1);
	    }
	}
    }

    printf("%d\n", ans);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}