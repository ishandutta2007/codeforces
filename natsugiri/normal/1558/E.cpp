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

int N, M;
int A[1011];
int B[1011];
int X[2011];
int Y[2011];

VI G[1011];
bool is_root[1011];
VI que;

int parent[1011];
int parent_edge[1011];
bool vis[1011];
LL S[1011];

int anti(int v, int j) {
    int x = X[j];
    int y = Y[j];
    if (is_root[x]) x = 0;
    if (is_root[y]) y = 0;

    return v ^ x ^ y;
}

bool ok(LL mid) { 
    memset(is_root, 0, sizeof is_root);
    is_root[0] = true;

    int rest = N;

    while (1) {
	memset(S, 0, sizeof S);
	S[0] = mid;

	REP (i, N) G[i].clear();
	REP (j, M) {
	    int x = X[j];
	    int y = Y[j];
	    if (is_root[x]) x = 0;
	    if (is_root[y]) y = 0;
	    if (x == 0 && y == 0) continue;
	    G[x].push_back(j);
	    G[y].push_back(j);
	}

	que.clear();
	que.push_back(0);
	memset(vis, 0, sizeof vis);
	memset(parent_edge, -1, sizeof parent_edge);
	vis[0] = true;

	int find_x = -1, find_y = -1;

	for (int i_=0; i_<(int)que.size(); i_++) {
	    int v = que[i_];
	    EACH (e, G[v]) {
		int w = anti(v, *e);
		if (vis[w] && *e == parent_edge[v]) continue;

		if (vis[w]) {
		    find_x = v;
		    find_y = w;
		    goto OUT;
		} else if (A[w] < S[v]) {
		    vis[w] = true;
		    parent[w] = v;
		    parent_edge[w] = *e;
		    S[w] = S[v] + B[w];
		    que.push_back(w);
		}
	    }
	}
OUT:

	// printf("init = %lld, (%d %d)\n", mid, find_x+1, find_y+1);
	// rprintf("%lld", S, S+N);

	if (find_x == -1) return false;

	while (!is_root[find_x]) {
	    mid += B[find_x];
	    is_root[find_x] = true;
	    rest--;
	    find_x = parent[find_x];
	}
	while (!is_root[find_y]) {
	    mid += B[find_y];
	    is_root[find_y] = true;
	    rest--;
	    find_y = parent[find_y];
	}
	if (rest == 1) return true;
    }
}

void MAIN() {
    scanf("%d%d", &N, &M);
    REP (i, N-1) scanf("%d", A+i+1);
    REP (i, N-1) scanf("%d", B+i+1);
    REP (j, M) {
	scanf("%d%d", X+j, Y+j);
	X[j]--;
	Y[j]--;
    }

    LL lo = -1, hi = 1000000001;
    while (hi - lo > 1) {
	LL mid = (hi + lo) / 2;
	(ok(mid)? hi: lo) = mid;
    }

    printf("%lld\n", hi);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}