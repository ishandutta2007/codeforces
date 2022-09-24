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
template<class T> void sort_unique(vector<T> &v) {
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
}

int N;
int A[100011];
VI G[100011];
bool vis[100011];
VI stk;

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);

    REP (i, N+1) G[i].clear();
    memset(vis, 0, sizeof (bool) * (N+1));
    stk.clear();

    REP (i, N-1) {
	if (A[i] < A[i+1]) {
	    G[A[i+1]].push_back(A[i]);
	}
	if (A[i] > A[i+1]) {
	    G[0].push_back(A[i]);
	}
    }
    vis[0] = true;
    stk.push_back(0);
    while (!stk.empty()) {
	int v = stk.back();
	stk.pop_back();
	EACH (e, G[v]) if (!vis[*e]) {
	    vis[*e] = true;
	    stk.push_back(*e);
	}
    }

    VI V;
    REP (i, N) if (vis[A[i]]) V.push_back(A[i]);

    sort_unique(V);
    printf("%d\n", (int)V.size());
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}